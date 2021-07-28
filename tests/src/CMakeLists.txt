# Testing library
set (${self} test_${PROJECT_NAME})
# ph_fetch (catch2)

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
	add_executable (test_${name} testlib.cpp test_${name}.cpp ${HEADER_LIST})
	target_link_libraries (test_${name} PRIVATE ph::concepts ${PROJECT_NAME} Catch2::Catch2)
	target_include_directories (test_${name} PRIVATE ph::concepts ../include)
	ph_precompile (TARGET test_${name} PRIVATE PCH ${std_pch})

	if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
		set_target_properties(test_${name}          PROPERTIES FOLDER "${PROJECT_NAME}")
	else ()
		set_target_properties(test_${name}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
	endif()		
endmacro ()


# add_executable (test_${PROJECT_NAME}_sequence testlib.cpp test_sequence.cpp ${HEADER_LIST})
# add_executable (test_${PROJECT_NAME}_algorithms testlib.cpp test_algorithms.cpp ${HEADER_LIST})


ph_add_test (concepts)
ph_add_test (uni)
ph_add_test (vari)
ph_add_test (typelist)
ph_add_test (typetraits)
ph_add_test (Arithmetic)
ph_add_test (Array)
ph_add_test (Bool)
ph_add_test (Char)
ph_add_test (Floating)
ph_add_test (Function)
ph_add_test (Fundamental)
ph_add_test (Integer)
ph_add_test (Iterator)
ph_add_test (Number)
ph_add_test (Pointer)
ph_add_test (Range)
ph_add_test (Reference)
ph_add_test (Signed)
ph_add_test (Size)
ph_add_test (Unsigned)








# target_link_libraries (test_${PROJECT_NAME}_algorithms PRIVATE ${PROJECT_NAME} Catch2::Catch2 ph::color)
# target_include_directories (test_${PROJECT_NAME}_algorithms PRIVATE include ph::color)
# ph_precompile (TARGET test_${PROJECT_NAME}_algorithms PRIVATE PCH ${std_pch})

# target_link_libraries (test_${PROJECT_NAME}_sequence PRIVATE ${PROJECT_NAME} Catch2::Catch2 ph::color)
# target_include_directories (test_${PROJECT_NAME}_sequence PRIVATE include ph::color)
# ph_precompile (TARGET test_${PROJECT_NAME}_sequence PRIVATE PCH ${std_pch})

# add_test (NAME testtest_${PROJECT_NAME} COMMAND ${self}) 


# if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#     set_target_properties(test_${PROJECT_NAME}_sequence          PROPERTIES FOLDER "${PROJECT_NAME}")
#     set_target_properties(test_${PROJECT_NAME}_algorithms          PROPERTIES FOLDER "${PROJECT_NAME}")

# else()
#     set_target_properties(test_${PROJECT_NAME}_sequence           PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
#     set_target_properties(test_${PROJECT_NAME}_algorithms          PROPERTIES FOLDER "${PROJECT_NAME}")

# endif()



