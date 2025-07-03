# cmake_minimum_required(VERSION 3.0)
# project(mprpc)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# include_directories(${PROJECT_SOURCE_DIR}/src)
# include_directories(${PROJECT_SOURCE_DIR}/example)

# link_directories(${PROJECT_SOURCE_DIR}/lib)

# # add_subdirectory(src)
# add_subdirectory(example)

# target_link_libraries(main PRIVATE protobuf)
# link_directories(/usr/local/lib)

cmake_minimum_required(VERSION 3.13)
project(mprpc)

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 直接指定 protobuf 路径（根据你的实际安装路径修改）
set(PROTOBUF_INCLUDE_DIR "/usr/local/include")  # protobuf 头文件目录
set(PROTOBUF_LIB_DIR "/usr/local/lib")         # protobuf 库目录
set(PROTOBUF_LIB "protobuf")                   # protobuf 库名

# 包含目录
include_directories(
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/example
    ${PROTOBUF_INCLUDE_DIR}  # 添加 protobuf 头文件目录
)

# 库目录
link_directories(
    ${PROJECT_SOURCE_DIR}/lib
    ${PROTOBUF_LIB_DIR}      # 添加 protobuf 库目录
)

# 添加子目录
add_subdirectory(src)
# 添加示例目录
add_subdirectory(example)