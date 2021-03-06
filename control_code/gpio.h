/*
 *  gpio.h
 *  
 *
 *  Created by mathieu porez on 10/10/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Devices */
#define GPIO_31 "/sys/class/gpio/gpio31/"
#define GPIO_30 "/sys/class/gpio/gpio30/"
#define GPIO_47 "/sys/class/gpio/gpio47/"
#define GPIO_27 "/sys/class/gpio/gpio27/"
#define GPIO_117 "/sys/class/gpio/gpio117/"
#define GPIO_49 "/sys/class/gpio/gpio49/"

/* Registers */
#define ACTIVE_LOW "active_low"
#define DIRECTION "direction"
#define EDGE "edge"
#define VALUE "value"
#define GPIO_IN "in"
#define GPIO_OUT "out"

void set_gpio(const char * dev, const char * reg, int val);
int get_gpio(const char * dev, const char * reg);

#endif
