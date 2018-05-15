//
// Created by PulsarV on 18-5-14.
//

#ifndef ROBOCAR_RCTASKMANAGER_H
#define ROBOCAR_RCTASKMANAGER_H
namespace RC{
    typedef std::map<std::string,pthread_t> ThreadPool;
    class TaskManager{
    public:
        ThreadPool ImageMessageQueue;
        ThreadPool RobotMove;
        ThreadPool DeviceSerial;
    };
}
#endif //ROBOCAR_RCTASKMANAGER_H
