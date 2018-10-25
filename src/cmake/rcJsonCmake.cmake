set(RC_JSON_FILES
        src/rc_json/json_reader.cpp
        src/rc_json/json_tool.h
        src/rc_json/json_value.cpp
        src/rc_json/json_valueiterator.inl
        src/rc_json/json_writer.cpp
        )

if (RC_LIB STREQUAL "OFF")
    set(LIB_NAME rcjson)
    add_library(${LIB_NAME} SHARED ${RC_JSON_FILES})
    if (CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(SLIB_NAME lrcjson)
        add_library(${LIB_NAME} ${RC_JSON_FILES})
    endif ()
endif ()