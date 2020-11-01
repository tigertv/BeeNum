CC = g++
OPTS = -std=c++17 -Wall -Wextra -masm=intel

all: main.o 
	$(CC) $(OPTS) main.o -o main
main.o: main.cpp
	$(CC) $(OPTS) -c main.cpp -o main.o
clean:
	rm -f main *.o 
