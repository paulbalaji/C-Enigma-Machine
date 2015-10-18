CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic

all: enigma

enigma: Main.o
	$(CC) $(CFLAGS) -o enigma Main.o

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
