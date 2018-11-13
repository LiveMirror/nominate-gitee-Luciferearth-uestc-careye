//
// Created by PulsarV on 18-11-11.
//
#ifdef XX
#include <stdio.h>
#include <mpi.h>
#include <opencv2/opencv.hpp>
#include <zconf.h>

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
        if (is_master) {
            cap.open(0);
            std::cout<<"Open Camera In Rank:"<<rank<<std::endl<<std::endl;
            while (1) {
                cv::Mat frame;
                cap >> frame;
//                cv::imshow("sssss", frame);
                int chanel, width, height;
                width = frame.cols;
                height = frame.rows;
                chanel = frame.channels();
                int buffer_size = width * height * chanel;
                u_char *t_data = new u_char(buffer_size);
//                t_data=frame.data;
                memcpy(t_data, frame.data, buffer_size);
                MPI_Ssend(t_data, buffer_size, MPI_UNSIGNED_CHAR, 1, 28, MPI_COMM_WORLD);
                cv::waitKey(10);
            }
        } else {
            while(1){
                std::cout<<"Recv Data:"<<rank<<std::endl<<std::endl;
                int buffer_size = 640 * 480 * 3;
                u_char *t_data = new u_char(buffer_size);
                MPI_Recv(t_data, buffer_size, MPI_INT, 0, 28, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                std::cout<<"Data Recv:"<<rank<<std::endl<<std::endl;
//                cv::Mat frame=safe_detect(t_data,640,480,1920,3);
                std::cout<<"Save Image"<<std::endl<<std::endl;
//                cv::imwrite("/home/norse/WorkSpace/uestc-careye/cmake-build-debug/bin/save"+std::to_string(clock()),frame);
                sleep(10);
            }
        }
    std::cout<<name<<"is_node:"<<is_master<<std::endl;
    printf("CV caculator %d of %d, (%s, %d)\n", rank, size, version, len);
    MPI_Finalize();
    return 0;
}
#endif

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main() {
    float e = 0.001, z, m, a[3][3] =
            {5, 2, 1,
             -1, 4, 2,
             2, -3, 10
            },
            b[3] = {-12, 20, 3}, x[3] = {0, 0, 0}, y[3];
    int n = 3, j, i, k = 1;
    while (1) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++)
                m = m + a[i][j] * x[j];
            m = m - x[i] * a[i][i];
            y[i] = (b[i] - m) / a[i][i];
            m = 0;
        }
        i = 0;
        while (i < 3) {
            z = fabs(x[i] - y[i]);
            if (z > e)
                break;
            i++;
        }
        if (i != 3) {
            for (i = 0; i < 3; i++)
                x[i] = y[i];
            k++;
        } else if (i == 3)
            break;
    }
    printf("%f\n%f\n%f\n", y[0], y[1], y[2]);
    return 0;
}

