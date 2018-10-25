set(RC_CV_FILES src/rc_cv/rcCV.cpp)

if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rccv)
    add_library(${LIB_NAME} SHARED ${RC_CV_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME} ${OpenCV_LIBS})
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrccv)
        add_library(${SLIB_NAME} ${RC_CV_FILES})
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB})
    endif ()
endif ()

