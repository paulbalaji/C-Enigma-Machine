CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic -g

all: enigma

enigma: Main.o Rotor.o Plugboard.o Reflector.o Component.o
	$(CC) $(CFLAGS) Main.o Rotor.o Plugboard.o Reflector.o Component.o -o enigma

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

Rotor.o: Rotor.cpp Rotor.h
	$(CC) $(CFLAGS) -c Rotor.cpp
	
Plugboard.o: Plugboard.cpp Plugboard.h
	$(CC) $(CFLAGS) -c Plugboard.cpp

Reflector.o: Reflector.cpp Reflector.h
	$(CC) $(CFLAGS) -c Reflector.cpp

Component.o: Component.cpp Component.h
	$(CC) $(CFLAGS) -c Component.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
