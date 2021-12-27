cmake_minimum_required(VERSION 2.8.3)
project(ros_service_examples)

find_package(catkin REQUIRED COMPONENTS roscpp roslib message_generation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

add_service_files(FILES VectorSummationService.srv)

generate_messages()

catkin_package(CATKIN_DEPENDS roscpp roslib message_runtime)
  
include_directories(${catkin_INCLUDE_DIRS})
add_executable(vsum_service src/vsum_service.cpp)
add_executable(vsum_client src/vsum_client.cpp)

target_link_libraries(vsum_service ${catkin_LIBRARIES})

target_link_libraries(vsum_client ${catkin_LIBRARIES})

catkin_install_python(PROGRAMS nodes/vsum_service_python.py DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
