TEMPLATE = app
TARGET = eqntott

CONFIG -= qt

QMAKE_CFLAGS += -Wundef
#CONFIG += c11 c17 strict_c
QMAKE_CFLAGS += -std=c17
QMAKE_CFLAGS += -g

DEFINES += _POSIX_C_SOURCE=202405L
DEFINES += _XOPEN_SOURCE=800
DEFINES += "PACKAGE_STRING=\"\\\"eqntott 9.0\\\"\""

SOURCES += bnode.c
HEADERS += bnode.h
SOURCES += canon.c
HEADERS += canon.h
SOURCES += cover.c
HEADERS += cover.h
SOURCES += duple.c
HEADERS += duple.h
SOURCES += merge.c
HEADERS += merge.h
SOURCES += nt.c
HEADERS += nt.h
SOURCES += preprocess.c
HEADERS += preprocess.h
SOURCES += prexpr.c
HEADERS += prexpr.h
SOURCES += procargs.c
HEADERS += procargs.h
SOURCES += pterm.c
HEADERS += pterm.h
SOURCES += pterm_ops.c
HEADERS += pterm_ops.h
SOURCES += putpla.c
HEADERS += putpla.h
SOURCES += read_ones.c
HEADERS += read_ones.h
SOURCES += reduce.c
HEADERS += reduce.h
SOURCES += rmcvd.c
HEADERS += rmcvd.h
SOURCES += substitute.c
HEADERS += substitute.h
SOURCES += version.c
HEADERS += version.h
SOURCES += x.c
HEADERS += x.h
SOURCES += y.tab.c
HEADERS += y.tab.h
HEADERS += yyparse.h
SOURCES += yystuff.c
HEADERS += yystuff.h
