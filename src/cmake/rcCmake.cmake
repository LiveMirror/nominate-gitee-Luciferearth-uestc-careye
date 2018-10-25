if (RC_LIB)
    set(LIB_NAME rc)
    set(RC_FILES
            ${RC_SERAIL_FILES}
            ${RC_TASK_FILES}
            ${RC_RTMP_FILES}
            ${RC_MOVE_FILES}
            ${RC_MAPPING_FILES}
            ${RC_GUI_FILES}
            ${RC_CV_FILES}
            ${RC_JSON_FILES}
            ${RC_LOG_FILES}
            )
    add_library(${LIB_NAME} SHARED ${RC_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME} ${OpenCV_LIBS}  boost_system boost_thread pthread)
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrccv)
        add_library(${SLIB_NAME} ${RC_FILES})
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB}  boost_system boost_thread)
    endif ()
endif ()

