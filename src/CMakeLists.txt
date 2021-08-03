



file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/../include/${CMAKE_PROJECT_NAME}/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "*.cpp")


Create_cpp_files (

	FILES 
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

	INCLUDE_DIR
		"../include/${CMAKE_PROJECT_NAME}"

	SRC_DIR
		"${CMAKE_CURRENT_LIST_DIR}"
)



foreach (file IN LISTS ${HEADER_LIST})
message(${file})
message("kuk")
	# set_target_properties(${file}          PROPERTIES FOLDER "${PROJECT_NAME}/include/kuk${name}")
endforeach ()


add_library (ph_concepts
	${SOURCE_LIST}  ${HEADER_LIST} 
)




target_compile_definitions (${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:DEBUG> $<$<CONFIG:RELEASE>:RELEASE>")


# target_sources (ph_concepts PRIVATE in/platform.hpp)
set (self ${PROJECT_NAME})

set_target_properties (${self} PROPERTIES CXX_STANDARD 20)
target_compile_features (${self} PUBLIC cxx_std_20)

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
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "main")
else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies")
endif()

IDE()