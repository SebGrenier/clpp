cmake_minimum_required (VERSION 3.8)

set_sources (SOURCEFILES
	"${CMAKE_CURRENT_SOURCE_DIR}/Lib.cpp"
HEADERS
	"${CMAKE_CURRENT_SOURCE_DIR}/Lib.hpp"
)

add_subdirectory ("Windows")
