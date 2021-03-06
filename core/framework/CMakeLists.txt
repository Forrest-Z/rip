cmake_minimum_required(VERSION 3.1)
project(framework)

# utils built by top level cmake
# appendages built by top level cmake


# Get all .cpp files except for main.cpp
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "src/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "include/*.hpp")

# Create the core library for RIP
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
if(ENABLE_TESTING)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif()
target_link_libraries(${PROJECT_NAME}
    fmt json spdlog cppfs
    units cmd_messenger appendages)
target_include_directories(${PROJECT_NAME} PUBLIC include)

if(ENABLE_TESTING)
    # Get test source files and test data files
    file(GLOB_RECURSE ${PROJECT_NAME}_TEST_SOURCES "test/*.cpp")
    file(GLOB_RECURSE ${PROJECT_NAME}_TEST_DATA "test/data/*")

    include(FileOutputs)

    # Copy test data to outdir/test
    make_outputs(${CMAKE_CURRENT_SOURCE_DIR} "${${PROJECT_NAME}_TEST_DATA}" ${CMAKE_CURRENT_BINARY_DIR} testDataOutputs)

    # Create arduino_gen_test executable, set to c++11, link arduino_gen library and google test libraries
    add_executable(${PROJECT_NAME}_test ${${PROJECT_NAME}_TEST_SOURCES} ${testDataOutputs})
    set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 11)
    target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME}_test gmock gtest googletest_rip_macros)
endif()
