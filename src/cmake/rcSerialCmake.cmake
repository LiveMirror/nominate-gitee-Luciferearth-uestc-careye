set(LIB_NAME rcserial)
set(SOURCE_FILES
        src/rc_serial/rcserial.cpp
        src/rc_serial/rc_gyro_serial.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${LIB_NAME})