cmake_minimum_required( VERSION 3.23 FATAL_ERROR )

project( "Bearbytes C++ utilities" VERSION 1.0.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_EXTENSIONS ON )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_CXX_COMPILER "clang++" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fno-rtti -fno-exceptions -fno-unwind-tables -m64" )
set( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi" )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_subdirectory( source )
add_subdirectory( examples )

enable_testing()
add_subdirectory( test )
