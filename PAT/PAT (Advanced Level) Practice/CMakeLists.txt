cmake_minimum_required (VERSION 3.10)

file( GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )
 
foreach( SOURCE IN LISTS SOURCES )
    string( SUBSTRING ${SOURCE} 0 4 PROGRAM )
    string( PREPEND PROGRAM "A")
    add_executable( ${PROGRAM} ${SOURCE} )
endforeach( SOURCE )