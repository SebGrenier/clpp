cmake_minimum_required (VERSION 3.8)

project (clpp)

# Add 3rd party include directories
set (3RDPARTY_DIR "${WORKSPACEROOT}\\3rdParty")
include_directories ("${3RDPARTY_DIR}\\include")

# Add platform defines
if(${WIN32})
	add_definitions (-DWINDOWS_PLATFORM)
endif(${WIN32})

add_library (${PROJECT_NAME} "")

target_sources (${PROJECT_NAME}
PRIVATE
	"clpp.cpp"
	"clApi.cpp"
	"clUtilities.cpp"
PUBLIC
	"clpp.hpp"
	"clApi.hpp"
	"clFunction.hpp"
	"clUtilities.hpp"
)

# Include subdirectories
add_subdirectory ("libImport")

 # Make sure c++14 is available
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

install (TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

# Install Headers
install(DIRECTORY "" DESTINATION includes FILES_MATCHING PATTERN "*.hpp")