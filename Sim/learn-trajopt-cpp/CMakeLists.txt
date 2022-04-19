cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(learn-trajopt-cpp VERSION 0.1 LANGUAGES CXX)

# Include utilities
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(FetchContent)

add_compile_options(-std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3 -DNDEBUG")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(Torch REQUIRED)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(${PROJECT_NAME}_HEADERS
  include/mlp_caller.h
  include/torch_utils.h
  )

add_library(${PROJECT_NAME} INTERFACE ${${PROJECT_NAME}_HEADERS})
target_link_libraries(${PROJECT_NAME} INTERFACE ${TORCH_LIBRARIES} Eigen3::Eigen)
target_include_directories(${PROJECT_NAME} INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>")

set_target_properties(${PROJECT_NAME} PROPERTIES
  PUBLIC_HEADER "${${PROJECT_NAME}_HEADERS}"
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

configure_package_config_file(
"${PROJECT_SOURCE_DIR}/cmake/config.cmake.in"
"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(
EXPORT ${PROJECT_NAME}_Targets
FILE ${PROJECT_NAME}Targets.cmake
NAMESPACE ${PROJECT_NAME}::
DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
            "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
      DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

add_subdirectory(tests)