cmake_minimum_required(VERSION 3.10)

# Set the project name
project(GameboyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Gameboy src/main.cpp src/JumpInstructionSet.cpp src/ControlInstructionSet.cpp src/cpu.cpp src/memory.cpp src/bus.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (if any)
# target_link_libraries(GameboyProject <library_name>)
