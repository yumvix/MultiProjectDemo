cmake_minimum_required(VERSION 3.10)


get_filename_component(CURRENT_DIR ${CMAKE_SOURCE_DIR} NAME)
message(STATUS ${CURRENT_DIR})
project(${CURRENT_DIR})

# 设置C++标准（可选）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子工程（关键步骤）

message(STATUS ${CMAKE_SOURCE_DIR})
message(STATUS ${CMAKE_SOURCE_DIR}/source)
add_subdirectory(${CMAKE_SOURCE_DIR}/source)

# # 自动添加所有子文件夹作为独立工程
# file(GLOB sln_folders_subdir LIST_DIRECTORIES true ${CMAKE_SOURCE_DIR}/source)
# message(STATUS ${sln_folders_subdir})
# foreach(project_dir ${sln_folders_subdir})
#   if(IS_DIRECTORY ${project_dir})
#     # 获取文件夹名（如 "project1"）
#     message(STATUS ${project_dir})
#     get_filename_component(project_name ${project_dir} NAME)
    
#     # 添加子工程（关键步骤）
#     add_subdirectory(${project_dir} ${CMAKE_BINARY_DIR}/build_${project_name})
    
#     # 可选：将目标统一输出到bin目录
#     set_target_properties(${project_name} PROPERTIES
#       RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#     )
#   endif()
# endforeach()