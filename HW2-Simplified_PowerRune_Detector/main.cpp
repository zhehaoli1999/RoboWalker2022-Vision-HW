#include <iostream>
#include <opencv2/imgcodecs.hpp> // This header is for image file reading and writing
#include <opencv2/highgui.hpp> // This header is for high-level graphical user interface(GUI)
#include <string>
#include <vector>
#include <filesystem>
#include "./Utils/Logger.h"
#include "./Preprocessor/Preprocessor.h"
#include "./Detector/PowerRuneDetector.h"

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
using namespace std;
using namespace cv;
int main() {
    const bool isShowResult = false; // Whether to show result, you can add an arg parser to use in commandline
    string srcPath = "./data/input"; // Input path
    string imgPath;

    // Traverse all image files in input dir
    for (const auto& dirEntry : recursive_directory_iterator(srcPath)) {
        imgPath = string(dirEntry.path());
        if (imgPath.find(".jpg") == std::string::npos) // Check this file is a .jpg image
            continue;

        Logger::debug() << "Input: " << imgPath << endl; // Print input path into log

        // 1. Read image
        auto img = imread(imgPath);
        if (img.empty()) {
            Logger::error() << "Cannot read image!" << endl;
            exit(1);
        }

        // 2. Preprocess image like denoising
        auto preprocess = Preprocessor();
        auto midImg = preprocess(img);

        // 3. Detect the power rune leaf that to be shot
        auto PRDetect = PowerRuneDetector("./data/template/");
        Point2f target; Mat detectResult;
        if(PRDetect(midImg, target, detectResult, isShowResult))
        {
            auto outputPath =  imgPath.replace(imgPath.find("input"), 5, "output");
            Logger::debug() << "Output: " << outputPath << endl; // Print output path into log

            // Write detect result image to output path
            if(! imwrite(outputPath, detectResult))
            {
                Logger::error() << "imwrite error!"<<endl;
                exit(1);
            }
        }

        // display images in separate windows
        if (isShowResult) {
            namedWindow("original", WINDOW_AUTOSIZE);
            imshow("original", img);
            namedWindow("preprocessed", WINDOW_AUTOSIZE);
            imshow("preprocessed", midImg);

            waitKey(); // Remember to add this line to see results!
        }
    }

    return 0;
}
