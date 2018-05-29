//
// Created by PulsarV on 18-5-14.
//

#ifndef ROBOCAR_RCTASKMANAGER_H
#define ROBOCAR_RCTASKMANAGER_H
#define CAMERA_TYPE_FILE 1
#define CAMERA_TYPE_DEVICE 0
#include <map>
#include <rc_move/rcmove.h>
#include <boost/thread/thread.hpp>
namespace RC{
    typedef boost::thread rc_Thread;
    typedef std::map<std::string,rc_Thread> rc_ThreadPool;
    typedef std::pair<std::string,rc_Thread> rc_ThreadUnion;
    typedef struct _DeviceInfo{
        char *serial_port;
        int camera_index;
        char *mapping;
    }DeviceInfo;
    typedef struct _FDeviceInfo{
        int type=CAMERA_TYPE_FILE;
        char *serial_port;
        char *camera_file_path;
        char *mapping;
    }FDeviceInfo;
    typedef struct _ServerInfo{
        char *server_address;
        int port;
    }ServerInfo;
    void d_start_robot(DeviceInfo device_info);
    void f_start_robot(FDeviceInfo device_info);
    void start_rtmp_server(ServerInfo server_info);
    class TaskManager{
    public:
        TaskManager(char *server_name);
        void init(int camera_index,char *serial_port,char* mapping,char *server_address="0.0.0.1",int port=-1);
        void init(char *camera_file_path,char *serial_port,char *mapping,char *server_address="0.0.0.0",int port=-1);
        int start();
    private:
        bool is_init= false;
        char *server_name;
        rc_ThreadPool RobotServer;

    };
}
#endif //ROBOCAR_RCTASKMANAGER_H
