cmake_minimum_required(VERSION 3.29)
project(Violet_OpenGL)

set(CMAKE_CXX_STANDARD 20)

# Find OpenGL and GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# irrklang
include_directories(/home/sama/libs/irrKlang/irrKlang-64bit-1.6.0/include)
link_directories(/home/sama/libs/irrKlang/irrKlang-64bit-1.6.0/bin/linux-gcc-64)

add_executable(Violet_OpenGL main.cpp)

# Link OpenGL and GLUT libraries
target_link_libraries(Violet_OpenGL IrrKlang ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})