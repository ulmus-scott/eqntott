
project('eqntott', 'c',
    version: '9.0',
    default_options: ['debug=true', 'optimization=3',
                      'c_std=c23',
                      'warning_level=2']
)

add_project_arguments([
    '-D_POSIX_C_SOURCE=202405L',
    '-D_XOPEN_SOURCE=800',
    '-DPACKAGE_STRING="eqntott 9.0"',
    '-Wundef'
    ], language: 'c'
)

executable('eqntott',
    'src/bnode.c',
    'src/canon.c',
    'src/cover.c',
    'src/duple.c',
    'src/merge.c',
    'src/nt.c',
    'src/preprocess.c',
    'src/prexpr.c',
    'src/procargs.c',
    'src/pterm.c',
    'src/pterm_ops.c',
    'src/putpla.c',
    'src/read_ones.c',
    'src/reduce.c',
    'src/rmcvd.c',
    'src/substitute.c',
    'src/version.c',
    'src/x.c',
    'src/y.tab.c',
    'src/yystuff.c',
    install: true,
)

install_data(['doc/eqntott.1'],
    install_dir: get_option('mandir'),
    install_tag: 'man',
)
