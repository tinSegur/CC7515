if(BUILD_TESTING)
    set(CPPLIB_TESTS
    "${PROJECT_SOURCE_DIR}/test/matrix_test.cc")

    add_executable(${PROJECT_NAME}Tests ${CPPLIB_TESTS})
    target_link_libraries(${PROJECT_NAME}Tests PRIVATE GTest::gtest_main ${PROJECT_NAME})
    include(GoogleTest)
endif ()