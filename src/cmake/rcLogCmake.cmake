set(LIB_NAME rclog)
set(SOURCE_FILES src/rc_log/rclog.cpp)
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})