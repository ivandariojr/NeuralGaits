enable_testing()
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
find_package(GTest REQUIRED)

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(test_torch_eigen_interace EXCLUDE_FROM_ALL test_torch_eigen_interace.cpp)
add_executable(test_load_model EXCLUDE_FROM_ALL test_load_model.cpp)
add_executable(test_mlp_caller EXCLUDE_FROM_ALL test_mlp_caller.cpp)

add_test(NAME test_load_model COMMAND test_load_model)
add_test(NAME test_mlp_caller COMMAND test_mlp_caller)
add_test(NAME test_torch_eigen_interace COMMAND test_torch_eigen_interace)

target_link_libraries(test_torch_eigen_interace PUBLIC ${PROJECT_NAME} gtest gtest_main ${TORCH_LIBRARIES} Eigen3::Eigen)
target_link_libraries(test_mlp_caller PUBLIC ${PROJECT_NAME} gtest gtest_main ${TORCH_LIBRARIES} Eigen3::Eigen)
target_link_libraries(test_load_model PUBLIC ${PROJECT_NAME} gtest gtest_main ${TORCH_LIBRARIES} stdc++fs Eigen3::Eigen)
