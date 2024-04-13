if(BUILD_TESTING)
    set(CPPLIB_TESTS
    "${PROJECT_SOURCE_DIR}/test/matrix_test.cc")

    add_executable(${PROJECT_NAME}Tests ${CPPLIB_TESTS})
    target_link_libraries(${PROJECT_NAME}Tests ${PROJECT_NAME} gtest gtest_main)

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME}Tests)
endif ()