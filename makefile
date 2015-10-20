CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic -g

all: enigma

enigma: Main.o Rotor.o Plugboard.o Component.o
	$(CC) $(CFLAGS) Main.o Rotor.o Plugboard.o Component.o -o enigma

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

Rotor.o: Rotor.cpp
	$(CC) $(CFLAGS) -c Rotor.cpp
	
Plugboard.o: Plugboard.cpp
	$(CC) $(CFLAGS) -c Plugboard.cpp

Component.o: Component.cpp
	$(CC) $(CFLAGS) -c Component.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
