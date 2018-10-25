message(STATUS "Load VLC Cmake")
set(RC_VLC_FILES

        )

if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rcvlc)
#    add_library(${LIB_NAME} SHARED ${RC_TASK_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
#        target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} boost_system boost_thread rcmove rclog)
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
#        set(SLIB_NAME lrctask)
#        add_library(${SLIB_NAME} ${RC_TASK_FILES})
#        target_link_libraries(${LIB_NAME} ${OPENCV_LIB} lrcmove lrclog)
    endif ()
endif ()
