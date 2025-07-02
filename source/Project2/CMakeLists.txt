# 获取当前目录所有源文件
file(GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# 创建独立可执行文件
add_executable(${project_name} ${SOURCES})

# 若有额外依赖（如OpenCV）
# target_link_libraries(project1 PRIVATE opencv_core opencv_highgui)