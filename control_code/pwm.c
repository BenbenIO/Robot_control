/*
 *  pwm.c
 *  
 *
 *  Created by mathieu porez on 10/10/13.
 *  Copyright 2013 emn. All rights reserved.
 *
 */

#include "pwm.h"

void set_pwm(const char * dev, const char * reg, unsigned int val)
{
	static int fd, len;
	static char buff[64];
	static char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fd = open(file,O_RDWR);
	len = sprintf(buff,"%d",val);
	write(fd,buff,len);
	close(fd); 

}

int get_pwm(const char * dev, const char * reg)
{
	static int val;
	FILE* fp;
	static char file[64];
	sprintf(file,"%s/%s",dev,reg);
	fp = fopen(file, "r");
	fscanf(fp, "%d", &val);
	fclose (fp);
	return val;
}
