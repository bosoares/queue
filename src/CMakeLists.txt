find_package (Threads)

# add_library(
#     queue_lib STATIC
#     queue.hpp
#     queue.cpp
# )

add_executable(${PROJECT_NAME} main.cpp queue.hpp)
			
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})