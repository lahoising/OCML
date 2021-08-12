cmake_minimum_required(VERSION 3.10)
project(OCML)

set(INC_PATH "include")
set(INC_DEFS_PATH "defs")

file(
	GLOB SRC_FILES
	"src/**.c"
)

file(
	GLOB INC_FILES
	"${INC_PATH}/**.h"
)

file(
	GLOB INC_DEFS_FILES
	"${INC_DEFS_PATH}/**.h"
)

add_library(
	ocml STATIC
	${SRC_FILES} ${INC_FILES}
	${INC_DEFS_FILES}
)
	
target_include_directories(
	ocml PUBLIC
	"${INC_PATH}"
)

target_include_directories(
	ocml PUBLIC 
	"${INC_DEFS_PATH}"
)

set(OCML_BUILD_EXAMPLES ON CACHE BOOL "Build OCML examples")

if(${OCML_BUILD_EXAMPLES}) 
	file(
		GLOB EXAMPLE_FILES
		"examples/**.c"
	)

	foreach(example_file ${EXAMPLE_FILES})
		get_filename_component(sample "${example_file}" NAME_WLE)
		add_executable(${sample} ${example_file})
		target_link_libraries(${sample} ocml)
	endforeach()
endif()
