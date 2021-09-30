//
// Created by 李喆昊 on 2021/9/23.
//

#ifndef POWERRUNE_DETECTOR_H
#define POWERRUNE_DETECTOR_H

#include<opencv2/imgproc.hpp>
#include "../Utils/Logger.h"
#include <memory>

using namespace cv;
using namespace std;

class PowerRuneDetector{
public:
    PowerRuneDetector(const string& templPath, const int nTempl=6);

    bool operator()(const Mat &inputImg, Point2f& target, Mat& outImg, const bool showResult=true);

    /*
     * @brief Get template match value
     * @param img: input image
     * @param templ: template image
     * @return
     */
    float getTemplateMatchVal(const Mat& img, const Mat& templ, Point2f& point, const int method=TM_CCOEFF_NORMED);

    Mat perspectiveTransform(const RotatedRect& rect, const Mat& inputImg, const bool showResult=true);

    void drawRotatedRect(Mat& displayImg, const RotatedRect& rect, const Scalar& color,
                         int thickness = 1, int lineType = LINE_8);

private:
    const float matchValThresh = 0.5; //TODO: 需要调整的参数
    const int nTempl;
    const Size2i templSize = Size2i(140, 80); // TODO: 需要调整的参数
    vector<Mat> templArray;
};


#endif //POWERRUNE_DETECTOR_H
