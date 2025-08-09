cmake_minimum_required(VERSION 3.10)
project(CPP_Basic)

set(CMAKE_CXX_STANDARD 11)

# Add executables for each .cpp file in subfolders
add_executable(fstream      fstream/fstream.cpp)
add_executable(iomanip      iomanip/iomanip.cpp)
add_executable(iostream     iostream/iostream.cpp)
add_executable(sstream      sstream/sstream.cpp)