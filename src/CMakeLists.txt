find_package (Threads)


add_library(lib${PROJECT_NAME} INTERFACE)
target_include_directories(lib${PROJECT_NAME} INTERFACE include/)

add_executable(${PROJECT_NAME} main.cpp)

#set_target_properties(lib${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} PRIVATE lib${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})