cmake_minimum_required(VERSION 3.5)
project(raisimOgre_examples VERSION 0.2.0)

find_package(raisimOgre CONFIG REQUIRED)
find_package(Eigen3 REQUIRED HINTS ${Eigen3_HINT})
find_package(yaml-cpp REQUIRED PATHS /usr/local/lib/yaml-cpp-yaml-cpp-0.6.0/include/yaml-cpp)

#==
# Build Targets
#==

function(create_executable app_name file_name)
  add_executable(${app_name} ${file_name})
  target_link_libraries(${app_name} PUBLIC raisim::raisimOgre yaml-cpp)
  target_include_directories(${app_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${EIGEN3_INCLUDE_DIRS})
  target_compile_definitions(${app_name} PRIVATE "-DEXAMPLE_ROBOT_RESOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}/rsc/")
endfunction()

# robots
# create_executable(ghostV60 src/robots/ghostV60.cpp)
create_executable(amber src/robots/amber.cpp)

#==
# Install example binaries
#==

set(EXAMPLE_BINS
	amber
)

install(
  TARGETS ${EXAMPLE_BINS}
  RUNTIME DESTINATION bin
)

# EOF
