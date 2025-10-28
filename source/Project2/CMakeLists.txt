get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
#project(${CURRENT_DIR_NAME})

# 获取当前目录所有源文件
file(GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# 获取当前目录所有头文件
file(GLOB_RECURSE HEADER 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)


# 创建独立可执行文件
add_executable(${CURRENT_DIR_NAME} ${HEADER} ${SOURCES})
#target_include_directories(${CURRENT_DIR_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# 若有额外依赖（如OpenCV）
# target_link_libraries(project1 PRIVATE opencv_core opencv_highgui)