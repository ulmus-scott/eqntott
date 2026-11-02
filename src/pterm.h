#ifndef PTERM_H
#define PTERM_H

typedef short BIT;

typedef struct Pterm {
	BIT *ptand;			/* AND-plane connections */
	BIT *ptor;			/* OR-plane connections */
	struct Pterm *next;		/* link to next product term */
	long andhash;			/* hash of input connection values */
	short index;			/* number of 1's in ptand */
	short cv;			/* "covered" flag */
} PTERM;

#define NIL_PTERM ((PTERM *) 0)

PTERM* copy_pterm(PTERM *pterm);
PTERM* new_pterm(PTERM *next);
PTERM* free_pterm(PTERM *pterm);

#define or3(a,b)  (a==0?b:(b==0?a:(a==1||b==1?1:2)))
#define and3(a,b) (a==1?b:(b==1?a:(a==0||b==0?0:2)))

#endif
