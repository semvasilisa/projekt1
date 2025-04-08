cmake_minimum_required(VERSION 3.10)
project(data_structures)

include_directories(include)

set(SOURCE
    src/DoublyLinkedList.cpp
    src/SinglyLinkedList.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCE})

add_executable(efficiency_tests tests/efficiency_tests.cpp)
target_link_libraries(efficiency_tests ${PROJECT_NAME})

add_executable(app tests/app.cpp)
target_link_libraries(app ${PROJECT_NAME})