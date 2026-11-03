/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */

#ifndef __X_H
#define __X_H

#include <stdlib.h>

#define MAXSTR 512

#define NSUBSTITUTE 10

#define AND -1
#define OR -2
#define NOT -3
#define ONE -4
#define ZERO -5
#define DONTCARE -6
#define NAND -7
#define NOR -8

#define MIN_OUTPUT 512		/* inputs start at 0, outputs at 512 */
#define MIN_GNODE 1024		/* and internal nodes at 1024 */

typedef struct Btreenode {
	int value;			/* operator name or leaf value */
	struct Btreenode *left;		/* link to left subtree */
	struct Btreenode *right;	/* link to right subtree */
#ifdef DEBUG
	int mark;
#endif
} BNODE;

#define NIL_BNODE ((BNODE *) 0)

#define LINELEN 70

BNODE *new_bnode(int value, BNODE *left, BNODE *right);
void free_bnode(BNODE *bnode);

#endif
