set(LIB_NAME rcrtmp)
set(SLIB_NAME lrcrtmp)
set(SOURCE_FILES
        src/rc_rtmp/rcrtmp.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
add_library(${SLIB_NAME} ${SOURCE_FILES})