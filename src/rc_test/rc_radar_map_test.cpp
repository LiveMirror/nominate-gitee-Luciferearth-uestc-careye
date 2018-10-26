//
// Created by PulsarV on 18-10-26.
//

#include <rplidar.h>
#include <GL/glut.h>
#include <projects.h>
#include <rplidar_driver.h>
#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <cstdlib>
#include <iostream>

#define _countof(_Array) (int)(sizeof(_Array) / sizeof(_Array[0]))

#define GL_WIDTH 480
#define MAX_RADAR_DIST 1500
#define RADAR_STEP 0.01
using namespace rp::standalone::rplidar;

float p1_x = 0, p1_y = 0;
float p2_x = 0, p2_y = 0;
float p1step = 1.75f;
//float p1step = 0.0f;
float p2step = 2.25f;
RPlidarDriver *drv;

class DOT {
public:
    double theta, dist;

    DOT(double theta, double dist) {
        this->dist = dist;
        this->theta = theta;
    }
};

std::vector<DOT> dots;


void draw_line(float x1, float y1, float x2, float y2) {
    GLfloat line_size = 3;
    glLineWidth(line_size);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void draw_point(float x, float y, float R, float G, float B, float alpha) {
    GLfloat point_size = 5;
    glPointSize(point_size);
    glColor4f(R, G, B, alpha);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

bool ctrl_c_pressed;

void ctrlc(int) {
    ctrl_c_pressed = true;
}

void draw_rader() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glColor4f(0, 1, 0, 0);
    int n = 1000;
    for (float scale = 1; scale > 0.1; scale -= 0.1) {
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < n; i++) {
            glVertex2f(scale * cos(2 * PI * i / n), scale * sin(2 * PI * i / n));   //定义顶点
        }
        glEnd();
    }
    glColor4f(1, 0, 0, 0);
    draw_line(0, 0, 0, 1);
    draw_line(0, 0, 1, 1);
    draw_line(0, 0, -1, 1);
    draw_line(0, 0, 1, -1);
    draw_line(0, 0, -1, -1);
    draw_line(0, 0, 0, -1);
    draw_line(0, 0, 1, 0);
    draw_line(0, 0, -1, 0);
    draw_point(p1_x, p1_y, 1, 1, 1, 0);
    draw_point(p2_x, p2_y, 1, 1, 1, 0);
    draw_line(0, 0, p1_x, p1_y);
    draw_line(0, 0, p2_x, p2_y);
    std::vector<DOT>::iterator it;
    for (it = dots.begin(); it != dots.end(); ++it) {
        float x = 0, y = 0;
        x = cos(it->theta / 180 * PI) * (it->dist / MAX_RADAR_DIST);
        y = sin(it->theta / 180 * PI) * (it->dist / MAX_RADAR_DIST);
        draw_point(x, y, 0, 0, 1, 0);
    }

    glFlush();
    glutSwapBuffers();
}

float get_angle(float x, float y) {
    float trangel = atan(x / y) * 180 / PI;
    if (y < 0 && x > 0 || y < 0 && x < 0)
        trangel = trangel + 180;
    if (x < 0 && y > 0)
        trangel = trangel + 360;
    trangel = trangel == 360 ? 0 : trangel;
}

void TimerFunction(int value) {
    p1_x = sin(PI * p1step);
    p1_y = cos(PI * p1step);
    p2_x = sin(PI * p2step);
    p2_y = cos(PI * p2step);
    if (p1step == 2.5 + 1.75)
        p1step = 1.75;
    if (p2step == 2.5 + 2.25)
        p2step = 2.25;
    p1step += RADAR_STEP;
    p2step += RADAR_STEP;
    rplidar_response_measurement_node_t nodes[360 * 22];
    size_t count = _countof(nodes);
    u_result op_result;
    op_result = drv->grabScanData(nodes, count);
    if (IS_OK(op_result)) {
        drv->ascendScanData(nodes, count);
        dots.clear();
        for (int pos = 0; pos < (int) count; ++pos) {
            DOT dot(((nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT) / 64.0f),
                    (nodes[pos].distance_q2 / 4.0f));
//            DOT dot(120.4,200);
            dots.push_back(dot);
//            printf("%s theta: %f Dist: %08.2f Q: %d \n",
//                   (nodes[pos].sync_quality & RPLIDAR_RESP_MEASUREMENT_SYNCBIT) ? "S " : "  ",
//                   (nodes[pos].angle_q6_checkbit >> RPLIDAR_RESP_MEASUREMENT_ANGLE_SHIFT) / 64.0f,
//                   nodes[pos].distance_q2 / 4.0f,
//                   nodes[pos].sync_quality >> RPLIDAR_RESP_MEASUREMENT_QUALITY_SHIFT);
        }
    }

    if (!ctrl_c_pressed) {
//        exit(0);
    }
    glutPostRedisplay(); //标志重新绘制
    glutTimerFunc(1, TimerFunction, 1);
//    std::cout<<"当前角度1: "<<get_angle(p1_x,p1_y)<<" 当前角度2: "<<get_angle(p2_x,p2_y)<<std::endl;
}

bool checkRPLIDARHealth(RPlidarDriver *drv) {
    u_result op_result;
    rplidar_response_device_health_t healthinfo;


    op_result = drv->getHealth(healthinfo);
    if (IS_OK(op_result)) { // the macro IS_OK is the preperred way to judge whether the operation is succeed.
        printf("RPLidar health status : %d\n", healthinfo.status);
        if (healthinfo.status == RPLIDAR_STATUS_ERROR) {
            fprintf(stderr, "Error, rplidar internal error detected. Please reboot the device to retry.\n");
            return false;
        } else {
            return true;
        }

    } else {
        fprintf(stderr, "Error, cannot retrieve the lidar health code: %x\n", op_result);
        return false;
    }
}

void KeyBoards(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            drv->stop();
            drv->stopMotor();
            RPlidarDriver::DisposeDriver(drv);
            drv = NULL;
            exit(0);
            break;
    }
}

int main(int argc, char **argv) {
    const char *opt_com_path = NULL;
    _u32 baudrateArray[2] = {115200, 256000};
    _u32 opt_com_baudrate = 0;
    u_result op_result;
    bool useArgcBaudrate = false;

    opt_com_path = "/dev/ttyUSB0";
    bool connectSuccess = false;
    rplidar_response_device_info_t devinfo;

    drv = RPlidarDriver::CreateDriver(DRIVER_TYPE_SERIALPORT);
    // make connection...
    if (useArgcBaudrate) {
        if (!drv)
            drv = RPlidarDriver::CreateDriver(DRIVER_TYPE_SERIALPORT);
        if (IS_OK(drv->connect(opt_com_path, opt_com_baudrate))) {
            op_result = drv->getDeviceInfo(devinfo);

            if (IS_OK(op_result)) {
                connectSuccess = true;
            } else {
                delete drv;
                drv = NULL;
            }
        }
    } else {
        size_t baudRateArraySize = (sizeof(baudrateArray)) / (sizeof(baudrateArray[0]));
        for (size_t i = 0; i < baudRateArraySize; ++i) {
            if (!drv)
                drv = RPlidarDriver::CreateDriver(DRIVER_TYPE_SERIALPORT);
            if (IS_OK(drv->connect(opt_com_path, baudrateArray[i]))) {
                op_result = drv->getDeviceInfo(devinfo);

                if (IS_OK(op_result)) {
                    connectSuccess = true;
                    break;
                } else {
                    delete drv;
                    drv = NULL;
                }
            }
        }
    }
    if (!connectSuccess) {
        fprintf(stderr, "Error, cannot bind to the specified serial port %s.\n", opt_com_path);
        exit(0);
    }
    printf("RPLIDAR S/N: ");
    for (int pos = 0; pos < 16; ++pos) {
        printf("%02X", devinfo.serialnum[pos]);
    }

    printf("\n"
                   "Firmware Ver: %d.%02d\n"
                   "Hardware Rev: %d\n", devinfo.firmware_version >> 8, devinfo.firmware_version & 0xFF,
           (int) devinfo.hardware_version);



    // check health...
    if (!checkRPLIDARHealth(drv)) {
        exit(0);
    }

    signal(SIGINT, ctrlc);

    drv->startMotor();
    // start scan...
    drv->startScan(0, 1);
    drv->startMotor();
//    drv->stop();
//    drv->stopMotor();
//    getchar();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowPosition(100, 100);
    glutInitWindowSize(GL_WIDTH, GL_WIDTH);
    glMatrixMode(GL_PROJECTION);//设定投影方式
    glutCreateWindow("radar map");
    glutKeyboardFunc(&KeyBoards);
    glutDisplayFunc(draw_rader);
    glutTimerFunc(1, TimerFunction, 1);
    glutMainLoop();

    return 0;
}