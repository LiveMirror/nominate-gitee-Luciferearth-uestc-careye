//
// Created by PulsarV on 18-10-30.
//

#ifndef ROBOCAR_RM_MSG_SERVER_H
#define ROBOCAR_RM_MSG_SERVER_H

#include <rc_serial_msg.h>
#include <rc_image_msg.h>
namespace RC{
    namespace Message{
        class MessageServer: public SerialMessage,ImageMessage {

        };
    }
}


#endif //ROBOCAR_RM_MSG_SERVER_H
