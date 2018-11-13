//
// Created by PulsarV on 18-5-12.
//
#include <opencv2/opencv.hpp>
#include <rc_main/main.h>

int main(int argc,char **argv) {
    int CAMERA_DEVICE=0;
    for (int i = 0; i < argc; i += 1) {
        std::string commond = argv[i];
        if (commond == RC_PARAM_INDEX)
            if (argv[RC_START_PARAM])
                CAMERA_DEVICE = atoi(argv[RC_START_PARAM]);
    }
    cv::VideoCapture cap;
    cap.open(CAMERA_DEVICE);
    if (cap.isOpened()) {
        while (true) {
            cv::Mat frame, output;
            cap >> frame;
            if(!frame.empty()){
                cv::imshow("output", frame);
                std::cout<<" step:"<<frame.step
                         <<" chanel:"<<frame.channels()
                         <<" cols:"<<frame.cols
                         <<" rows:"<<frame.rows<<std::endl;
            }
            if (cv::waitKey(1) == 'q')break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}

