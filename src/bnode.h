/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */

#ifndef BNODE_H
#define BNODE_H

#define AND -1
#define OR -2
#define NOT -3
#define ONE -4
#define ZERO -5
#define DONTCARE -6
#define NAND -7
#define NOR -8

typedef struct Btreenode {
	int value;			/* operator name or leaf value */
	struct Btreenode *left;		/* link to left subtree */
	struct Btreenode *right;	/* link to right subtree */
#ifdef DEBUG
	int mark;
#endif
} BNODE;

#define NIL_BNODE ((BNODE *) 0)

BNODE *new_bnode(int value, BNODE *left, BNODE *right);
void free_bnode(BNODE *bnode);
BNODE* copy_bnode(BNODE *old);

#endif
