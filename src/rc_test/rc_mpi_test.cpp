//
// Created by PulsarV on 18-11-9.
//
#include <stdio.h>
#include <mpi.h>
#include <opencv2/opencv.hpp>

cv::Mat safe_detect(unsigned char *img, int img_width, int img_height, int img_step, int img_channel) {
//    if (img_channel != 3) {
//        return;
//    }
    cv::Mat img_rgb(img_height, img_width, CV_8UC3);
    for (int i = 0; i < img_height; i++) {
        for (int j = 0; j < img_width; j++) {
            img_rgb.at<cv::Vec3b>(i, j)[0] = img[img_step * i + j * img_channel + 0];
            img_rgb.at<cv::Vec3b>(i, j)[1] = img[img_step * i + j * img_channel + 1];
            img_rgb.at<cv::Vec3b>(i, j)[2] = img[img_step * i + j * img_channel + 2];
        }
    }
    return img_rgb;
}
    int main(int argc, char *argv[]) {
        int rank, size, len;
        cv::VideoCapture cap;
        char version[MPI_MAX_LIBRARY_VERSION_STRING];
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Get_library_version(version, &len);
        std::string name = version;
        bool is_master = name.find("pulsar") != 47;
//        if (is_node) {
//            cap.open(0);
//            while (1) {
//                cv::Mat frame;
//                cap >> frame;
//                cv::imshow("", frame);
//                int chanel, width, height;
//                width = frame.cols;
//                height = frame.rows;
//                chanel = frame.channels();
//                int buffer_size = width * height * chanel;
//                u_char *t_data = new u_char(buffer_size);
//                memcpy(t_data, frame.data, buffer_size);
//                MPI_Ssend(t_data, buffer_size, MPI_UNSIGNED_CHAR, 1, 28, MPI_COMM_WORLD);
//                cv::waitKey(10);
//            }
//        } else {
//            while(1){
//                int buffer_size = 640 * 480 * 3;
//                u_char *t_data = new u_char(buffer_size);
//                MPI_Recv(t_data, buffer_size, MPI_INT, 0, 28, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//                cv::Mat frame=safe_detect(t_data,640,480,1920,3);
//                cv::imwrite("./save/"+std::to_string(clock()),frame);
//            }
//
//        }
    std::cout<<name<<"is_master:"<<is_master<<std::endl<<std::endl;
        printf("CV caculator %d of %d, (%s, %d)\n", rank, size, version, len);
        MPI_Finalize();
        return 0;
    }

