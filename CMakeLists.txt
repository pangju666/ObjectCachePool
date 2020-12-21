cmake_minimum_required(VERSION 3.15)
project(ObjectCachePool VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(hiredis-1.0.0)
add_subdirectory(msgpack-c-cpp-3.3.0)
add_subdirectory(ObjectCachePool)
