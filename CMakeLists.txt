cmake_minimum_required(VERSION 3.10)

# Set the project name
project(GameboyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Gameboy 
src/main.cpp 
src/cpu/ControlInstructionSet.cpp 
src/cpu/cpu.cpp 
src/memory.cpp 
src/bus.cpp
src/cpu/16bitLoadInstructionSet.cpp
src/cpu/8bitShiftInstructionSet.cpp
src/cpu/8bitALUInstructionSet.cpp
src/cpu/16bitALUInstructionSet.cpp
src/cpu/8bitLoadInstructionSet.cpp
src/cpu/JumpInstructionSet.cpp
src/testing/Testing.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries (if any)
# target_link_libraries(GameboyProject <library_name>)
