/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */
#include "version.h"

#include <stdio.h>
#include "config.h"

void version(void)
{
  fprintf (stderr, PACKAGE_STRING "\n");
  return;
}
