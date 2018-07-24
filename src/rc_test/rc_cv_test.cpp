//
// Created by PulsarV on 18-5-12.
//
#include <opencv2/opencv.hpp>
#include <rc_cv/rcCV.h>

int main() {
    cv::VideoCapture cap;
    cap.open(1);
    if (cap.isOpened()) {
        while (true) {
            cv::Mat frame, output;
            cap >> frame;
            int ans[2];
//            RC::CV::detectLine(frame, &output);
            RC::CV::detcetByRightAndLeft(frame,ans);
            cv::imshow("output", frame);
            if (cv::waitKey(100) == 'q')break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}

