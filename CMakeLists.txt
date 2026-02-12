cmake_minimum_required(VERSION 3.16)
project(LinkedListReverse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Good default warnings
if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

add_executable(linkedlist_reverse
  src/main.cpp
  include/LinkedList.h
)

target_include_directories(linkedlist_reverse PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Optional: treat warnings as errors in interview setting
option(ENABLE_WERROR "Treat warnings as errors" ON)
if (ENABLE_WERROR)
  if (MSVC)
    target_compile_options(linkedlist_reverse PRIVATE /WX)
  else()
    target_compile_options(linkedlist_reverse PRIVATE -Werror)
  endif()
endif()
