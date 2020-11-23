.PHONY: clean fast

CXX = g++ 
OPTS = -std=c++17 -Wall -Wextra -masm=intel 
SRC = $(wildcard *.cpp) 
BINT = $(wildcard Bint/*.cpp) 
OBJ=$(SRC:.cpp=.o)
OBJF=$(SRC:.cpp=.fast.o)

all: main 

fast: main-fast

main: $(OBJ) 
	$(CXX) $(OPTS) $(OBJ) -o $@
main-fast: $(OBJF) 
	$(CXX) $(OPTS) -Ofast $(OBJF) -o $@ 
Bint.o: Bint.cpp $(BINT)
	$(CXX) $(OPTS) -c $< -o $@ 
%.o: %.cpp
	$(CXX) $(OPTS) -c $< -o $@ 
%.fast.o: %.cpp
	$(CXX) $(OPTS) -Ofast -c $< -o $@ 

clean: 
	rm -rf main main-fast *.o
