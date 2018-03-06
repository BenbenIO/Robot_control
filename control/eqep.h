/*
 *  eqep.h
 *  
 *
 *  Created by mathieu porez on 10/10/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#ifndef _EQEP_H
#define _EQEP_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* EQEP folders */
#define EQEP0 "/sys/devices/ocp.2/48300000.epwmss/48300180.eqep"
#define EQEP1 "/sys/devices/ocp.2/48302000.epwmss/48302180.eqep"
#define EQEP2 "/sys/devices/ocp.2/48304000.epwmss/48304180.eqep"

/* EQEP files */
#define POSITION "position"  
#define MODE "mode"
#define PERIOD "period"
#define ENABLED "enabled"

int get_eqep(const char * dev, const char * reg);
void set_eqep(const char * dev, const char * reg, int val);

#endif