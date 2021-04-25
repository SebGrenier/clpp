cmake_minimum_required (VERSION 3.8)

project (CLInfo)

# Add clpp as a 3rd party include directories
set (BUILD_DIR "${WORKSPACEROOT}/build")
include_directories ("${WORKSPACEROOT}/include")

# Add platform defines
if(${WIN32})
	add_definitions (-DWINDOWS_PLATFORM)
endif(${WIN32})

list (APPEND Sources "CLInfo.cpp")

set (CLPP_LIB "CLpp.lib")

add_executable (${PROJECT_NAME} ${Sources})
target_link_libraries (${PROJECT_NAME} ${WORKSPACEROOT}/lib/${CLPP_LIB})

 # Make sure c++14 is available
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${WORKSPACEROOT}/bin")