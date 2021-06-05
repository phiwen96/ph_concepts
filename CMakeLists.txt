cmake_minimum_required (VERSION 3.19.4)

project (
	ph_concepts
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX
)	
set (_Darwin 0)
set (_Linux 0)
set (_Windows 0)

enable_language(ASM_NASM)


set (_Processor -1)

if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")
    set (_Processor 0)
elseif (${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm64")
	set (_Processor 1)
else ()
    message (FATAL_ERROR "unknown processor")
endif ()

set (_System -1)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
# message("Darwin")
    set (_System 0)
    # add_compile_definitions (Darwin)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set (_System 1)
    # add_compile_definitions (Linux)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message (FATAL_ERROR "not yet defined for Windows")

    set (_System 2)
    # add_compile_definitions (Windows)
else ()
    message (FATAL_ERROR "unknown system ${CMAKE_SYSTEM_NAME}")
endif ()

add_subdirectory (cmake/phake)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	
	# Let's ensure -std=g++xx instead of -std=c++xx
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)
	set (CMAKE_CXX_EXTENSIONS ON)

	# Let's nicely support folders in IDEs
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)

	find_package (Boost 1.75 REQUIRED)


	# Testing only available if this is the main app
	# Note this needs to be done in the main CMakeLists
	# since it calls enable_testing, which must be in the
	# main CMakeLists.
	include (CTest)



   # Docs only available if this is the main app
   	# find_package (Doxygen)

	# if (Doxygen_FOUND)
	# 	add_subdirectory (docs)
   	# else()
    #  		message(STATUS "Doxygen not found, not building docs")
   	# endif()


endif()

find_package (Boost 1.74 REQUIRED)

add_subdirectory (src)


# if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
	add_subdirectory (tests)
# endif()