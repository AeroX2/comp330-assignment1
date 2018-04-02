cmake_minimum_required(VERSION 3.9)
project(comp330_assignment1)

set(CMAKE_CXX_FLAGS "-std=c++0x")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(comp330_assignment1
        src/entities/entity.cpp
        src/entities/entity.hpp
        src/entities/fire.cpp
        src/entities/fire.hpp
        src/entities/helicopter.cpp
        src/entities/helicopter.hpp
        src/entities/house.cpp
        src/entities/house.hpp
        src/entities/lake.cpp
        src/entities/lake.hpp
        src/entities/splash.cpp
        src/entities/splash.hpp
        src/entities/vector.cpp
        src/entities/vector.hpp
        src/constants.hpp
        src/main.cpp
        src/utils.cpp
        src/utils.hpp
        src/world.cpp
        src/world.hpp)
target_link_libraries(comp330_assignment1 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})