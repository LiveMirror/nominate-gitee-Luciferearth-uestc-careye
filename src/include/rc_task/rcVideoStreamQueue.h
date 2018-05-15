//
// Created by PulsarV on 18-5-14.
//

#ifndef ROBOCAR_RCFRAMEQUEUE_H
#define ROBOCAR_RCFRAMEQUEUE_H

#include <opencv2/opencv.hpp>
#include <rc_globalVarable/rc_global_task.h>
#include <rc_log/rclog.h>
namespace RC {
    typedef std::queue<cv::Mat> rciqueue;
    class ImageTaskQueue{
    public:
        static int initTaskMannger(int argc,char** argv);
        static int pushWebImage(cv::Mat image);
        static void popWebImage(cv::Mat *outImage);
        static int pushGUIImage(cv::Mat image);
        static void popGUIImage(cv::Mat *outImage);
        static void startDefaultGUI();
        static void startGtkGUI();
        static void startQtGUI();
        static void startWebStream();
        static int getWebImageQueueSize();
        static int getGuiImageQueueSize();
    private:
        static int argc;
        static char **argv;
        static rciqueue guiImage;
        static rciqueue webImage;
        static void defaultGui();
    };
}
#endif //ROBOCAR_RCFRAMEQUEUE_H
