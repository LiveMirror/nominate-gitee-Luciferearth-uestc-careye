
set(RC_RTMP_FILES
        src/rc_rtmp/rcrtmp.cpp
        )

if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rcrtmp)
    add_library(${LIB_NAME} SHARED ${RC_RTMP_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME})
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcrtmp)
        add_library(${SLIB_NAME} ${RC_RTMP_FILES})
    endif ()
endif ()

