//
// Created by PulsarV on 18-10-30.
//

#ifndef ROBOCAR_RC_BASE_MSG_H
#define ROBOCAR_RC_BASE_MSG_H
namespace RC{
    namespace Message{
        class BaseMessage{
        public:
            template <typename T>
            static  void pull_message(T message_queue);
            template <typename T>
            static  void fetch_message(T message_queue);
            template <typename T>
            static  void delete_message(T message_queue);
            template <typename T>
            static  void pop_message(T message_queue);
            template <typename T>
            static  void front_message(T message_queue);
            template <typename T>
            static  void release_message(T message_queue);
        };
    }
}
#endif //ROBOCAR_RC_BASE_MSG_H
