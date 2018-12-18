cmake_minimum_required(VERSION 3.8)

# set up the project name
project(ImaPlatform)

find_package(cpprestsdk REQUIRED)

# specify the global variables
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -m64 -L/usr/local/lib/ -I/usr/local/opt/openssl/include -lboost_system -lboost_thread-mt -lboost_chrono-mt")

# add header files to be used
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/Applications/CPLEX_Studio128/cplex/include)
include_directories(/Applications/CPLEX_Studio128/concert/include)
include_directories(${PROJECT_SOURCE_DIR}/antlr4-cpp-runtime-4.7.1-macos/antlr4-runtime)
include_directories(${PROJECT_SOURCE_DIR}/parser/include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(parser)

# build command: cmake . -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_INCLUDE_DIR=/usr/local/opt/openssl/lib
