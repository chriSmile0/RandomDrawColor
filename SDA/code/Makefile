#Makefile

CC=gcc
CFLAGS=-W -Wall 
CPPFLAGS += -I include 

ifeq (ARBRE,$(MODE))

main: main_arbre.o fichier.o ensemble_arbre.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^
	
else

main: main.o fichier.o ensemble.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^
	
endif
	
clean:
	rm -fr fichier.o ensemble.o ensemble_arbre.o main_arbre.o main.o main projet-sda.tar.xz image
	
dist: 
	tar cvfj projet-sda.tar.xz ensemble.c ensemble.h fichier.c fichier.h main.c Makefile
