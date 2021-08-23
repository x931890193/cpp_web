cmake_minimum_required(VERSION 3.15)
project(cpp_web)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

add_definitions(-DORMPP_ENABLE_MYSQL)

add_executable(cpp_web ext/crow_all_new.hpp main.cpp include/conn.hpp include/include.hpp include/wrapper.hpp include/handler/index.hpp include/method.hpp include/method.cpp ext/resp.hpp)
# 设置boost库的根路径
set(BOOST_ROOT "/usr/local/include/boost")
# 查找boost的功能模块
find_package(Boost 1.76.0 COMPONENTS log thread system regex date_time REQUIRED)
INCLUDE_DIRECTORIES(
        /usr/local/mysql/include
)
set(mysqlclient "/usr/local/mysql/lib/libmysqlclient.a")
## 目标进行链接
target_link_libraries(cpp_web ${Boost_LIBRARIES} ${mysqlclient})



