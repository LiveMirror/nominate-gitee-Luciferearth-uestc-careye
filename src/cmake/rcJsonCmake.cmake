set(LIB_NAME rcjson)
set(SLIB_NAME lrcjson)
set(SOURCE_FILES
        src/rc_json/json_reader.cpp
        src/rc_json/json_tool.h
        src/rc_json/json_value.cpp
        src/rc_json/json_valueiterator.inl
        src/rc_json/json_writer.cpp
        )
include_directories(src/include)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
add_library(${SLIB_NAME} ${SOURCE_FILES})