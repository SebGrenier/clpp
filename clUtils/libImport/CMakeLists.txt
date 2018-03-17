cmake_minimum_required (VERSION 3.8)

set (Sources ${Sources} "${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp" PARENT_SCOPE)

add_subdirectory ("windows")