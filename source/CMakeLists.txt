cmake_minimum_required(VERSION 3.10)
#message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

# 自动添加所有子文件夹作为独立工程
file(GLOB source_folders_subdir ${CMAKE_CURRENT_SOURCE_DIR}/*)
#message(STATUS "A-----------"${source_folders_subdir})

foreach(project_dir ${source_folders_subdir})
  if(IS_DIRECTORY ${project_dir})
    # 获取文件夹名（如 "project1"）
    message(STATUS "AB-----------"${project_dir})
    get_filename_component(project_name ${project_dir} NAME)
    
    # 添加子工程（关键步骤）
    add_subdirectory(${project_dir})
    #add_subdirectory(${project_dir} ${CMAKE_BINARY_DIR}/build_${project_name})
    # 可选：将目标统一输出到bin目录
    set_target_properties(${project_name} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
  endif()
endforeach()