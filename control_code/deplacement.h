/*
 *  deplacement.h
 *  
 *
 */

#ifndef _DEPLACEMENT_H
#define _DEPLACEMENT_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pwm.h"
#include "gpio.h"
#include "adc.h"

//define des noms de pin:
//Pour le motor 1 :
#define pwm_M1 EHRPWM1A
#define enable_M1 GPIO_31
#define sens_M1 GPIO_30
#define adc_M1 AIN4
//Pour le motor 2 :
#define pwm_M2 EHRPWM2B
#define enable_M2 GPIO_47
#define sens_M2 GPIO_27
#define adc_M2 AIN6
//Pour le motor 2 :
#define pwm_M3 EHRPWM0A
#define enable_M3 GPIO_117
#define sens_M3 GPIO_49
#define adc_M3 AIN2

//Variable PWM:
#define PERIODE_PWM 500000    //Period (500 micros) --> 2KHz
#define DUTY_ZERO 250000     //Duty pour 50% --> 0 A (see config contrl)
#define DUTY_AV 400000       //Duty pour 80% --> 13000 tr/min
#define DUTY_AR 100000      //Duty pour 20% --> 13000 tr/min

//Autres variable
#define seuil_B 520
#define seuil_H 1200

void initialisation (void);

void declamp_AV (void);
void clamp_AV (void);

void declamp_AR (void);
void clamp_AR (void);

void allong (void);
void repli (void);

int avance (int nbpas);
int recule (int nbpas);
int repos (void);

#endif
