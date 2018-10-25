set(OpenCV_DIR 3rdparty/opencv_build)
message(STATUS "OpenCV_DIR is ${OpenCV_DIR}")
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV_VERSION ${OpenCV_VERSION}")
