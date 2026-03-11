cmake_minimum_required(VERSION 3.10)
project(ArgumentSea LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER clang++)

add_library(argumentsea SHARED src/lib.cc)

target_include_directories(argumentsea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(argumentsea PROPERTIES 
    OUTPUT_NAME "argumentsea"
    PREFIX "lib"
)

install(TARGETS argumentsea DESTINATION /usr/lib)
install(FILES include/argumentsea.hpp DESTINATION /usr/include)