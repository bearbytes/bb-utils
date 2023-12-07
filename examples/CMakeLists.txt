function( add_new_example EXAMPLE_NAME )
  add_executable( ${EXAMPLE_NAME} ${EXAMPLE_NAME}.cpp )
  target_link_libraries( ${EXAMPLE_NAME} PRIVATE bb )
endfunction()

add_new_example( decoder-example )
