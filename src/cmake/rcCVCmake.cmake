set(LIB_NAME rccv)
set(SOURCE_FILES src/rc_cv/rcCV.cpp)
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
if (CMAKE_SYSTEM_NAME MATCHES "linux")
	target_link_libraries(${LIB_NAME} ${OpenCV_LIBS})
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
	target_link_libraries(${LIB_NAME} ${OPENCV_LIB})
endif (CMAKE_SYSTEM_NAME MATCHES "linux")


