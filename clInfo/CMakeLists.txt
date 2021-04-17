cmake_minimum_required (VERSION 3.8)

project (clInfo)

# Add OpenCL as a 3rd party dir
set (OPENCL_DIR "${WORKSPACEROOT}\\OpenCL-Headers")
include_directories ("${OPENCL_DIR}")

# Add clpp as a 3rd party include directories
set (BUILD_DIR "${WORKSPACEROOT}\\build")
include_directories ("${BUILD_DIR}\\includes")

# Add platform defines
if(${WIN32})
	add_definitions (-DWINDOWS_PLATFORM)
endif(${WIN32})

list (APPEND Sources "clInfo.cpp")

set (CLPP_LIB "clpp.lib")

add_executable (${PROJECT_NAME} ${Sources})
target_link_libraries (${PROJECT_NAME} ${BUILD_DIR}/lib/${CLPP_LIB})

 # Make sure c++14 is available
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)