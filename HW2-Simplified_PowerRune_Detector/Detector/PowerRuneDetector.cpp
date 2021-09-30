//
// Created by 李喆昊 on 2021/9/23.
//

#include "PowerRuneDetector.h"
#include <opencv2/highgui.hpp>

PowerRuneDetector::PowerRuneDetector(const string& templPath, const int nTempl)
: nTempl(nTempl), templArray(nTempl)
{
    // read template image
    for(int i = 0; i < nTempl; i++)
    {
        this->templArray[i] = imread(templPath + "template" + to_string(i) + ".jpg", IMREAD_GRAYSCALE);
        if (this->templArray[i].empty())
        {
            Logger::error() << "Read template image error!" << endl;
            exit(1);
        }
        resize(this->templArray[i], this->templArray[i], this->templSize); //FIXME
    }
};

bool PowerRuneDetector::operator()(const Mat &inputImg, Point2f& target, Mat& outImg, const bool showResult) {
    // contours detection
    // TODO: 实现图片中物体轮廓的检测

    Mat displayImg(inputImg.rows, inputImg.cols, CV_8UC3);
    cvtColor(inputImg, outImg, COLOR_GRAY2BGR, 3); // outImg is CV_8UC3 type

    bool isDetected = false;
    // selected possible area containing leaf
    /* TODO：你需要实现从轮廓中使用模板匹配的方式检测扇叶的整体流程，需要选择最佳匹配结果
     *  并将识别到的中心位置放入target返回、识别结果绘制在outImg
     *  一种可能的流程（有优化空间）：
     *  1. 遍历所有轮廓
     *  2. 在遍历过程中抽取出轮廓对应的区域（ROI：感兴趣区域）进行模板匹配（由于有多个模板，模板匹配可能也需要遍历，但可以并行加速（加分项））
     *  3. 从所有可能区域中通过比较模板匹配的数值（因为我们的测试数据中每次只有一个待击打装甲板），选出最佳区域，
     *  4. 如果识别到，设置isDetected变量，将识别到的中心位置放入target返回、识别结果绘制在outImg
     *  5. 如果识别不到，继续下一个轮廓。
     */

    if(showResult) {
        namedWindow("contours", WINDOW_AUTOSIZE);
        imshow("contours", displayImg);
        namedWindow("detect result", WINDOW_AUTOSIZE);
        imshow("detect result", outImg);
    }

    return isDetected;
}

float PowerRuneDetector::getTemplateMatchVal(const Mat& roi, const Mat& templ, Point2f& matchCenter, const int method) {
    // pre-filter
    // TODO: 你可以修改这里的筛选标准 & 参数以优化识别结果
    int w = max(roi.cols, roi.rows);
    int h = min(roi.cols, roi.rows);
    if(w <= h * 1.5)
        return -1;

    int resultCols =  roi.cols - templ.cols + 1;
    int resultRows = roi.rows - templ.rows + 1;
    if(resultCols <= 0 or resultRows <= 0)
        return -1;

//    assert(resultCols > 0 && resultRows > 0);
    Mat result( resultRows, resultCols, CV_32FC1 );

    // use OpenCV matchTemplate method
    matchTemplate( roi, templ, result, method);
    // normalize matching result for later search
//    normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

    double minVal, maxVal;
    Point minLoc, maxLoc, matchLoc;
    // find global minimum & maximum
    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

    float matchVal = 0;  // value to be returned
    if( method  == TM_SQDIFF || method == TM_SQDIFF_NORMED )
    {
        matchLoc = minLoc;
        matchVal = minVal;
    }
    else
    { matchLoc = maxLoc;
    matchVal = maxVal;}

    matchCenter = matchLoc;
    return matchVal;
}

Mat PowerRuneDetector::perspectiveTransform(const RotatedRect& rect, const Mat& inputImg, const bool showResult)
{
    int h = rect.size.height;
    int w = rect.size.width;
//    Logger::debug() << "h = " << h << " w = " << w << endl;

    Point2f srcRect[4];
    rect.points(srcRect);

    Point2f dstRect[4];
    dstRect[0] = Point2f(0, 0);
    dstRect[1] = Point2f(h, 0);
    dstRect[2] = Point2f(h, w);
    dstRect[3] = Point2f(0, w);

    Mat M = getPerspectiveTransform(srcRect, dstRect);
    Mat warpedImg;
    warpPerspective(inputImg, warpedImg, M, {h, w});
    if(warpedImg.rows > warpedImg.cols)
        cv::rotate(warpedImg, warpedImg, cv::ROTATE_90_CLOCKWISE);

//    Logger::warning() << warpedImg.rows << " " <<warpedImg.cols << endl;

    if(showResult)
    {
        auto r = rand();
        namedWindow("input"+to_string(r), WINDOW_AUTOSIZE);
        imshow("input"+to_string(r), inputImg);
        namedWindow("warped"+to_string(r), WINDOW_AUTOSIZE);
        imshow("warped"+to_string(r), warpedImg);
    }

    return warpedImg;
}

void PowerRuneDetector::drawRotatedRect(Mat &displayImg, const RotatedRect &rect, const Scalar& color,
                                        int thickness, int lineType) {
    Point2f rectPoints[4];
    rect.points(rectPoints);
    line(displayImg, rectPoints[0], rectPoints[1],color, thickness, lineType);
    line(displayImg, rectPoints[1], rectPoints[2],color, thickness, lineType);
    line(displayImg, rectPoints[2], rectPoints[3],color, thickness, lineType);
    line(displayImg, rectPoints[3], rectPoints[0],color, thickness, lineType);
}
