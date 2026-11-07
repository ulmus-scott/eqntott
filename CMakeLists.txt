cmake_minimum_required(VERSION 3.24)

project(
    eqntott
    VERSION 9.0
    LANGUAGES C
    )

include(GNUInstallDirs)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_COLOR_DIAGNOSTICS ON)

add_executable(
    eqntott
    src/bnode.c
    src/bnode.h
    src/canon.c
    src/canon.h
    src/cover.c
    src/cover.h
    src/duple.c
    src/duple.h
    src/merge.c
    src/merge.h
    src/nt.c
    src/nt.h
    src/preprocess.c
    src/preprocess.h
    src/prexpr.c
    src/prexpr.h
    src/procargs.c
    src/procargs.h
    src/pterm.c
    src/pterm.h
    src/pterm_ops.c
    src/pterm_ops.h
    src/putpla.c
    src/putpla.h
    src/read_ones.c
    src/read_ones.h
    src/reduce.c
    src/reduce.h
    src/rmcvd.c
    src/rmcvd.h
    src/substitute.c
    src/substitute.h
    src/version.c
    src/version.h
    src/x.c
    src/x.h
    src/y.tab.c
    src/y.tab.h
    src/yyparse.h
    src/yystuff.c
    src/yystuff.h
    )

target_compile_definitions(eqntott PRIVATE
    _POSIX_C_SOURCE=202405L
    _XOPEN_SOURCE=800
    PACKAGE_STRING="eqntott 9.0"
    )

target_compile_options(eqntott PRIVATE -g -O3 -Wall -Wextra -Wundef)

install(TARGETS eqntott RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(FILES doc/eqntott.1 DESTINATION ${CMAKE_INSTALL_MANDIR})
