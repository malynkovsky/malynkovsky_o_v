cmake_minimum_required(VERSION 3.0)

project(course_work)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(course_work source.cpp)
target_link_libraries(course_work ${OpenCV_LIBS})