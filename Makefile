.PHONY: clean

CXX = g++ 
OPTS = -std=c++17 -Wall -Wextra -masm=intel 
SRC = $(wildcard *.cpp) 
OBJ=$(SRC:.cpp=.o)
OBJF=$(SRC:.cpp=.fast.o)

all: main 

main: $(OBJ) 
	$(CXX) $(OPTS) $(OBJ) -o $@
main-fast: $(OBJF) 
	$(CXX) $(OPTS) -Ofast $(OBJF) -o $@ 
%.o: %.cpp
	$(CXX) $(OPTS) -c $< -o $@ 
%.fast.o: %.cpp
	$(CXX) $(OPTS) -Ofast -c $< -o $@ 

clean: 
	rm -rf main main-fast *.o
