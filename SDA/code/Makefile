#Makefile

CC=gcc
CFLAGS=-W -Wall 
CPPFLAGS += -I include 

ifeq (LISTE,$(MODE))

main: main.o fichier.o ensemble.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^
	
else

main: main_arbre.o fichier.o ensemble_arbre.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $^
	
endif
	
clean:
	rm -fr fichier.o ensemble.o ensemble_arbre.o main_arbre.o main.o main projet-sda.tar.xz image
	

