set(LIB_NAME rcserial)
set(RC_SERAIL_FILES
        ${PROJECT_SOURCE_DIR}/src/rc_serial/rcserial.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_serial/rc_gyro_serial.cpp
        )
if (RC_LIB STREQUAL "OFF")
    add_library(${LIB_NAME} SHARED ${RC_SERAIL_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME})
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcserial)
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB})
        add_library(${SLIB_NAME} ${RC_SERAIL_FILES})
    endif ()
endif ()
