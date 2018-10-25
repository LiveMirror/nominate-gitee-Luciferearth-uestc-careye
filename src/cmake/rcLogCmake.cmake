set(LIB_NAME rclog)
set(RCLOG_FILES src/rc_log/rclog.cpp)
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${RCLOG_FILES})