cmake_minimum_required(VERSION 3.15)
project(ObjectCachePool VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX d)

set(HIREDIS_INCLUDE_DIR "HIREDIS_INCLUDE_DIR-NOTFOUND" CACHE PATH "hiredis include directory")
set(HIREDIS_LIBRARY "HIREDIS_LIBRARY-NOTFOUND" CACHE FILEPATH "hiredis library")

set(MSGPACK_INCLUDE_DIR "MSGPACK_INCLUDE_DIR-NOTFOUND" CACHE PATH "msgpack include directory")

add_library(msgpack INTERFACE)
target_include_directories(msgpack
        INTERFACE $CACHE{MSGPACK_INCLUDE_DIR}
    )
	
add_library(hiredis SHARED IMPORTED)
set_target_properties(hiredis
        PROPERTIES IMPORTED_LOCATION $CACHE{HIREDIS_LIBRARY}
    )
target_include_directories(hiredis
        INTERFACE $CACHE{HIREDIS_INCLUDE_DIR}
    )
	
file(GLOB headers *.h)
file(GLOB sources *.cpp)
add_library(ObjectCachePool ${headers} ${sources})
target_link_libraries(ObjectCachePool PRIVATE hiredis)

install(TARGETS ObjectCachePool
        DESTINATION lib)
install(FILES ${headers}
        DESTINATION include)
