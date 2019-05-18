include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(basic_tests
        GraphTest.cpp)

target_link_libraries(basic_tests gtest gtest_main)