cmake_minimum_required(VERSION 3.22)

project(additionGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find the SFML package and its components
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(main src/main.cpp 
src/titleScreen.cpp src/titleScreen.h 
src/countdown.cpp src/countdown.h
src/showNums.cpp src/showNums.h
src/finalGuess.cpp src/finalGuess.h
src/leaderboard.cpp src/leaderboard.h
src/helperFunctions.cpp src/helperFunctions.h)
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE sfml-graphics)
target_link_libraries(main PRIVATE sfml-window)