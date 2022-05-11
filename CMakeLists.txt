cmake_minimum_required(VERSION 3.23.0)

project(mon-projet)

find_package(
  SFML
  COMPONENTS system window network graphics audio
  REQUIRED)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(mon-projet ${SOURCE_FILES})

target_link_libraries(mon-projet sfml-system sfml-window sfml-network
                      sfml-graphics sfml-audio)
