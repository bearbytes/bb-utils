cmake_minimum_required( VERSION 3.20 FATAL_ERROR )

project( "Bearbytes C++ utilities" VERSION 1.0.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_EXTENSIONS ON )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

add_subdirectory( source )

enable_testing()
add_subdirectory( test )
