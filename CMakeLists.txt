cmake_minimum_required(VERSION 3.28.3)


# Set up Project

# Set up CUDA nvcc to use the correct C++ compliler
set(CMAKE_CUDA_HOST_COMPILER "/usr/bin/g++-12")
project(GameOfLifeCUDA LANGUAGES CXX CUDA)

# Set the C++ standard. I use C++ 17 for this project since I need to use g++-12 since cuda only plays with them, and g++-12 supports this standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link source files
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/code/source/**/*.cpp)
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/code/source/**/*.cu)

# Setup main executable
add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/code/main.cpp ${src_files})
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/source/simulation)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/source/ui)


# Set up testing
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    tests ${CMAKE_CURRENT_SOURCE_DIR}/code/gtest.cpp
    ${src_files}
)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/source/simulation)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/source/ui)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/code/tests)

target_link_libraries( 
    tests
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(tests)