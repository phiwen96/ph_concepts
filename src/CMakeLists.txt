

file(GLOB_RECURSE HEADER_LIST "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB SOURCE_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_library (ph_concepts
	${SOURCE_LIST}  ${HEADER_LIST} 
)



ph_precompile (TARGET ph_concepts PRIVATE PCH ${std_pch} ${boost_pch})

add_library (ph::concepts ALIAS ph_concepts)
target_link_libraries (ph_concepts PRIVATE ${Boost_LIBRARIES})
target_include_directories (ph_concepts PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories (ph_concepts PRIVATE ${Boost_INCLUDE_DIRS})

target_compile_features (ph_concepts PUBLIC cxx_std_20)


target_include_directories(ph_concepts PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/ph_concepts>
    $<INSTALL_INTERFACE:include/ph_type_list>
)

target_include_directories(ph_concepts PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()