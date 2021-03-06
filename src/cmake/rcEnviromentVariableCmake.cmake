set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/libs)

message(STATUS "Author:Pulsar-V")
message(STATUS "Version:1.0.0")

set(MAIN_DIR ${PROJECT_SOURCE_DIR})
message(STATUS "MAIN_DIR is ${MAIN_DIR}")
set(LIB_DIR ${PROJECT_BINARY_DIR}/libs)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	include_directories(${PROJECT_SOURCE_DIR}/3rdparty/boost_1_67_0)
endif ()

set(VLC_LIBS
        vlc
        )