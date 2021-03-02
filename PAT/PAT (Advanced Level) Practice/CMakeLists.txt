cmake_minimum_required (VERSION 3.8)

file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )
 
foreach( sourcefile IN LISTS APP_SOURCES )
    string( REPLACE ".cpp" "" program ${sourcefile} )
    add_executable( ${program} ${sourcefile} )
endforeach( sourcefile )