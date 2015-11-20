cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
  -Wall
  -g
  -O2
  -std=c++11
)

project(kadai3)

add_executable (kadai3 main.cpp kadai3.cpp kadai1A.cpp)
target_link_libraries (kadai3)