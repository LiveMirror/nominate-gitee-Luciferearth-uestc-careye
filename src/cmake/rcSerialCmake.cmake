set(LIB_NAME rcserial)
set(SOURCE_FILES
        src/rc_serial/rcserial.cpp
        src/rc_serial/rc_gyro_serial.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME})
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcserial)
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB})
        add_library(${SLIB_NAME} ${SOURCE_FILES})
endif ()
