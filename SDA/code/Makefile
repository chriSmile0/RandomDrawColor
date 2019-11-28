#Makefile

CC=gcc
CFLAGS=-W -Wall 
CPPFLAGS += -I include 

main: main.o fichier.o ensemble.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^
	
clean:
	rm -fr fichier.o ensemble.o main.o main projet-sda.tar.xz
	
dist: 
	tar cvfj projet-sda.tar.xz ensemble.c ensemble.h fichier.c fichier.h main.c Makefile
