#include <rc_main/main.h>

void fillter_8UC1(int max, cv::Mat *gray);

int main() {
    cv::Mat frame_image;
    cv::VideoCapture cap(0);
    if (cap.isOpened()) {
        while (1) {
            cap >> frame_image;
            cv::Mat hsv_image;
            cv::Mat mask;
            cv::Mat trash_hsv;
            cv::Mat gray_hsv;
            cv::Mat trash_rgb;
            cv::Mat gray_rgb;
            cv::Mat out_mask;
            cv::Mat kernel = (cv::Mat_<float>(3, 3) << 0, -1, 0, 0, 5, 0, 0, -1, 0);
            filter2D(frame_image, frame_image, CV_8UC3, kernel);
            cv::medianBlur(frame_image, frame_image, 5);

            cv::cvtColor(frame_image, hsv_image, cv::COLOR_BGR2HSV);
            cv::cvtColor(hsv_image, gray_hsv, cv::COLOR_BGR2GRAY);
            cv::cvtColor(frame_image, gray_rgb, cv::COLOR_BGR2GRAY);

            filter2D(gray_rgb, gray_rgb, CV_8UC1, kernel);

            cv::medianBlur(hsv_image, hsv_image, 5);
            cv::Canny(frame_image, mask, 200, 255, 3);



            const cv::Scalar hsvBlack_Low(10, 10, 10);
            const cv::Scalar hsvBlack_High(100, 100, 100);

            cv::threshold(gray_hsv, trash_hsv, 1, 255, cv::THRESH_BINARY);
            cv::threshold(gray_rgb, trash_rgb, 40, 250, cv::THRESH_BINARY);

            cv::inRange(hsv_image, hsvBlack_Low, hsvBlack_High, trash_hsv);
            cv::bitwise_and(frame_image, hsv_image, out_mask, trash_hsv);

            cv::cvtColor(hsv_image, frame_image, cv::COLOR_HSV2BGR);
            cv::Mat dst_cpu;
            cv::cvtColor(mask, dst_cpu, cv::COLOR_GRAY2BGR);

            std::vector<cv::Vec4i> lines_cpu;{
                cv::HoughLinesP(mask, lines_cpu, 1, CV_PI / 180, 100, 100, 5);
            }

            for (size_t i = 0; i < lines_cpu.size(); ++i) {
                cv::Vec4i l = lines_cpu[i];
                cv::line(frame_image,
                         cv::Point(l[0], l[1]),
                         cv::Point(l[2], l[3]),
                         cv::Scalar(0, 255, 255),
                         3,
                         cv::LINE_AA);
            }

            cv::imshow("cap", frame_image);
            cv::imshow("gray_rgb", gray_rgb);
            cv::imshow("trash_hsv", trash_hsv);
            cv::imshow("trash_rgb", trash_rgb);
            cv::imshow("cpu", dst_cpu);
            cv::imshow("mask", mask);
            cv::imshow("out", out_mask);
            cv::imshow("hsv", hsv_image);
            if (cv::waitKey(10) == 'q')break;
        }
    }
    cv::destroyAllWindows();
    return 0;
}

void fillter_8UC1(int max, cv::Mat *gray) {
    cv::MatIterator_<uchar> it, end;
    for (it = gray->begin<uchar>(), end = gray->end<uchar>(); it != end; ++it) {
        if (*it < 10)
            *it = 0;
        else
            *it = 255;
    }
}
