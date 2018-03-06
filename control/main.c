/*
 *  main.c
 *  The code is used to run the robot forward inside the tunnel 
 *
 */

#include <stdio.h>

#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "deplacement.h"
#include "eqep.h"
#include "utile.h"


int main (int argc, char ** argv)
{
	printf("debut du programme\n\n");
	int position;
	float positionmm;
	
	initialisation();
	
	printf("attention mise a zero, le moteur va en butée, faire attention que cela ne tourne pas !\n");
	misezero();
	position = get_eqep(EQEP2, POSITION);
	printf("voici la position BBB  a t = 0 : %d\n",position);
	sleep(3);
	printf("deplacement pendant 40 s allong :\n");
	//on enable le moteur
	set_gpio(enable_M2,VALUE,1); // 1 --> enable
	set_pwm(pwm_M2, PWM_DUTY, DUTY_AR);
	sleep(40);
	//on eteint le moteur
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	
	position = get_eqep(EQEP2, POSITION);
	printf("voici la position BBB a t = 40 : %d\n",position);
	
	positionmm=distance();
	printf("voici la distance parcourue : %f mm\n",positionmm);
	printf("maintenant on mesure à la regle!\n");
	

	printf("\nfin programme\n");
	
	return 0;
}
