project(leptjson_test C)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(leptjson leptjson.c)   #根据提供的源文件生成库，默认静态库
add_executable(leptjson_test test.c)    #生成目标可执行文件
target_link_libraries(leptjson_test leptjson)   #指定链接给定目标和/或其依赖项时要使用的库或标志。

