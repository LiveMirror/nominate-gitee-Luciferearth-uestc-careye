set(EXE_NAME RoboCar)
set(OpenCV_DIR opencv_build)
set(SOURCE_FILES src/rc_main/main.cpp)
include_directories(src/include)
add_custom_command(OUTPUT ${EXE_NAME}
        POST_BUILD
        COMMAND copy ${PROJECT_SOURCE_DIR}/3rdparty/opencv_build/bin ${PROJECT_BINARY_DIR}/bin
        COMMENT  "Copy libs"
        )
add_custom_target(Test1 ALL DEPENDS ${EXE_NAME})
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXE_NAME} ${OPENCV_LIBS})
