set(LIB_NAME rccv)
set(SOURCE_FILES src/rc_cv/rcCV.cpp)
include_directories(src/include)

add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(${LIB_NAME} ${OpenCV_LIBS})
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(SLIB_NAME lrccv)
	add_library(${SLIB_NAME} ${SOURCE_FILES})
	target_link_libraries(${LIB_NAME} ${OPENCV_LIB})
endif ()

