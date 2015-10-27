cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
  -Wall
  -g
  -O2
  -std=c++11
)

project(kadai1A)

add_executable (kadai1A main.cpp kadai1A.cpp)
target_link_libraries (kadai1A)