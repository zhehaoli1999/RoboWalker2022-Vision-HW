//
// Created by 李喆昊 on 2021/9/23.
//

#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include<opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

class Preprocessor {
public:
    Preprocessor();

    /*
     * @brief image process 
     * @param img: input image
     * @return processed image as Mat 
     */
    Mat operator()(const Mat& inputImg);

    /*
     * @brief 图像去噪
     * @param inputImg: 需要去噪的图片
     * @param binaryFilterThresh: 二值化阈值
     * @param binaryFilterMaxVal: 二值化最大值
     * @return 去噪后的图片 as Mat
     */
    Mat denoise(const Mat& inputImg,
                const int binaryFilterThresh = 100,
                const int binaryFilterMaxVal = 255); //TODO(加分项): 你可以使用adaptive threshold

    /*
     * @brief 形态学处理
     * @param inputImage
     * @return 处理后的图片 as Mat
     */
    Mat morphologyProcess(const Mat& inputImg);

private:
    const int morphSize = 2; //TODO: 你可以调整形态学变换结构元的大小
    Mat morphElement;
};


#endif //PREPROCESSOR_H
