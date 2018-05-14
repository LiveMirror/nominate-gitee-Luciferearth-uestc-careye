//
// Created by PulsarV on 18-5-9.
//

#include <rc_move/rcmove.h>


int RC::RobotCarMove::init(int camera_id, char *device) {
    this->camera_id = camera_id;
    this->serial_device = new Serial();
    this->serial_device->openSerial(device);
}

int RC::RobotCarMove::start() {
    if (camera_id == -1) {
        RC::LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
        return 0;
    }
    cv::VideoCapture cap(this->camera_id);
    if (cap.isOpened()) {
        while (true) {
            cv::Mat frame;
            cv::Mat output;
            cap >> frame;
            RC::CV::detectLine(frame, &output);
            if (!frame.empty()) {
                if (this->serial_device->isOpend()) {
                    this->wheel_go_forward();
                    char buffer[64] = {'\0'};
                    this->serial_device->recive(buffer);
                    std::string data=buffer;
                    if(!data.empty())
                        RC::LOG::logDebug(buffer);
                }
                cv::imshow("frame", output);
            }
            if (cv::waitKey(100) == 'q')break;
        }
    }
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
    this->serial_device->send( RC_WHEEL_3_FORWARD);

}

void RC::RobotCarMove::wheel_AC() {
    this->serial_device->send(RC_WHEEL_AC);
}

void RC::RobotCarMove::wheel_CW() {
    this->serial_device->send( RC_WHEEL_CW);

}

void RC::RobotCarMove::wheel_go_forward() {
    this->serial_device->send((char *) RC_WHEEL_GO_BACKWARD);

}

void RC::RobotCarMove::wheel_go_backward() {
    this->serial_device->send((char *) RC_WHEEL_GO_FORWARD);

}
