cmake_minimum_required(VERSION 3.30)
project(laki_beam_python_interface)

set(CMAKE_CXX_STANDARD 17)

include_directories(/home/ralf/dev/boost/include)
find_package(Boost 1.85.0 COMPONENTS thread)

# add_executable(laki_beam_python_interface LakiBeamUDP.cpp python_interface.cpp main.cpp)
add_library(laki_beam_python_interface SHARED  LakiBeamUDP.cpp python_interface.cpp)
target_link_libraries(laki_beam_python_interface Boost::thread)

set_target_properties(laki_beam_python_interface PROPERTIES PUBLIC_HEADER python_interface.h)
# add_library(laki_beam_python_interface LakiBeamUDP.cpp python_interface.cpp)
