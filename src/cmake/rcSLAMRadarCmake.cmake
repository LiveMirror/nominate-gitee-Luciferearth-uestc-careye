set(LIB_NAME rcslamradar)

set(RPLIDAR_SDK_PATH ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar)

#FILE(GLOB RPLIDAR_SDK_SRC
#        "${RPLIDAR_SDK_PATH}/src/arch/linux/*.cpp"
#        "${RPLIDAR_SDK_PATH}/src/hal/*.cpp"
#        "${RPLIDAR_SDK_PATH}/src/*.cpp"
#        )
#include_directories(
#        ${RPLIDAR_SDK_PATH}/include
#        ${RPLIDAR_SDK_PATH}/src
#)
include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include)
include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar)
include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src)
include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal)
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux)
    set(RCSLAMRADAR_FILES
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_cmd.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_driver.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_protocol.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rptypes.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/sdkcommon.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_TCP.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_impl.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_serial.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/abs_rxtx.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/assert.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/byteops.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/event.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/locker.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/socket.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/thread.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/thread.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/types.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/util.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/arch_linux.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/net_serial.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/net_serial.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/net_socket.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/thread.hpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/timer.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/linux/timer.h
            )
else(CMAKE_SYSTEM_NAME MATCHES "Windows")
    include_directories(${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32)
    set(RCSLAMRADAR_FILES
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_cmd.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_driver.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rplidar_protocol.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/include/rptypes.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/sdkcommon.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_TCP.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_impl.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/rplidar_driver_serial.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/abs_rxtx.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/assert.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/byteops.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/event.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/locker.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/socket.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/thread.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/thread.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/types.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/hal/util.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/timer.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/timer.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/net_socket.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/net_serial.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/net_serial.cpp
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/arch_win32.h
            ${PROJECT_SOURCE_DIR}/src/rc_mapping/slam_radar/src/arch/win32/winthread.hpp
            )
endif()

#add_library(${LIB_NAME} STATIC ${RCSLAMRADAR_FILES})
#target_link_libraries(${LIB_NAME} ${OpenCV_LIBS})
