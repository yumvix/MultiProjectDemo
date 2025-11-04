# 获取当前目录所有源文件
file(GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# 创建独立可执行文件
add_executable(${project_name} ${SOURCES})

# # 创建一个自定义命令，在构建时复制 data.txt 到构建目录
# add_custom_command(
#     TARGET ${project_name} POST_BUILD
#     COMMAND  ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_CURRENT_SOURCE_DIR}/input.txt" "$<TARGET_FILE_DIR:${project_name}>/input.txt"
#     COMMENT "Copying data.txt to build directory"
# )
# 设置调试工作目录为可执行文件所在的目录
set_target_properties(${project_name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")