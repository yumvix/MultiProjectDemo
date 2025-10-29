# 获取当前目录所有源文件
file(GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# 创建独立可执行文件
add_executable(${project_name} ${SOURCES})

# 创建一个自定义命令，在构建时复制 data.txt 到构建目录
add_custom_command(
    TARGET ${project_name} POST_BUILD
    COMMAND  ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/input.txt" "$<TARGET_FILE_DIR:${project_name}>/input.txt"
    COMMENT "Copying data.txt to build directory"
)
# # 创建一个自定义命令，在构建时复制 data.txt 到构建目录
# add_custom_command(
#     TARGET my_app POST_BUILD
#     COMMAND  ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/src/data.txt" "$<TARGET_FILE_DIR:my_app>/data.txt"
#     COMMENT "Copying data.txt to build directory"
# )

# # 添加一个自定义目标，用于运行 my_app 并设置工作目录
# add_custom_target(run_my_app ALL
#     COMMAND  ${CMAKE_COMMAND} -E chdir  $<TARGET_FILE_DIR:my_app>  $<TARGET_FILE:my_app>
#     DEPENDS my_app
#     COMMENT "Running my_app in its output directory"