//
// Created by PulsarV on 18-5-9.
//

#include <rc_move/rcmove.h>


int RC::RobotCarMove::init(int camera_id, char *device, char *mapping) {
    if (mapping != NULL)
        this->mapping = mapping;
    this->camera_id = camera_id;
    this->type = RC_PLAY_BY_CAMERA;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init(char *video, char *device, char *mapping) {
    if (mapping != NULL)
        this->mapping = mapping;
    this->video = video;
    this->type = RC_PLAY_BY_VIDEO;
    this->init_serial_device(device);
    return 1;
}

int RC::RobotCarMove::init_serial_device(char *device) {
    this->serial_device = new Serial();


#ifdef __linux__
    this->serial_device->openSerial(device);
#endif // __linux__
    return 1;
}

int RC::RobotCarMove::start() {
    std::fstream mapped;
    std::ifstream map;

    cv::VideoCapture cap;
    switch (this->type) {
        case RC_PLAY_BY_CAMERA:
            if (this->camera_id != -1) {
                LOG::logInfo("Open Camera Device From Device");
                int id = this->camera_id;
                cap.open(id);
            } else
                return LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
        case RC_PLAY_BY_VIDEO:
            if (this->video != NULL) {
                LOG::logInfo("Open Camera Device From Files");
                cap.open(this->camera_id);
            } else
                return LOG::logError(RC_MOVE_DEVICE_PORT_INITATION_ERROR);
            break;
    }
    if (this->mapping != NULL) {
        map.open(this->mapping);
    } else {
        mapped.open("map.bin", std::ios::app);
    }
    if (cap.isOpened()) {
        LOG::logSuccess("Open Successed");
        while (true) {
            cv::Mat frame, output;
            cap >> frame;
            cv::Mat re_frame;
            cv::resize(frame,re_frame,cv::Size(128,128),0,0,cv::INTER_LINEAR);
            int ans[2]={0,0};
            CV::detcetByRightAndLeft(re_frame,ans);
            if (! frame.empty()) {
#ifdef __linux__
                if (this->serial_device->isOpend() && this->AutoMove) {
                    if(ans[0]>(128/2)+10){
//                        this->wheel_1_backward(20);
                        this->wheel_AC();
                    }
                    if(ans[0]<(128/2)-10){
//                        this->wheel_2_forward(20);
                        this->wheel_CW();
                    }
                    this->wheel_go_backward();
                    char buffer[64] = {'\0'};
                    this->serial_device->recive(buffer,64);
                    std::string data = buffer;
                    std::cout<<ans[0]<<","<<ans[1]<<std::endl;

                    if (!data.empty()){
                        LOG::logDebug(buffer);
                    } else{
                        cv::waitKey(1000);
                    }
                }
#endif // __linux__
                cv::imshow("", frame);
            }
            char key = cv::waitKey(20);
            if(key=='c')this->AutoMove=this->AutoMove==true? false:true;
            if (map.is_open()) {
                if (!map.eof()) {
                    char com = map.get();
                    this->command(com);
                    continue;
                }
            }
            if (key == 'x')break;
            if (mapping == NULL)
                if ((int) key > 65 && (int) key < 122)
                    mapped << &key;
#ifdef __linux__
            if (this->serial_device->isOpend()) {
                this->command(key);
            }
#endif // 
        }
    } else
        return LOG::logError(RC_OPEN_CAMERA_ERROR);
#ifdef __linux__
    this->serial_device->release();
#endif
    cv::destroyAllWindows();
    mapped.close();
    return 1;
}

void RC::RobotCarMove::command(char com) {
    switch (com) {
        case 'w':
            this->wheel_go_backward();
            this->wheel_go_backward();
            break;
        case 'a':
            this->wheel_2_forward(20);
            this->wheel_2_forward(20);
            break;
        case 's':
            this->wheel_go_forward();
            this->wheel_go_forward();
            break;
        case 'd':
            this->wheel_1_backward(20);
            this->wheel_1_backward(20);
            break;
        case 'q':
            this->wheel_CW();
            this->wheel_CW();
            break;
        case 'e':
            this->wheel_AC();
            this->wheel_AC();
            break;
    }
}
#ifdef __linux__
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
#else
void RC::RobotCarMove::wheel_1_backward(double trangle) {
}

void RC::RobotCarMove::wheel_1_forward(double trangle) {

}

void RC::RobotCarMove::wheel_2_backward(double trangle) {

}

void RC::RobotCarMove::wheel_2_forward(double trangle) {

}

void RC::RobotCarMove::wheel_3_backward(double trangle) {

}

void RC::RobotCarMove::wheel_3_forward(double trangle) {

}

void RC::RobotCarMove::wheel_AC() {
}

void RC::RobotCarMove::wheel_CW() {

}

void RC::RobotCarMove::wheel_go_forward() {

}

void RC::RobotCarMove::wheel_go_backward() {
}
#endif // __linux__