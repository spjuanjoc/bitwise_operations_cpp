cmake_minimum_required(VERSION 3.15)
project(bitwise_operations_cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(PROJECT_OPTIONS
    -O3
    -Werror
    -Wpedantic
    -Wall
    -Wextra
    -Woverflow
    )
target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})
# To get Werror working replace INTERFACE for PUBLIC or PRIVATE

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
conan_target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
message("${CONAN_LIBS}")
