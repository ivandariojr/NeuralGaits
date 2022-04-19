cmake_minimum_required(VERSION 3.10)

# set the project name
project(amber-cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3)
find_package(osqp REQUIRED)
find_package(OsqpEigen REQUIRED)

# L4DC learning traj_opt
find_package(learn-trajopt-cpp REQUIRED CONFIG)
find_package(Torch REQUIRED)
find_package(yaml-cpp REQUIRED CONFIG NO_DEFAULT_PATH)

# add library
add_library(robot-lib include/robot.hpp
		include/controller.hpp
		include/estimator.hpp
		include/timer.hpp
		include/lib.hpp
		include/trajectory.hpp
		include/Bezier.hpp
		src/robot.cpp
		src/controller.cpp
		src/estimator.cpp
		src/timer.cpp
		src/lib.cpp
		src/trajectory.cpp
		src/Bezier.cpp)

SET(inc_dir include_sim/codegen/lib)

add_library(Sim 
		${inc_dir}/C_matrix/C_matrix.h
		${inc_dir}/D_matrix/D_matrix.h
		${inc_dir}/G_matrix/G_matrix.h
		${inc_dir}/dz_2/dz_2.h
		${inc_dir}/Lf2y_matrix/Lf2y_matrix.h
		${inc_dir}/Lf2y_matrix/Lf2y_matrix_data.h
		${inc_dir}/Lf2y_matrix/Lf2y_matrix_initialize.h
		${inc_dir}/LgLfy_matrix/LgLfy_matrix.h
		${inc_dir}/LgLfy_matrix/LgLfy_matrix_data.h
		${inc_dir}/LgLfy_matrix/LgLfy_matrix_initialize.h
		${inc_dir}/p_cm/p_cm.h
		${inc_dir}/p_hip/p_hip.h
		${inc_dir}/p_swing/p_swing.h
		${inc_dir}/t_lb/t_lb.h
		${inc_dir}/Lf_t_lb/Lf_t_lb.h
		${inc_dir}/Lf2_t_lb/Lf2_t_lb.h
		${inc_dir}/LgLf_t_lb/LgLf_t_lb.h
		${inc_dir}/t_ub/t_ub.h
		${inc_dir}/Lf_t_ub/Lf_t_ub.h
		${inc_dir}/Lf2_t_ub/Lf2_t_ub.h
		${inc_dir}/LgLf_t_ub/LgLf_t_ub.h
		${inc_dir}/psw_lb/psw_lb.h
		${inc_dir}/Lf_psw_lb/Lf_psw_lb.h
		${inc_dir}/Lf2_psw_lb/Lf2_psw_lb.h
		${inc_dir}/LgLf_psw_lb/LgLf_psw_lb.h
		${inc_dir}/psw_ub/psw_ub.h
		${inc_dir}/Lf_psw_ub/Lf_psw_ub.h
		${inc_dir}/Lf2_psw_ub/Lf2_psw_ub.h
		${inc_dir}/LgLf_psw_ub/LgLf_psw_ub.h
		${inc_dir}/CBF_s1/CBF_s1.h
		${inc_dir}/CBF_s2/CBF_s2.h
		${inc_dir}/CBF_s3/CBF_s3.h
		${inc_dir}/CBF_Lfs1/CBF_Lfs1.h
		${inc_dir}/CBF_Lfs2/CBF_Lfs2.h
		${inc_dir}/CBF_Lfs3/CBF_Lfs3.h
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1.h
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2.h
		${inc_dir}/CBF_Lf2s3/CBF_Lf2s3.h
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1_initialize.h
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2_initialize.h
		${inc_dir}/CBF_Lf2s3/CBF_Lf2s3_initialize.h
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1_data.h
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2_data.h
		${inc_dir}/CBF_Lf2s1/rt_nonfinite.h
		${inc_dir}/CBF_Lf2s2/rt_nonfinite.h
		${inc_dir}/CBF_LgLfs1/CBF_LgLfs1.h
		${inc_dir}/CBF_LgLfs2/CBF_LgLfs2.h
		${inc_dir}/CBF_LgLfs3/CBF_LgLfs3.h
		${inc_dir}/CBF_ds1edx/CBF_ds1edx.h
		${inc_dir}/CBF_ds2edx/CBF_ds2edx.h
		${inc_dir}/CBF_ds1edx/CBF_ds1edx_initialize.h
		${inc_dir}/CBF_ds2edx/CBF_ds2edx_initialize.h
		${inc_dir}/CBF_ds1edx/CBF_ds1edx_data.h
		${inc_dir}/CBF_ds2edx/CBF_ds2edx_data.h
		${inc_dir}/C_matrix/C_matrix.c
		${inc_dir}/D_matrix/D_matrix.c
		${inc_dir}/G_matrix/G_matrix.c
		${inc_dir}/dz_2/dz_2.c
		${inc_dir}/Lf2y_matrix/Lf2y_matrix.c
		${inc_dir}/Lf2y_matrix/Lf2y_matrix_data.c
		${inc_dir}/Lf2y_matrix/Lf2y_matrix_initialize.c
		${inc_dir}/LgLfy_matrix/LgLfy_matrix.c
		${inc_dir}/LgLfy_matrix/LgLfy_matrix_data.c
		${inc_dir}/LgLfy_matrix/LgLfy_matrix_initialize.c
		${inc_dir}/p_cm/p_cm.c
		${inc_dir}/p_hip/p_hip.c
		${inc_dir}/p_swing/p_swing.c
		${inc_dir}/t_lb/t_lb.c
		${inc_dir}/Lf_t_lb/Lf_t_lb.c
		${inc_dir}/Lf2_t_lb/Lf2_t_lb.c
		${inc_dir}/LgLf_t_lb/LgLf_t_lb.c
		${inc_dir}/t_ub/t_ub.c
		${inc_dir}/Lf_t_ub/Lf_t_ub.c
		${inc_dir}/Lf2_t_ub/Lf2_t_ub.c
		${inc_dir}/LgLf_t_ub/LgLf_t_ub.c
		${inc_dir}/psw_lb/psw_lb.c
		${inc_dir}/Lf_psw_lb/Lf_psw_lb.c
		${inc_dir}/Lf2_psw_lb/Lf2_psw_lb.c
		${inc_dir}/LgLf_psw_lb/LgLf_psw_lb.c
		${inc_dir}/psw_ub/psw_ub.c
		${inc_dir}/Lf_psw_ub/Lf_psw_ub.c
		${inc_dir}/Lf2_psw_ub/Lf2_psw_ub.c
		${inc_dir}/LgLf_psw_ub/LgLf_psw_ub.c
		${inc_dir}/CBF_s1/CBF_s1.c
		${inc_dir}/CBF_s2/CBF_s2.c
		${inc_dir}/CBF_s3/CBF_s3.c
		${inc_dir}/CBF_Lfs1/CBF_Lfs1.c
		${inc_dir}/CBF_Lfs2/CBF_Lfs2.c
		${inc_dir}/CBF_Lfs3/CBF_Lfs3.c
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1.c
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2.c
		${inc_dir}/CBF_Lf2s3/CBF_Lf2s3.c
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1_initialize.c
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2_initialize.c
		${inc_dir}/CBF_Lf2s3/CBF_Lf2s3_initialize.c
		${inc_dir}/CBF_Lf2s1/CBF_Lf2s1_data.c
		${inc_dir}/CBF_Lf2s2/CBF_Lf2s2_data.c
		${inc_dir}/CBF_Lf2s1/rt_nonfinite.c
		${inc_dir}/CBF_Lf2s2/rt_nonfinite.c
		${inc_dir}/CBF_LgLfs1/CBF_LgLfs1.c
		${inc_dir}/CBF_LgLfs2/CBF_LgLfs2.c
		${inc_dir}/CBF_LgLfs3/CBF_LgLfs3.c
		${inc_dir}/CBF_ds1edx/CBF_ds1edx.c
		${inc_dir}/CBF_ds2edx/CBF_ds2edx.c
		${inc_dir}/CBF_ds1edx/CBF_ds1edx_initialize.c
		${inc_dir}/CBF_ds2edx/CBF_ds2edx_initialize.c
		${inc_dir}/CBF_ds1edx/CBF_ds1edx_data.c
		${inc_dir}/CBF_ds2edx/CBF_ds2edx_data.c
		)

set_target_properties(Sim PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Sim PUBLIC  ${EIGEN3_INCLUDE_DIR})
target_include_directories(Sim PUBLIC ${inc_dir})

target_include_directories(robot-lib PUBLIC src)
target_link_libraries(robot-lib learn-trajopt-cpp::learn-trajopt-cpp)
target_link_libraries(robot-lib ${TORCH_LIBRARIES})
target_link_libraries(robot-lib osqp::osqp)
target_link_libraries(robot-lib Sim)
target_link_libraries(robot-lib yaml-cpp)
set_target_properties(robot-lib PROPERTIES LINKER_LANGUAGE CXX)


# add the executable
add_executable(amber-cpp src/main.cpp)
target_link_libraries(amber-cpp robot-lib)



