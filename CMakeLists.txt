cmake_minimum_required (VERSION 3.20)

file (TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if (EXISTS "${LOC_PATH}")
    message (FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif ()

get_filename_component (self ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project (
	${self}
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX
)	

unset (self)

# set(GLFW_BUILD_EXAMPLES OFF)
# set(GLFW_BUILD_TESTS OFF)
# set(GLFW_BUILD_DOCS OFF)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	enable_testing()
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)
	set (CMAKE_CXX_EXTENSIONS ON)
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)
endif()


if (NOT TARGET ph_cmake)
	include (FetchContent)
	FetchContent_Declare(
  		ph_cmake
  		GIT_REPOSITORY https://github.com/phiwen96/ph_cmake.git
  		GIT_TAG        0.0.0)

	FetchContent_GetProperties (ph_cmake)
	
	if (NOT ph_cmake_POPULATED)
  		FetchContent_Populate (ph_cmake)
  		add_subdirectory (${ph_cmake_SOURCE_DIR} ${ph_cmake_BINARY_DIR})
	endif ()
endif ()

# Fetch (TARGETS ph_concepts) #ph_file ph_optional ph_proxy)


 


# if (NOT TARGET ph_concepts)
# 	include (FetchContent)
# 	FetchContent_Declare(
#   		ph_concepts
#   		GIT_REPOSITORY https://github.com/phiwen96/ph_concepts.git
#   		GIT_TAG        v0.0.0)

# 	FetchContent_GetProperties (ph_concepts)
	
# 	if (NOT ph_concepts_POPULATED)
#   		FetchContent_Populate (ph_concepts)
#   		add_subdirectory (${ph_concepts_SOURCE_DIR} ${ph_concepts_BINARY_DIR})
# 	endif ()
# endif ()

# if (NOT TARGET ph_optional)
# 	include (FetchContent)
# 	FetchContent_Declare(
#   		ph_optional
#   		GIT_REPOSITORY https://github.com/phiwen96/ph_optional.git
#   		GIT_TAG        v0.0.0)

# 	FetchContent_GetProperties (ph_optional)
	
# 	if (NOT ph_optional_POPULATED)
#   		FetchContent_Populate (ph_optional)
#   		add_subdirectory (${ph_optional_SOURCE_DIR} ${ph_optional_BINARY_DIR})
# 	endif ()
# endif ()

# if (NOT TARGET ph_proxy)
# 	include (FetchContent)
# 	FetchContent_Declare(
#   		ph_proxy
#   		GIT_REPOSITORY https://github.com/phiwen96/ph_proxy.git
#   		GIT_TAG        v0.0.0)

# 	FetchContent_GetProperties (ph_proxy)
	
# 	if (NOT ph_proxy_POPULATED)
#   		FetchContent_Populate (ph_proxy)
#   		add_subdirectory (${ph_proxy_SOURCE_DIR} ${ph_proxy_BINARY_DIR})
# 	endif ()
# endif ()






# find_package(Vulkan REQUIRED)


# FetchContent_Declare(glfw
#   GIT_REPOSITORY https://github.com/glfw/glfw.git
#   INSTALL_COMMAND ""
#   )

# FetchContent_GetProperties(glfw)
# if(NOT glfw_POPULATED)
#   FetchContent_Populate(glfw)
#   add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()







# FetchContent_Declare(glm
#   GIT_REPOSITORY https://github.com/g-truc/glm.git
#   INSTALL_COMMAND ""
#   )

# FetchContent_GetProperties(glm)
# if(NOT glm_POPULATED)
#   FetchContent_Populate(glm)
#   add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()




add_subdirectory (src)

# add_subdirectory (applications)

# add_subdirectory (docs)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
# add_subdirectory (tests)
# # include(CMakePrintHelpers)
# 	# cmake_print_variables (lib CMAKE_VERSION)
# 	# cmake_print_properties(TARGETS ${CMAKE_PROJECT_NAME} PROPERTIES TYPE ALIASED_TARGET)
# 	add_subdirectory (tests)
endif()


# if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR ${CMAKE_PROJECT_NAME}_BUILD_TESTING) AND BUILD_TESTING)
	add_subdirectory (tests)
# endif()

