cmake_minimum_required (VERSION 3.8)

project (CLpp)

set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include (set_sources)

# Add 3rd party include directories
set (OPENCL_DIR "${WORKSPACEROOT}/OpenCL-Headers")
include_directories ("${OPENCL_DIR}")

# Add platform defines
if(${WIN32})
	add_definitions (-DWINDOWS_PLATFORM)
endif(${WIN32})

add_library (${PROJECT_NAME} "")

set (INCLUDE_INSTALL_DIR "${WORKSPACEROOT}/include")
set (LIB_INSTALL_DIR "${WORKSPACEROOT}/lib")

set_sources (SOURCEFILES
	"CLpp.cpp"
	"CLApi.cpp"
	"CLUtilities.cpp"
	"CLPlatform.cpp"
HEADERS
	"CLpp.hpp"
	"CLApi.hpp"
	"CLFunction.hpp"
	"CLUtilities.hpp"
	"CLPlatform.hpp"
	"CLCachedProperty.hpp"
	"CLTypeTraits.hpp"
)

# Include subdirectories
add_subdirectory ("LibImport")

 # Make sure c++14 is available
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

# Install lib
install (TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${LIB_INSTALL_DIR} ARCHIVE DESTINATION ${LIB_INSTALL_DIR})

# Install OpenCL headers
install (DIRECTORY "${OPENCL_DIR}/CL" DESTINATION ${INCLUDE_INSTALL_DIR})