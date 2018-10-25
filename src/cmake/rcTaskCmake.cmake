message(STATUS "Load Task Cmake")
set(LIB_NAME rctask)
set(SOURCE_FILES
        src/rc_task/rcVideoStreamQueue.cpp
        src/rc_task/rcWebStream.cpp
        src/rc_task/rcTaskManager.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} boost_system boost_thread rcmove rclog)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(SLIB_NAME lrctask)
    add_library(${SLIB_NAME} ${SOURCE_FILES})
	target_link_libraries(${LIB_NAME} ${OPENCV_LIB} lrcmove lrclog)
endif ()
