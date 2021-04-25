macro(set_sources)
	set(optionsArgs "")
	set(oneValueArgs "")
	set(multiValueArgs "SOURCEFILES" "HEADERS")
	cmake_parse_arguments(SETSOURCES "${optionsArgs}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	file(RELATIVE_PATH REL_PATH ${WORKSPACEROOT} ${CMAKE_CURRENT_SOURCE_DIR})

	# Set compilation sources
	target_sources (${PROJECT_NAME} PRIVATE ${SETSOURCES_SOURCEFILES} PUBLIC ${SETSOURCES_HEADERS})

	# Install headers
	INSTALL (FILES ${SETSOURCES_HEADERS} DESTINATION "${INCLUDE_INSTALL_DIR}/${REL_PATH}" COMPONENT Headers)

endmacro(set_sources)