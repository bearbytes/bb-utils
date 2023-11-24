add_library( bb INTERFACE )

target_include_directories( bb INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources( bb INTERFACE
    FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} FILES
    bb/array.h
    bb/basic-types-limits.h
    bb/basic-types-utils.h
    bb/basic-types.h
    bb/byte-utils.h
    bb/byte.h
    bb/clamped.h
    bb/constexpr-utils.h
    bb/span.h
)

install( TARGETS bb
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
