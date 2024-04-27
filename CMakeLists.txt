cmake_minimum_required(VERSION 3.28.3)

project(CollegeDsAssignments)
set(BOOL EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(src_dir "${PROJECT_SOURCE_DIR}/src")
set(include_dir "${PROJECT_SOURCE_DIR}/include")

include_directories(${include_dir})

file(GLOB source_cpp_files "${src_dir}/*.cpp")
file(GLOB header_hpp_files "${include_dir}/*.hpp")

add_executable(CollegeDsAssignments ${source_cpp_files} ${header_hpp_files})

target_compile_options(CollegeDsAssignments PUBLIC "-save-temps")
target_compile_features(CollegeDsAssignments PUBLIC c_std_23)
