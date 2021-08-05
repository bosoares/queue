cmake_minimum_required(VERSION 3.5)
project(myQueue VERSION 1.0.0)

set(INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE}")
#add_subdirectory(externals)
add_subdirectory(src)
