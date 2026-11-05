/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */
#include "substitute.h"

/*
 * substitute
 */

#include "bnode.h"
#include "nt.h"
#include "x.h"

extern BNODE *exprs[];
extern struct Nt *inorder[];

int substitute (BNODE* exp, BNODE** new_exp)
{
	int changed = 0;

	switch (exp->value) {
	case AND:
	case OR:
		changed =
			substitute (exp->left, &exp->left) +
			substitute (exp->right, &exp->right);
		*new_exp = exp;
		return (changed);

	case NOT:
		changed = substitute (exp->left, &exp->left);
		*new_exp = exp;
		return (changed);

	case ZERO:
	case ONE:
	case DONTCARE:
		*new_exp = exp;
		return (changed);

	default:
		/* must be input or output */
		if (inorder[exp->value]->isoutput) {
			changed = 1;
			*new_exp = copy_bnode
				(exprs[inorder[exp->value]->outord]);
		}
		else {
			changed = 0;
			*new_exp = exp;
		}
		return (changed);
	}
}
