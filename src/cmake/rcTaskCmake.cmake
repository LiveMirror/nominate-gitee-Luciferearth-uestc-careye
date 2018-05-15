set(LIB_NAME rctask)
set(SOURCE_FILES
        src/rc_task/rcVideoStreamQueue.cpp
        src/rc_task/rcWebStream.cpp
        src/rc_task/rcTaskManager.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${LIB_NAME} ${OPENCV_LIBS} rclog)