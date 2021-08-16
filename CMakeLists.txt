# 最低支持版本要求
cmake_minimum_required(VERSION 3.5)

# 工程名
project(leetcode_practice)

# 扫描根目录下文件并添加到DIR_SRC
aux_source_directory(. DIR_SRC)

# 生成可执行程序
add_executable(main ${DIR_SRC})