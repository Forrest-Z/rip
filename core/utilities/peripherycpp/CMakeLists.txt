# This probably doesn't comply with standards! Feel free to fix it.
cmake_minimum_required(VERSION 3.1)
project(peripherycpp)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES src/*.cpp src/*.hpp)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
if(ENABLE_TESTING)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif()
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} periphery misc)

#diag executables
if(ENABLE_TESTING)
    # Get test source files and doag data files
    file(GLOB_RECURSE ${PROJECT_NAME}_DIAG_SOURCES "diag/*.cpp")
    foreach(diagFile ${${PROJECT_NAME}_DIAG_SOURCES})
        file(RELATIVE_PATH name ${CMAKE_CURRENT_SOURCE_DIR}/diag ${diagFile})
        add_executable(${name} ${diagFile})
        set_property(TARGET ${name} PROPERTY CXX_STANDARD 11)
        target_link_libraries(${name} ${PROJECT_NAME})
    endforeach()
endif()

if(ENABLE_TESTING)
    # Get test source files and test data files
    file(GLOB_RECURSE ${PROJECT_NAME}_TEST_SOURCES "test/*.cpp")
    file(GLOB_RECURSE ${PROJECT_NAME}_TEST_DATA "test/data/*")

    # Copy test data to outdir/test
    include(FileOutputs)
    make_outputs(${CMAKE_CURRENT_SOURCE_DIR} "${${PROJECT_NAME}_TEST_DATA}" ${CMAKE_CURRENT_BINARY_DIR} testDataOutputs)

    # Create cmd_messneger_test executable, set to c++11, link cmd_messenger library and google test libraries
    add_executable(${PROJECT_NAME}_test ${${PROJECT_NAME}_TEST_SOURCES} ${testDataOutputs})
    set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 11)
    target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME}_test gmock gtest googletest_rip_macros)

    if(CMAKE_COMPILER_IS_GNUCXX)
        include(CodeCoverage)
        setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_NAME}_test coverage)
    endif()
endif()
