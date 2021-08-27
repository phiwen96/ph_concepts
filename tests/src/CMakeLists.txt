set (${self} test_${PROJECT_NAME})

if (NOT TARGET Catch2)
	include (FetchContent)

	FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v2.13.1)

	FetchContent_MakeAvailable (Catch2)
endif ()


file(GLOB_RECURSE HEADER_LIST "include/*.hpp")
file(GLOB SOURCE_LIST *.cpp)


# set (deps )
macro (ph_add_test name)
	add_executable (test_${name} ${SOURCE_LIST} ${HEADER_LIST})
	# set_target_properties(test_${name}          PROPERTIES FOLDER "main/${PROJECT_NAME}/tests")
	# source_group (bajs//kiss test_${name}.cpp)
	source_group(TREE ${CMAKE_CURRENT_LIST_DIR}
            PREFIX "sources"               
            FILES  test_${name}.cpp
        )
	# set_target_properties(test_${name} PROPERTIES PROJECT_LABEL "test_${name}Foo Tastic")
	target_link_libraries (test_${name} PRIVATE ph::concepts ${PROJECT_NAME} Catch2::Catch2)
	target_include_directories (test_${name} PRIVATE ph::concepts ../include)
	ph_precompile (TARGET test_${name} PRIVATE PCH ${std_pch})

	if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
		set_target_properties(test_${name}          PROPERTIES FOLDER "main/${PROJECT_NAME}/tests")
	else ()
		set_target_properties(test_${name}          PROPERTIES FOLDER "dependencies/tests/${PROJECT_NAME}")
	endif()		
endmacro ()

# Create_cpp_tests (
# 	TARGETS 
# 		"concepts"
# 		"uni"
# 		"vari"
# 		"typelist"
# )

ph_add_test (concepts)
# ph_add_test (uni)
# ph_add_test (vari)
# ph_add_test (typelist)
# ph_add_test (typetraits)
# ph_add_test (Arithmetic)
# ph_add_test (Array)
# ph_add_test (Bool)
# ph_add_test (Char)
# ph_add_test (Floating)
# ph_add_test (Function)
# ph_add_test (Fundamental)
# ph_add_test (Integer)
# ph_add_test (Iterator)
# ph_add_test (Number)
# ph_add_test (Pointer)
# ph_add_test (Range)
# ph_add_test (Reference)
# ph_add_test (Signed)
# ph_add_test (Size)
# ph_add_test (Unsigned)
# ph_add_test (String)
