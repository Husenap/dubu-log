set(target_name "dubu_log")

set(src_precompiled
    "src/dubu_log/precompiled.h")

set(src_logger
    "src/dubu_log/logger/MemoryLogger.cpp"
    "src/dubu_log/logger/MemoryLogger.h"
    "src/dubu_log/logger/FileLogger.cpp"
    "src/dubu_log/logger/FileLogger.h"
    "src/dubu_log/logger/ConsoleLogger.cpp"
    "src/dubu_log/logger/ConsoleLogger.h"
    "src/dubu_log/logger/Logger.cpp"
    "src/dubu_log/logger/Logger.h"
    "src/dubu_log/logger/ILogger.h")

set(src_dubu_log
    "src/dubu_log/dubu_log.h")

set(src_files
    ${src_precompiled}
    ${src_logger}
    ${src_dubu_log})

# Project
add_library(${target_name} STATIC ${src_files})

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings
    fmt)

target_precompile_headers(${target_name} PUBLIC ${src_precompiled})

source_group("src" FILES ${src_dubu_log})
source_group("src/logger" FILES ${src_logger})
source_group("src/precompiled" FILES ${src_precompiled})
source_group("src/precompiled" REGULAR_EXPRESSION "cmake_pch\.[ch]xx")

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})
