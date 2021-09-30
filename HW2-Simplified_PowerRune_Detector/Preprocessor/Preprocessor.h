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

    Mat operator()(const Mat& inputImg);

    Mat denoise(const Mat& inputImg,
                const int binaryFilterThresh = 100,
                const int binaryFilterMaxVal = 255); //TODO(加分项): 你可以使用adaptive threshold

    Mat morphologyProcess(const Mat& inputImg);

private:
    const int morphSize = 2; //TODO: 你可以调整形态学变换结构元的大小
    Mat morphElement;
};


#endif //PREPROCESSOR_H
