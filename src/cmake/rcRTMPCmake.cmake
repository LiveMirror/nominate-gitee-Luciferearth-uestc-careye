set(LIB_NAME rcrtmp)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})

set(SOURCE_FILES
        src/rc_rtmp/rcrtmp.cpp
        )
include_directories(src/include)
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME})
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcrtmp)
        add_library(${SLIB_NAME} ${SOURCE_FILES})
endif ()

