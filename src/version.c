/*
 *
 *	Copyright (C) 1981, Regents of the University of California
 *
 *	All rights reserved
 *
 */
#include "version.h"

#include <stdio.h>
#ifndef PACKAGE_STRING
#include "config.h"
#endif

void version(void)
{
  fprintf (stderr, PACKAGE_STRING "\n");
  return;
}
