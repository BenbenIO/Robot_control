/*
 *  deplacement.c
 *  The code is used to set the displacement function (initialization, forward, backward ...)
 *
 */

#include "deplacement.h"
#include "pwm.h"
#include "gpio.h"
#include "adc.h"

//displacement function :

void initialisation (void)
{
	//Initialization motor 1:
	printf("initialisation pwm M1\n");
	set_pwm(pwm_M1, PWM_POLARITY,0);
	set_pwm(pwm_M1, PWM_RUN,1);
	set_pwm(pwm_M1, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (see config contlr)
	printf("initialisation des pin M1\n");
	set_gpio(enable_M1,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	set_gpio(sens_M1,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M1,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M1\n");
	
	//Initialization  motor 2:
	printf("initialisation pwm M2\n");
	set_pwm(pwm_M2, PWM_POLARITY,0);
	set_pwm(pwm_M2, PWM_RUN,1);
	set_pwm(pwm_M2, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (see config contlr)
	printf("initialisation des pin M2\n");
	set_gpio(enable_M2,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	set_gpio(sens_M2,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M2,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M2\n");
	
	//Initialization  motor 3:
	printf("initialisation pwm M3\n");
	set_pwm(pwm_M3, PWM_POLARITY,0);
	set_pwm(pwm_M3, PWM_RUN,1);
	set_pwm(pwm_M3, PWM_PERIOD, PERIODE_PWM);
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);  //50% --> 0A (see config contlr)
	printf("initialisation des pin M3\n");
	set_gpio(enable_M3,DIRECTION,1); // 1 = "out"
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	set_gpio(sens_M3,DIRECTION,1); // 1 = "out"
	set_gpio(sens_M3,VALUE,0); // 0 à gauche, 1 à droite
	printf("fin init M3\n");
	sleep(3);
	printf("Fin initialisaton\n\n");
}

//fonction qui se charge de déclamper les pattes avants
void clamp_AV (void)
{
	printf("Fonction clampe AVANT\n");
	int courant_M1 =0;
	int i =0;
	
	//on enable le moteur
	set_gpio(enable_M1,VALUE,1); // 1 --> enable
	
	//on alimente le moteur
	while(courant_M1 <= seuil_H)
	{
		for( i=0;i<=6;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M1 = get_adc(adc_M1);
			//printf("\nVoici le courant temporaire : %d\n",courant_M1);
			usleep(3000);
		}
		sleep(1);
		set_pwm(pwm_M1, PWM_DUTY, DUTY_AV);
		courant_M1 = get_adc(adc_M1);
		printf("\nVoici le courant : %d",courant_M1);
	}	
	
	//on eteint le moteur
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	sleep(1);
	printf("\nFin clamp AV\n\n");
}

//fonction qui se charge de clamper les pattes avants
void declamp_AV (void)
{
	printf("\nFonction declampe AVANT\n");
	int courant_M1 =0;
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M1,VALUE,1); // 1 --> enable

	//on alimente le moteur
	printf("voici seuil_B :%d\n",seuil_B);
	courant_M1 = get_adc(adc_M1);
	while(courant_M1 >= seuil_B)
	{	
		
		for( i=0;i<=5;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M1 = get_adc(adc_M1);
			//printf("\nVoici le courant temporaire : %d\n",courant_M1);
			usleep(3000);
		}
		sleep(1);
		courant_M1 = get_adc(adc_M1);
		set_pwm(pwm_M1, PWM_DUTY, DUTY_AR);
		printf("Voici le courant : %d\n",courant_M1);
	}
	//on eteint le moteur
	set_pwm(pwm_M1, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M1,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin declamp AV\n\n");
}

//fonction qui se charge de déclamper les pattes ar
void clamp_AR (void)
{
	printf("\nFonction clampe AR\n");
	int courant_M3 =0;
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M3,VALUE,1); // 1 --> enable

	//on alimente le moteur
	courant_M3 = get_adc(adc_M3);
	while(courant_M3 <= seuil_H)
	{

		for( i=0;i<=6;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M3 = get_adc(adc_M3);
			//printf("\nVoici le courant temporaire : %d\n",courant_M3);
			usleep(3000);
		}
		sleep(1);
		courant_M3 = get_adc(adc_M3);  
		set_pwm(pwm_M3, PWM_DUTY, DUTY_AV);                            
		printf("Voici le courant : %d\n",courant_M3);
	}
	//on eteint le moteur
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin clamp AR\n\n");
}

//fonction qui se charge de clamper les pattes ar
void declamp_AR (void)
{
	printf("\nFonction declampe AR\n");
	int courant_M3 =0;
	int i =0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M3,VALUE,1); // 1 --> enable
	courant_M3 = get_adc(adc_M3);
	//on alimente le moteur
	while(courant_M3 >= seuil_B)
	{
		for( i=0;i<=6;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M3 = get_adc(adc_M3);
			//printf("\nVoici le courant temporaire : %d\n",courant_M3);
			usleep(3000);
		}
		sleep(1);
		set_pwm(pwm_M3, PWM_DUTY, DUTY_AR);
		courant_M3 = get_adc(adc_M3);
		printf("Voici le courant : %d\n",courant_M3);
	}
	//on eteint le moteur
	set_pwm(pwm_M3, PWM_DUTY, DUTY_ZERO);
	sleep(1);
	//On disable le moteur:
	set_gpio(enable_M3,VALUE,0); // 1 --> enable
	printf("Fin declamp AR\n");
}

//fonction qui se charge d'allonge le segment centrale
void repli (void)
{
	printf("\nFonction repli : \n");
	float courant_M2 =0;
	int i =0;
	//on enable le moteur
	set_gpio(enable_M2,VALUE,1); // 1 --> enable
	sleep(1);
	//on alimente le moteur
	while(courant_M2 <= seuil_H)
	{
		for( i=0;i<=6;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M2 = get_adc(adc_M2);
			//printf("Voici le courant temporaire : %f\n",courant_M2);
			usleep(3000);
		}
		sleep(1);
		set_pwm(pwm_M2, PWM_DUTY, DUTY_AV);
		courant_M2 = get_adc(adc_M2);
		printf("Voici le courant : %f\n",courant_M2);
	 	
	}
	//on eteint le moteur
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	sleep(1);
	printf("Fin repl\n");
}

//fonction qui se charge de replier le segment centrale
void allong (void)
{
	printf("\nFonction  allong\n\n");
	int courant_M2 =0;
	int i = 0;
	sleep(1);
	//on enable le moteur
	set_gpio(enable_M2,VALUE,1); // 1 --> enable

	//on alimente le moteur
	courant_M2 = get_adc(adc_M2);
	//while(courant_M2 >= seuil_B)
	//{
		
	for(i=0;i<=6;i++)   //Ceci est un boucle afin de temporiser le temps de convertion
		{
			courant_M2 = get_adc(adc_M2);
			//printf("Voici le courant temporaire : %d\n",courant_M2);
			usleep(3000);
		}
				
		sleep(1);
		set_pwm(pwm_M2, PWM_DUTY, DUTY_AR);
		courant_M2 = get_adc(adc_M2);
		printf("Voici le courant : %d\n",courant_M2);
		sleep(25);
	//}
	//on eteint le moteur
	set_pwm(pwm_M2, PWM_DUTY, DUTY_ZERO);
	//On disable le moteur:
	set_gpio(enable_M2,VALUE,0); // 1 --> enable
	printf("Fin allong\n\n");
}

int avance (int nbpas)
{
	//function de déplacement avant.
	int i;
	//initialisation (ETAT);
	sleep(1);
	for(i=1;i<=nbpas;i++)
	{
		declamp_AV();
		sleep(2);
		allong();
		sleep(2);
		clamp_AV();
		sleep(2);
		declamp_AR();
		sleep(2);
		repli();
		sleep(2);
		clamp_AR();
		sleep(2);
	}
	return 0;
}

int recule(int nbpas)
{
	//function de déplacement arriere, il n'y a que l'ordre des déclamp qui change.
	int i;
	sleep(3);
	for(i=1;i<=nbpas;i++)
	{
		declamp_AR();
		sleep(2);
		allong();
		sleep(2);
		clamp_AR();
		sleep(2);
		declamp_AV();
		sleep(2);
		repli();
		sleep(2);
		clamp_AV();
		sleep(2);
	}
	return 0;
}

int repos (void)
{
	//fonction d'arret du robot
	initialisation ();
	sleep(1);
	declamp_AR();
	sleep(2);
	repli();
	sleep(2);
	declamp_AV();
	sleep(2);
	return 0;
}
	
