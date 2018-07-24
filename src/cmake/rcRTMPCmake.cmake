set(LIB_NAME rcrtmp)
set(SOURCE_FILES
        src/rc_rtmp/rcrtmp.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})