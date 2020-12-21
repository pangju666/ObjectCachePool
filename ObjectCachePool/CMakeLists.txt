file(GLOB headers *.h)
file(GLOB sources *.cpp)

add_library(ObjectCachePool ${headers} ${sources})
target_link_libraries(ObjectCachePool
        PUBLIC msgpack
		PUBLIC hiredis
)

install(TARGETS ObjectCachePool DESTINATION lib)
install(FILES ${headers} DESTINATION include)
