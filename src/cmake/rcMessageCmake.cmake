message(STATUS "Load Message Cmake")
set(LIB_NAME rcmessage)
set(RC_MESSAGE_FILES
        ${PROJECT_SOURCE_DIR}/src/rc_task/rc_message/rc_image_msg.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_task/rc_message/rc_msg_server.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_task/rc_message/rc_serial_msg.cpp
        )
if (RC_LIB STREQUAL "OFF")
    add_library(${LIB_NAME} SHARED ${RC_TASK_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} boost_system boost_thread rcmove rclog)
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcmessage)
        add_library(${SLIB_NAME} ${RC_TASK_FILES})
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB} lrcmove lrclog)
    endif ()
endif ()
