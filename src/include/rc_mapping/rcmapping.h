//
// Created by PulsarV on 18-7-5.
//

#ifndef ROBOCAR_RCMAPPING_H
#define ROBOCAR_RCMAPPING_H

#include <rc_globalVarable/rc_global.h>
#include <rc_mapping/slam_devices.h>
#include <ios>
namespace RC{
    class RcMapping:public slam_devices{
    public:
        RcMapping(char *map_file= RC_NULL_POINT);
        bool open(char *map_file,int mode=std::ios::app);
        bool record(char *map_file);
    private:
        FILE rc_map;
        char *map_path;
    };
}


#endif //ROBOCAR_RCMAPPING_H
