cmake_minimum_required (VERSION 3.6)

project (clUtils)

add_library (${PROJECT_NAME} clUtils.cpp)

install (TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)