//
// Created by PulsarV on 18-5-9.
//

#ifndef ROBOCAR_RCCV_CPP_H
#define ROBOCAR_RCCV_CPP_H

#include <opencv2/opencv.hpp>
namespace RC {
    typedef struct rc_line{
        int theta;
        int r;
    }rc_line;
    typedef std::vector<cv::Vec4i> lines;
    namespace CV{
        double RADIAN=CV_PI/180.0;
        void fillter_8UC1(int max, cv::Mat *gray);
        std::vector<cv::Rect> detcetBody(cv::Mat src);
        std::vector<cv::Rect> detcetFace(cv::Mat src);
        void detectLine(cv::Mat src,cv::Mat *dst);
        std::vector<RC::rc_line> detectLine(cv::Mat &img, int threshold);
        void drawDetectLines(cv::Mat& image,const std::vector<cv::Vec4i>& lines,cv::Scalar & color);
        void detcetByRightAndLeft(cv::Mat &src,int *ans);
    }
}
#endif //ROBOCAR_RCCV_CPP_H
