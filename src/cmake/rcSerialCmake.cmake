set(LIB_NAME rcserial)
set(SLIB_NAME lrcserial)
set(SOURCE_FILES
        src/rc_serial/rcserial.cpp
        src/rc_serial/rc_gyro_serial.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
add_library(${SLIB_NAME} ${SOURCE_FILES})