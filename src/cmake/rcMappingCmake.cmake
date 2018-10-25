set(RC_MAPPING_FILES
        ${PROJECT_SOURCE_DIR}/src/include/rc_mapping/rcmapping.h
        ${PROJECT_SOURCE_DIR}/src/rc_mapping/rcmapping.cpp
        ${RCSLAMRADAR_FILES}
        )
include_directories(${PROJECT_SOURCE_DIR}/src/include)
if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rcmapping)
    add_library(${LIB_NAME} SHARED ${RC_MAPPING_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} rccv rcserial rclog)
    elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcmapping)
        add_library(${LIB_NAME} ${RC_MAPPING_FILES})
        target_link_libraries(${LIB_NAME} ${OPENCV_LIB} lrclog)
    endif ()
endif ()
