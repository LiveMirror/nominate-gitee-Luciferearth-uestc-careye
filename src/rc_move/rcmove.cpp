//
// Created by PulsarV on 18-5-9.
//

#include <rc_move/rcmove.h>


int RC::RobotCarMove::init(int camera_id, char *device) {
    this->camera_id = camera_id;
    this->type = RC_PLAY_BY_CAMERA;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init(char *video, char *device) {
    this->video = video;
    this->type = RC_PLAY_BY_VIDEO;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init_serial_device(char *device) {
    this->serial_device = new Serial();
    this->serial_device->openSerial(device);
    return 1;
}

int RC::RobotCarMove::start() {
    cv::VideoCapture cap;
    switch (this->type) {
        case RC_PLAY_BY_CAMERA:
            if (this->camera_id != -1)
                cap.open(this->camera_id);
            else
                return RC::LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
        case RC_PLAY_BY_VIDEO:
            if (this->video != NULL)
                cap.open(this->camera_id);
            else
                return RC::LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
    }
    if (cap.isOpened()) {
        while (true) {
            cv::Mat frame,output;
            cap >> frame;
//            RC::CV::detectLine(frame, &output);
            int ans[2];
            RC::CV::detcetByRightAndLeft(frame,ans);
            if (not frame.empty()) {
                if (this->serial_device->isOpend()) {
                    if(ans[0]>ans[1])
                        this->wheel_1_backward(1);
                    if(ans[0]<ans[1])
                        this->wheel_2_forward(1);
                    this->wheel_go_forward();
                    char buffer[64] = {'\0'};
                    this->serial_device->recive(buffer);
                    std::string data = buffer;
                    if (!data.empty())
                        RC::LOG::logDebug(buffer);
                }
            }
            if (cv::waitKey(100) == 'q')break;
        }
    } else
        return RC::LOG::logError(RC_OPEN_CAMERA_ERROR);
    this->serial_device->release();
    cv::destroyAllWindows();
    return 1;
}

void RC::RobotCarMove::wheel_1_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_1_BACKWARD);
}

void RC::RobotCarMove::wheel_1_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_1_FORWARD);

}

void RC::RobotCarMove::wheel_2_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_2_BACKWARD);

}

void RC::RobotCarMove::wheel_2_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_2_FORWARD);

}

void RC::RobotCarMove::wheel_3_backward(double trangle) {
    this->serial_device->send(RC_WHEEL_3_BACKWARD);

}

void RC::RobotCarMove::wheel_3_forward(double trangle) {
    this->serial_device->send(RC_WHEEL_3_FORWARD);

}

void RC::RobotCarMove::wheel_AC() {
    this->serial_device->send(RC_WHEEL_AC);
}

void RC::RobotCarMove::wheel_CW() {
    this->serial_device->send(RC_WHEEL_CW);

}

void RC::RobotCarMove::wheel_go_forward() {
    this->serial_device->send((char *) RC_WHEEL_GO_BACKWARD);

}

void RC::RobotCarMove::wheel_go_backward() {
    this->serial_device->send((char *) RC_WHEEL_GO_FORWARD);

}
