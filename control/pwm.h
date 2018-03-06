/*
 *  pwm.h
 *  
 *
 *  Created by mathieu porez on 10/10/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#ifndef _PWM_H
#define _PWM_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Device */ 
//on definie les devices, pour les pin pwm choisies: 
#define EHRPWM1A "/sys/devices/ocp.2/pwm_test_P9_14.10"
#define EHRPWM2B "/sys/devices/ocp.2/pwm_test_P8_13.11"
#define EHRPWM0A "/sys/devices/ocp.2/pwm_test_P9_31.12"

/* Registers */
#define PWM_DUTY "duty"
#define PWM_PERIOD "period"
#define PWM_POLARITY "polarity"
#define PWM_POWER "power"
#define PWM_RUN "run"

void set_pwm(const char * dev, const char * reg, unsigned int val);
int get_pwm(const char * dev, const char * reg);

#endif

