function( add_new_example EXAMPLE_NAME )
  add_executable( ${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp )
  target_link_libraries( ${EXAMPLE_NAME} PRIVATE bb )
  target_include_directories( ${EXAMPLE_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../source )
endfunction()

add_new_example( decoder-example )
