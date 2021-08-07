include_directories(
  ${SOURCE_DIR}
  ${GTEST_INCLUDE_DIR}
)

add_executable(test${PROJECT_NAME} 
    main.cpp
    test_queue.cpp
)

target_link_libraries(test${PROJECT_NAME} PRIVATE 
    lib${PROJECT_NAME}
    ${GTEST_LIB_DIR}/libgtest.a
    pthread
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS test${PROJECT_NAME} DESTINATION ${INSTALL_DIR})