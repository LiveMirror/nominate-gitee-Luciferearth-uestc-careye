//
// Created by PulsarV on 18-5-14.
//
#include <opencv2/opencv.hpp>
#include <rc_cv/rcCV.h>
int main(){
    cv::VideoCapture cap;
    cap.open(0);
    if (cap.isOpened()) {
        while (true) {
            cv::Mat frame, output;
            cap >> frame;
            RC::CV::detectLine(frame, &output);
            cv::imshow("output", output);
            if (cv::waitKey(100) == 'q')break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}

