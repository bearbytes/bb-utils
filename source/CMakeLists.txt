configure_file( bb/version.h.in bb/version.h )

add_library( bb INTERFACE )

target_include_directories( bb INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_sources( bb INTERFACE
    FILE_SET HEADERS BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} FILES
    bb/array.h
    bb/assert.h
    bb/basic-types-limits.h
    bb/basic-types-utils.h
    bb/basic-types.h
    bb/byte-utils.h
    bb/byte.h
    bb/callable.h
    bb/casting-utils.h
    bb/constexpr-utils.h
    bb/duration.h
    bb/new.h
    bb/noexcept-utils.h
    bb/on-scope-exit.h
    bb/optional.h
    bb/restricted.h
    bb/span.h
    bb/temperature.h
    bb/type-utils.h
    bb/variant.h
)

include( GNUInstallDirs )

install(
    TARGETS bb
    FILE_SET HEADERS
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/bb/version.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/bb
)
