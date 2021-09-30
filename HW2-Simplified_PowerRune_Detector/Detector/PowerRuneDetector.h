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

    /*
     * @brief 重载()运算符，能量机关扇叶识别整体流程
     * @param inputImg
     * @param target: 识别到的能量机关扇叶中心
     * @param outImg: 用于输出的识别结果
     * @param showResult: 是否展示结果窗口，默认true
     * @return bool值表示是否识别到，ture为识别到扇叶
     */
    bool operator()(const Mat &inputImg, Point2f& target, Mat& outImg, const bool showResult=true);

    /*
     * @brief 获取模板匹配的结果数值
     * @param img: input image
     * @param templ: template image
     * @param point: 匹配到的最佳中心点
     * @param method: opencv提供的模板匹配方法
     * @return 
     */
    float getTemplateMatchVal(const Mat& img, const Mat& templ, Point2f& point, const int method=TM_CCOEFF_NORMED);


    /*
     * @brief 矩形视角变换，将旋转矩形rect所在的（可能与坐标轴有夹角的）图像区域提取为平行于坐标轴的（和模板方向图片一致的）矩形图像，用于模板匹配
     * @param rect: 旋转矩形
     * @param inputImg: 输入图片
     * @param showResult: 是否展示结果窗口，默认true
     * @return 
     */
    Mat perspectiveTransform(const RotatedRect& rect, const Mat& inputImg, const bool showResult=true);

    /*
     * @brief 在displayImg上绘制旋转矩形rect
     * @param displayImg: 要展示的图片
     * @param rect要绘制的旋转矩形
     * @param color 线的颜色
     * @param thickness 线宽
     * @param lineType 线的类型
     */
    void drawRotatedRect(Mat& displayImg, const RotatedRect& rect, const Scalar& color,
                         int thickness = 1, int lineType = LINE_8);

private:
    const float matchValThresh = 0.5; //TODO: 需要调整的参数
    const int nTempl; //模板图片的数量
    const Size2i templSize = Size2i(140, 80); // TODO: 需要调整的参数
    vector<Mat> templArray; // 存放模板图片
};


#endif //POWERRUNE_DETECTOR_H
