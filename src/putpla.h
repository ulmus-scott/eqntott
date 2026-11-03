/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */

#ifndef PUTPLA_H
#define PUTPLA_H
#include "pterm.h"

void putpla(PTERM *pts[], int npts);
void putpt(register PTERM *pt);
void putrpla(PTERM *pts[], int npts);
void putSpla(PTERM *pts[], int npts);

#endif
