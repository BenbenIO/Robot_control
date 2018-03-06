/*
 *  utile.c
 *  Assistance function like: position calculus, TAR or currant conversion
 *
 */

#include "utile.h"
#include "eqep.h"
#include "deplacement.h"

float convertionC(float courant_M)
{
	float courant_converti ;
	courant_converti = (((courant_M-900.0)*0.4560)/1800.0);
	return courant_converti;
}

//fonction de mise en buté du moteur M2 pour mettre la pisition a zeros:
void misezero(void)
{
	printf("fonction mise a zero\n");
	repli();
	set_eqep(EQEP2, POSITION, 0);
}

float distance(void)
{
	int nbtour;
	float position;
	nbtour = ((get_eqep(EQEP2, POSITION)/4)+C);    //Experimental verified law
	position = ((nbtour/455)*p);                   //455 : reduction 
	return position;
}

