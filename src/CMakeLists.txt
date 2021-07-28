



set (include_dir "${CMAKE_CURRENT_LIST_DIR}/../include/ph_concepts")
set (src_dir "${CMAKE_CURRENT_LIST_DIR}")

ph_create_modules (

	MODULES 
		"concepts"
		"common"
		"Floating"
		"Integer"
		"Signed"
		"Unsigned"
		"Number"
		"Char"
		"Iterator"
		"Range"
		"String"
		"Integral"
		"Arithmetic"
		"Fundamental"
		"Void"
		"Pointer"
		"Size"
		"Function"
		"Reference"
		"Array"
		"uni"

	INCLUDE
		"${include_dir}"

	SRC 
		"${src_dir}"
)

file(GLOB_RECURSE HEADER_LIST "${include_dir}/*.hpp")
file(GLOB SOURCE_LIST "${src_dir}/*.cpp")

add_library (ph_concepts
	${SOURCE_LIST}  ${HEADER_LIST} 
)

target_compile_definitions (${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:DEBUG> $<$<CONFIG:RELEASE>:RELEASE>")


# target_sources (ph_concepts PRIVATE in/platform.hpp)
set (self ${PROJECT_NAME})

set_target_properties (${self} PROPERTIES CXX_STANDARD 20)
target_compile_features (${self} PUBLIC cxx_std_20)

# file (GLOB CONFIGS ${PROJECT_SOURCE_DIR}/src/in/*.hpp)
# foreach (file ${CONFIGS})
# 	get_filename_component (name ${file} NAME)
# 	# message ("hej ${file}")
# 	configure_file (${file} ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/${name} @ONLY)
# endforeach ()
# add_custom_command(
#     OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/custom_header.h
#     COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/custom_header.h.in ${CMAKE_CURRENT_BINARY_DIR}/custom_header.h
#     DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/custom_header.h.in
# )

# add_custom_target(
#     custom_header_target
#     DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/custom_header.h
# )
ph_precompile (TARGET ph_concepts PRIVATE PCH ${std_pch})

add_library (ph::concepts ALIAS ph_concepts)
# target_link_libraries (ph_concepts PRIVATE ${Boost_LIBRARIES})
target_include_directories (ph_concepts PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_include_directories (ph_concepts PRIVATE ${Boost_INCLUDE_DIRS})

target_compile_features (ph_concepts PUBLIC cxx_std_20)

# target_compile_options(ph_concepts PUBLIC "-ast-dump  -fsyntax-only")


target_include_directories(ph_concepts PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../include/ph_concepts>
    $<INSTALL_INTERFACE:include/ph_concepts>
)

target_include_directories(ph_concepts PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies")
endif()