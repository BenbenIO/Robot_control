CC = gcc
EXEC = slide
CFLAGS = -DBB_BLACK

all: clean $(EXEC)

$(EXEC):  gpio.o adc.o eqep.o pwm.o utile.o deplacement.o main.o

	$(CC) -o $(EXEC) main.o adc.o eqep.o utile.o gpio.o deplacement.o pwm.o

gpio.o:

	$(CC) -o gpio.o -c gpio.c $(CFLAGS)
	
pwm.o: 
	$(CC) -o pwm.o -c pwm.c $(CFLAGS)

adc.o:
	$(CC) -o adc.o -c adc.c $(CFLAGS)
	
eqep.o:
	$(CC) -o eqep.o -c eqep.c $(CFLAGS)
	
utile.o:
	$(CC) -o utile.o -c utile.c $(CFLAGS)
	
deplacement.o:
	$(CC) -o deplacement.o -c deplacement.c $(CFLAGS)

main.o:
	$(CC) -o main.o -c main.c $(CFLAGS)
		
clean:

	rm -rf *.o 
	rm -rf $(EXEC)
	