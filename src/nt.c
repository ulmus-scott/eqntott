/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */

/*
 * nt_init, nt_update, nt_input, nt_output, nt_compar, nt_open
 */
#include "nt.h"

#include <stdio.h>
#include <string.h>
#include "x.h"
#include "yystuff.h"

struct Nt nts[NTSIZE];
struct Nt *inorder[NINPUTS];
struct Nt *outorder[NINPUTS];
int ninputs = 0;
int noutputs = 0;
extern char *ego;
extern int f_flag, s_flag;

/*
 * initialize name table
 */

void nt_init(void)
{
	register struct Nt *p = nts;
	register int i = NTSIZE;

	for (; i > 0; i--, p++)
		p->name = (char *) 0;

	return;
}

int nt_compar(char *nt1, struct Nt *nt2)
{
	return (strcmp (nt1, nt2->name));
}

int nt_open(struct Nt *nt)
{
	return (!nt->name);
}


/*
 * hash, hsearch
 */

int hash(register char *s, int hshsiz)
{
	register long hash = 0;
	int retval;

	while (*s)
		hash += hash + *s++;
	if (hash < 0)
		hash = -hash;
	retval = hash % hshsiz;
	return (retval);
}

/*
 * hash search
 *	'key' is object to be found.
 *	'base' is the start of hash table.
 *	'nel' is the number of elements in the hash table.
 *	'width' is the size of a hash table entry.
 *	'compar' is passed key and a ptr into hash table,
 *		and must return 0 iff entry matches key.
 *	'open' is passed a ptr into the hash table,
 *		and must return 0 iff entry is empty.
 *	'slot' is set to point to a ptr into the hash table
 *		where the entry for key may be placed if not found,
 *		or is set to point to 0 if the table is full.
 *
 *	hash is called for first hash, linear rehash used.
 */

struct Nt* hsearch(char* key, register struct Nt *base, int nel,
                   int (*compar)(char *, struct Nt *), int (*open)(struct Nt *),
                   struct Nt **slot)
{
	register int i = hash (key, nel);
	int nnel;

	for (nnel = nel; nnel > 0; nnel--)
		if ((*open)(base+i)) {
			*slot = base+i;
			return (0);
		}
		else	if ((*compar)(key, base+i))
				i = (i+1) % (nel);
			else	return (base+i);
	return (*slot = 0);
}

/*
 * add name to name table if not present
 */

struct Nt* nt_update(char *name)
{
	struct Nt *nt, *slot;

	nt = hsearch (name, nts, NTSIZE, nt_compar, nt_open, &slot);
	if (nt)
		return (nt);

	if (!slot) {
		yyerror ("name table full");
		return ((struct Nt *) 0);
	}
	if (!(slot->name = strdup(name))) {
		yyerror ("can't store name");
		return ((struct Nt *) 0);
	}
	slot->isinput = slot->isoutput = 0;
	slot->outord = slot->inord = -1;
#ifdef DEBUG
	fprintf (stderr, "nt_update: %4d (%d)\t%s\n", 
		slot-nts, hash (name, NTSIZE), name);
#endif
	return (slot);
}

/*
 * find/add new input variable
 */

int nt_input(char *name)
{
	struct Nt *nt;

	nt = nt_update (name);
	if (!nt)
		return (-1);
	if (nt->isoutput && !(f_flag || s_flag)) {
		yyerror ("input is output");
		return (-1);
	}
	if (nt->isinput)
		return (nt->inord);
	if (ninputs >= NINPUTS) {
		yyerror ("too many inputs");
		return (-1);
	}
	inorder[ninputs] = nt;
	nt->isinput = 1;
	nt->inord = ninputs;
	return (ninputs++);
}

/*
 * find/add new output variable
 */

int nt_output(char *name)
{
	struct Nt *nt;

	nt = nt_update (name);
	if (!nt)
		return (-1);
	if (nt->isinput && !(f_flag || s_flag)) {
		yyerror ("output is input");
		return (-1);
	}
	if (nt->isoutput)
		return (nt->outord);
	if (noutputs >= NOUTPUTS) {
		yyerror ("too many outputs");
		return (-1);
	}
	outorder[noutputs] = nt;
	nt->isoutput = 1;
	nt->outord = noutputs;
	return (noutputs++);
}
