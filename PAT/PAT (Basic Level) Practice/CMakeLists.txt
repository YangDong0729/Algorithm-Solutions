# file( GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp )
 
# foreach(SOURCE IN LISTS SOURCES)
#     string(SUBSTRING ${SOURCE} 0 4 PROGRAM)
#     string(PREPEND PROGRAM "PAT_B")
#     add_executable(${PROGRAM} ${SOURCE})
# endforeach(SOURCE)