set(LIB_NAME rcmapping)
set(RCMAPPING_FILES
        ${PROJECT_SOURCE_DIR}/src/include/rc_mapping/rcmapping.h
        ${PROJECT_SOURCE_DIR}/src/rc_mapping/rcmapping.cpp
        ${RCSLAMRADAR_FILES}
        )
include_directories(${PROJECT_SOURCE_DIR}/src/include)
add_library(${LIB_NAME} SHARED ${RCMAPPING_FILES})
target_link_libraries(${LIB_NAME} ${OpenCV_LIBS} rclog)
