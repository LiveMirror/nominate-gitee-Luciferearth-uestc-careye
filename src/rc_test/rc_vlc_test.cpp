//
// Created by PulsarV on 18-5-14.
//
#include <opencv2/opencv.hpp>
#include <rc_cv/rcCV.h>
#include <vlc/vlc.h>
#include <zconf.h>
int main(){
    libvlc_instance_t *vlc;
    const char *url;
    const char *sout = "#transcode{vcodec=h264,vb=0,scale=0,acodec=mpga,ab=128,channels=2,samplerate=44100}:http{mux=ffmpeg{mux=flv},dst=:5555/test}";

    const char *media_name = "Lei's test";

    url = "/home/norse/WorkSpace/uestc-careye/test_data/All_Night.mp4";
//    url = "screen://";


    vlc = libvlc_new(0, NULL);
//    libvlc_media_new_location(vlc,url);
    libvlc_vlm_add_broadcast(vlc, media_name, url, sout, 0, NULL, true, false);
    libvlc_vlm_play_media(vlc, media_name);

    sleep(30000);

    libvlc_vlm_stop_media(vlc, media_name);
    libvlc_vlm_release(vlc);
//    cv::VideoCapture cap;
//    cap.open(0);
//    if (cap.isOpened()) {
//        while (true) {
//            cv::Mat frame, output;
//            cap >> frame;
//            RC::CV::detectLine(frame, &output);
//            cv::imshow("output", output);
//            if (cv::waitKey(100) == 'q')break;
//        }
//    }
//    cv::destroyAllWindows();
    return 0;
}

