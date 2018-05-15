set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

set(MAIN_DIR ${PROJECT_SOURCE_DIR})
message(STATUS "MAIN_DIR is ${MAIN_DIR}")
set(LIB_DIR ${PROJECT_BINARY_DIR}/libs)

set(OPENCV_LIBS
        opencv_features2d
        opencv_calib3d
        opencv_core
        opencv_features2d
        opencv_flann
        opencv_highgui
        opencv_imgcodecs
        opencv_imgproc
        opencv_ml
        opencv_objdetect
        opencv_photo
        opencv_shape
        opencv_stitching
        opencv_superres
        opencv_video
        opencv_viz)
set(VLC_LIBS
        vlc
        )