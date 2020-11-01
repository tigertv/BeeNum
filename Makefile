.PHONY: clean

CXX = g++ 
OPTS = -std=c++17 -Wall -Wextra -masm=intel
SRC = $(wildcard *.cpp) 
OBJ=$(SRC:.cpp=.o)

all: main

main: $(OBJ) 
	$(CXX) $(FLAGS) $(OBJ) -o main
%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@ 
clean: 
	rm -rf main *.o
