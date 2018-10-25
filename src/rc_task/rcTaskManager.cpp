//
// Created by PulsarV on 18-5-14.
//
#include <rc_task/rcTaskManager.h>
#include <rc_log/rclog.h>
#include <zconf.h>
#include <rc_main/main.h>

void RC::start_rtmp_server(ServerInfo server_info) {

}
void RC::d_start_robot(DeviceInfo device_info) {
    RC::LOG::logInfo((char*)"Waiting for loading....");

#ifdef __linux__
    sleep(1);
#else
	Sleep(1);
#endif // __linux__
    RobotCarMove robot;
    robot.init(device_info.camera_index, device_info.serial_port,device_info.mapping);
    robot.start();
}
void RC::f_start_robot(FDeviceInfo device_info) {
    RC::LOG::logInfo((char*)"Waiting for loading....");
#ifdef __linux__
	sleep(1);
#else
    Sleep(1);
#endif // __linux__
    RobotCarMove robot;
    robot.init(device_info.camera_file_path, device_info.serial_port,device_info.mapping);
    robot.start();
}
RC::TaskManager::TaskManager(char *server_name) {
    this->server_name=server_name;
}
void RC::TaskManager::init( int camera_index,char *serial_port,char *mapping,char *server_address, int port) {
    DeviceInfo d_info;
    d_info.serial_port=serial_port;
    d_info.camera_index=camera_index;
    d_info.mapping=mapping;
    RC::LOG::logInfo((char*)"Start Robot");
    rc_Thread t_robot(boost::bind(d_start_robot,d_info));
//    this->RobotServer.insert(rc_ThreadUnion("robot",t_robot));
    t_robot.join();
    this->is_init=true;
}
void RC::TaskManager::init(char *camera_file_path, char *serial_port,char *mapping,char *server_address, int port) {
    FDeviceInfo d_info;
    d_info.serial_port=serial_port;
    d_info.camera_file_path=camera_file_path;
    d_info.mapping=mapping;
    RC::LOG::logInfo("Start Robot");
    boost::thread t_robot(boost::bind(f_start_robot,d_info));
//    this->RobotServer.insert(rc_ThreadUnion("robot",t_robot));
    t_robot.join();
    this->is_init=true;
}
int RC::TaskManager::start() {
    if(this->is_init){
        if(!this->RobotServer.empty()){
            std::map<std::string,boost::thread>::iterator it;
            it = RobotServer.begin();
            while (it!=RobotServer.end())
                it++;
        }
        else return false;
    } else {
        RC::LOG::logError("You should run init before start");
        return -1;
    }
}
