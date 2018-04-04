project(COMP781Project)
cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-std=c++11")

find_package(ompl REQUIRED)
include_directories(${OMPL_INCLUDE_DIRS} .)

add_executable(Planning
	src/exe/planning.cc
	src/planner/RRT.cc
)

target_link_libraries(Planning
	${OMPL_LIBRARIES} 
	${OMPLAPP_LIBRARIES}
)
