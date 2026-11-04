/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */

#ifndef PREXPR_H
#define PREXPR_H

#include "bnode.h"

#define INPUT 1			/* code to decide what to print in prgexpr */
#define OUTPUT 2
#define INTERNAL 3

void prexpr(BNODE *exp);
void prlexpr(BNODE *exp);
void prgexpr(BNODE *exp, int node, int kind);

#endif
