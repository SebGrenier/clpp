cmake_minimum_required (VERSION 3.8)

project (clUtils)

# Add 3rd party include directories
set (3RDPARTY_DIR "${WORKSPACEROOT}\\3rdParty")
include_directories ("${3RDPARTY_DIR}\\include")

# Add platform defines
if(${WIN32})
	add_definitions (-DWINDOWS_PLATFORM)
endif(${WIN32})

list (APPEND Sources "clUtils.cpp")

# Include subdirectories
add_subdirectory ("libImport")

add_library (${PROJECT_NAME} ${Sources})

 # Make sure c++14 is available
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

install (TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)