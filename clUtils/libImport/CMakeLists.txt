cmake_minimum_required (VERSION 3.8)

target_sources (${PROJECT_NAME} 
PRIVATE 
	"${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp"
PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/lib.hpp"
)

add_subdirectory ("windows")
