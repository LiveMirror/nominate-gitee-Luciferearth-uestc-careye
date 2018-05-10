//
// Created by PulsarV on 18-5-9.
//

#include <rc_move/rcmove.h>
#include <rc_log/rclog.h>
#include <rc_globalVarable/rc_global_wheel.h>

int RC::RobotCarMove::init(int camera_id, char *device) {
    this->camera_id = camera_id;
    this->device = new Serial();
    this->device->open(device);
}

int RC::RobotCarMove::start() {
    if (camera_id == -1) {
        RC::LOG::logError((char *) "You should be initation the camera index before start");
        return 0;
    }
    cv::Mat frame_image;
    cv::VideoCapture cap(this->camera_id);
    if (cap.isOpened()) {
        while (true) {
            cap >> frame_image;
            cv::Mat output;
            RC::CV::detectLine(frame_image, &output);
            if (!output.empty())
                cv::imshow("sss", output);
            if (cv::waitKey(10) == 'q')break;
        }
    }
    cv::destroyAllWindows();
    return 1;
}

void RC::WHEEL::wheel_1_backward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_1_BACKWARD);
}

void RC::WHEEL::wheel_1_forward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_1_FORWARD);

}

void RC::WHEEL::wheel_2_backward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_2_BACKWARD);

}

void RC::WHEEL::wheel_2_forward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_2_FORWARD);

}

void RC::WHEEL::wheel_3_backward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_3_BACKWARD);

}

void RC::WHEEL::wheel_3_forward(RC::Serial *serial, double trangle) {
    serial->send((char *) RC_WHEEL_3_FORWARD);

}

void RC::WHEEL::wheel_AC(RC::Serial *serial) {
    serial->send((char *) RC_WHEEL_AC);

}

void RC::WHEEL::wheel_CW(RC::Serial *serial) {
    serial->send((char *) RC_WHEEL_CW);

}

void RC::WHEEL::wheel_go_backward(RC::Serial *serial) {
    serial->send((char *) RC_WHEEL_GO_BACKWARD);

}

void RC::WHEEL::wheel_go_forward(RC::Serial *serial) {
    serial->send((char *) RC_WHEEL_GO_FORWARD);

}
