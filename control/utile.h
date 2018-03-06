/*
 *  utile.h
 *	HEARDER	for the assistance function
 */

#ifndef _UTILE_H
#define _UTILE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "eqep.h"

#define C 0		//constant between position cBBB and nb tour
#define p 2   //Step in mm

float convertionC(float courant_M);
void misezero(void);
float distance(void);

#endif