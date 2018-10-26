//
// Created by PulsarV on 18-5-15.
//
#include <rc_serial/rc_gyro_serial.h>
#include <rc_serial/rcserial.h>
#ifdef __linux__
void RC::GyroDevice::setBackSpeed(int speed) {
    switch (speed){
        case GYRO_0D1HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_0D1HZ);
            break;
        case GYRO_0D5HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_0D5HZ);
            break;
        case GYRO_1HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_1HZ);
            break;
        case GYRO_2HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_2HZ);
            break;
        case GYRO_5HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_5HZ);
            break;
        case GYRO_10HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_10HZ);
            break;
        case GYRO_20HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_20HZ);
            break;
        case GYRO_50HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_5HZ);
            break;
        case GYRO_100HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_100HZ);
            break;
        case GYRO_200HZ:
            this->send(GYRO_SERIAL_BACK_SPEED_200HZ);
            break;
        case GYRO_ONCE:
            this->send(GYRO_SERIAL_BACK_SPEED_ONCE);
            break;
        case GYRO_CLOSE:
            this->send(GYRO_SERIAL_BACK_SPEED_CLOSE);
            break;
        default:
            RC::LOG::logError(GYRO_COMMOND_ERROE);
            break;
    }
}
void RC::GyroDevice::getContent(char *buffer,int size) {
    this->send(GYRO_SERIAL_BACK_SPEED_ONCE);
    this->recive(buffer,size);
}
void RC::GyroDevice::setBackContent(char **arg) {

}
#endif // __linux__

