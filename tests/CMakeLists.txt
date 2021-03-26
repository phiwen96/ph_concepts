# Testing library
ph_fetch (catch2)
file(GLOB SOURCE_LIST *.cpp)
add_executable (test_ph_concepts ${SOURCE_LIST})
target_link_libraries (test_ph_concepts PRIVATE ph_concepts Catch2::Catch2)
ph_precompile (TARGET test_ph_concepts PRIVATE PCH ${std_pch})
add_test (NAME testlibtest COMMAND testlib) 
 






