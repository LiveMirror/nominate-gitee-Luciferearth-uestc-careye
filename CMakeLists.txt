cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
project(RoboCar)

set(RC_TEST ON)
set(RC_LIB ON)

include(${PROJECT_SOURCE_DIR}/src/cmake/rcPlathformConfigCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcSLAMRadarCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcOpenGLCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcOpenCVCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcCaffeCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcEnviromentVariableCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcGlobalIncludeCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcVLCCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcMpiCmake.cmake)

include(${PROJECT_SOURCE_DIR}/src/cmake/rcJsonCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcLogCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcMappingCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcMessageCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcTaskCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcMoveCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcCVCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcGUICmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcSerialCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcRTMPCmake.cmake)

include(${PROJECT_SOURCE_DIR}/src/cmake/rcNetCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcMainCmake.cmake)
include(${PROJECT_SOURCE_DIR}/src/cmake/rcTestCmake.cmake)
