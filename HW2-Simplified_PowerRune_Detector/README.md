# RoboWalker2022视觉组第2次作业

出题人：李喆昊（QQ：1003449832）



## 目标

使用OpenCV库提供的传统数字图像处理算法，实现一个简化的能量机关识别器，感受传统算法的效果与局限性。

你需要修改的C++类有``PowerRuneDetector``与``Preprocessor``。

你可能用到的OpenCV函数有：（具体使用用法可以自行查阅文档：[OpenCV 4.5.0 doc](https://docs.opencv.org/4.5.0/)）

### 预处理部分
1. ``void split(InputArray m, OutputArrayOfArrays mv)`` 用于分离以``Mat``存储的图片的颜色通道
2. ``double threshold(InputArray src, OutputArray dst, double thresh, double maxval, int type) `` 用于对图像像素进行二值化
3. ``void morphologyEx(InputArray src, OutputArray dst, int op, InputArray kernel, Point_<int> anchor = Point(-1, -1), int iterations = 1, int borderType = BORDER_CONSTANT, const Scalar_<double> &borderValue = morphologyDefaultBorderValue())``
    对图像进行形态学处理以去噪

### 能量机关扇叶识别部分
1. ``void findContours(InputArray image, OutputArrayOfArrays contours, OutputArray hierarchy, int mode, int method, Point_<int> offset = Point())``查找图片中的轮廓
2. TODO soon！


## 代码目录结构

```
.
├── CMakeLists.txt 
├── Detector （PowerRuneDetector类的代码）
│   ├── PowerRuneDetector.cpp
│   └── PowerRuneDetector.h
├── Preprocessor （Preprocessor预处理类的代码）
│   ├── Preprocessor.cpp
│   └── Preprocessor.h
├── README.md
├── Utils （日志输出 & 计时器类的代码）
│   ├── Logger.cpp
│   ├── Logger.h
│   ├── Timer.cpp
│   └── Timer.h
├── data
│   ├── input （输入数据）
│   ├── output （输出目录）
│   └── template （用于OpenCV模板匹配的模板图片）
├── imgs
│   └── ... （README.md中的图片）
├── main.cpp （主函数）
└── test
    └── ... 

```



## 输入/输出

输入数据在``data/input``目录下，有3个文件夹

将识别结果输出到``data/output``目录下，目录结构&文件名和输入数据一致。

示例输入：``data/input/3/1912.jpg``

<img src="./data/input/3/1912.jpg" alt="1912" style="zoom:50%;" />

示例输出：待击打扇叶的识别结果（期望的输出路径为``data/output/3/1912.jpg``）

<img src="./imgs/1912-output.jpg" style="zoom:50%;" />


TODO 更多细节待完善


