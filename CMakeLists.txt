cmake_minimum_required(VERSION 3.10)
project(data_structures)

add_library(data_structures_lib INTERFACE)
target_include_directories(data_structures_lib INTERFACE include/)

add_executable(efficiency_tests src/efficiency_tests.cpp)
target_link_libraries(efficiency_tests data_structures_lib)

add_executable(app src/app.cpp)
target_link_libraries(app data_structures_lib)