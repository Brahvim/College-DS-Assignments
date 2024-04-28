cmake_minimum_required(VERSION 3.28.3)

project(CollegeDsAssignments)
set(BOOL EXPORT_COMPILE_COMMANDS true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(api_src_dir "${PROJECT_SOURCE_DIR}/api/src")
set(test_src_dir "${PROJECT_SOURCE_DIR}/test/src")

set(api_include_dir "${PROJECT_SOURCE_DIR}/api/include")
set(test_include_dir "${PROJECT_SOURCE_DIR}/test/include")

include_directories(${api_include_dir} ${test_include_dir})

file(GLOB api_source_cpp_files "${api_src_dir}/*.c")
file(GLOB api_header_hpp_files "${api_include_dir}/*.h")

file(GLOB test_source_cpp_files "${test_src_dir}/*.c")
file(GLOB test_header_hpp_files "${test_include_dir}/*.h")

add_executable(
  CollegeDsAssignments ${api_header_hpp_files} ${test_header_hpp_files}
                       ${api_source_cpp_files} ${test_source_cpp_files})

target_compile_options(CollegeDsAssignments PUBLIC "-save-temps" "-O0")
target_compile_features(CollegeDsAssignments PUBLIC c_std_23)
