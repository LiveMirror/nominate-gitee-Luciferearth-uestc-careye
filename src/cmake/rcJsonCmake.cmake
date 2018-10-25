set(RC_JSON_FILES
        ${PROJECT_SOURCE_DIR}/src/rc_json/json_reader.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_json/json_tool.h
        ${PROJECT_SOURCE_DIR}/src/rc_json/json_value.cpp
        ${PROJECT_SOURCE_DIR}/src/rc_json/json_valueiterator.inl
        ${PROJECT_SOURCE_DIR}/src/rc_json/json_writer.cpp
        )

if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rcjson)
    add_library(${LIB_NAME} SHARED ${RC_JSON_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcjson)
        add_library(${LIB_NAME} ${RC_JSON_FILES})
    endif ()
endif ()