cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
message(STATUS "Load RC NET")

include_directories(${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/include)
set(RC_NNET_FILES
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/activation_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/activation_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/activations.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/activations.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/avgpool_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/avgpool_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/batchnorm_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/batchnorm_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/blas.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/blas.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/box.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/box.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/classifier.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/col2im.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/col2im.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/compare.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/connected_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/connected_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/convolutional_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/convolutional_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/cost_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/cost_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/crnn_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/crnn_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/crop_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/crop_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/cuda.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/cuda.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/data.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/data.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/deconvolutional_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/deconvolutional_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/demo.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/demo.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/detection_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/detection_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/dropout_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/dropout_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/gemm.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/gemm.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/gru_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/gru_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/im2col.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/im2col.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/image.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/image.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/image_opencv.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/stb_image_write.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/iseg_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/iseg_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/l2norm_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/l2norm_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/list.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/list.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/local_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/local_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/logistic_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/logistic_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/lstm_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/lstm_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/matrix.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/matrix.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/maxpool_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/maxpool_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/network.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/network.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/normalization_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/normalization_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/option_list.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/option_list.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/parser.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/parser.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/region_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/region_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/region_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/region_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/reorg_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/reorg_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/rnn_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/rnn_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/route_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/route_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/shortcut_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/shortcut_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/softmax_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/softmax_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/stb_image.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/tree.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/tree.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/upsample_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/upsample_layer.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/utils.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/utils.h
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/yolo_layer.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/src/yolo_layer.h
        )
set(YOLO3
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/darknet.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/detector.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/dice.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/rnn.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/rnn_vid.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/segmenter.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/super.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/swag.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/tag.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/voxel.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/writing.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/coco.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/art.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/attention.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/captcha.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/cifar.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/classifier.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/lsd.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/regressor.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/nightmare.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/instance-segmenter.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/go.c
        ${PROJECT_SOURCE_DIR}/src/rc_cv/rcnet/examples/yolo.c
        )

add_executable(rcnetapp ${YOLO3})
if (RC_LIB STREQUAL "OFF")
    add_library(rcnet SHARED ${RC_NNET_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(rcnet pthread stdc++ ${OpenCV_LIBS} rccv rcserial rclog)
        target_link_libraries(rcnetapp rcnet pthread stdc++ ${OpenCV_LIBS} rccv rcserial rclog)
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        target_link_libraries(rcnet pthread stdc++ ${OpenCV_LIB} rccv rcserial rclog)
        target_link_libraries(rcnetapp rcnet pthread stdc++ ${OpenCV_LIB} rccv rcserial rclog)
        add_library(${SLIB_NAME} ${RC_MOVE_FILES})
    endif ()
else()
    target_link_libraries(rcnetapp rc)
endif ()