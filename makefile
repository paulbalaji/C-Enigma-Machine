CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic -g

all: enigma

enigma: Main.o Rotor.o
	$(CC) $(CFLAGS) Main.o Rotor.o -o enigma

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

Rotor.o: Rotor.cpp
	$(CC) $(CFLAGS) -c Rotor.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
