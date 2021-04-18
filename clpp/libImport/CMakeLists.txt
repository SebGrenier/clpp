cmake_minimum_required (VERSION 3.8)

set_sources (SOURCEFILES
	"${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp"
HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/lib.hpp"
)

add_subdirectory ("windows")
