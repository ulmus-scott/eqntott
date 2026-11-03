/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */
#ifndef NT_H
#define NT_H

#define NINPUTS 128
#define NOUTPUTS 128
#define NPTERMS 65536
#define NTSIZE NINPUTS+NOUTPUTS

struct Nt {
	char *name;		/* variable name */
	int isinput;		/* variable used as input? */
	int isoutput;		/* variable used as output? */
	int inord;		/* index into inorder */
	int outord;		/* index into outorder */
};

extern struct Nt nts[NTSIZE];
extern struct Nt *inorder[NINPUTS];
extern struct Nt *outorder[NINPUTS];
extern int ninputs;
extern int noutputs;

void nt_init(void);
int nt_input(char *name);
int nt_output(char *name);

#endif
