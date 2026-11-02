#ifndef PTERM_OPS_H
#define PTERM_OPS_H

#include "pterm.h"

int cmppt (const void *a_, const void *b_);
int cmpv (BIT *x, BIT *y, int n);
int cmpptx (const void *a_, const void *b_);
int cmppth (const void *a_, const void *b_);
PTERM *find_pterm (PTERM *pt, PTERM *pts[], int npts);
long pthash (BIT *inv, int n);
int ptindex (BIT *inv, int n);

#endif
