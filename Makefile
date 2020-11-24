.PHONY: all clean fast test run-test

CXX = g++ 
OPTS = -std=c++17 -Wall -Wextra -masm=intel 
SRC = $(wildcard *.cpp) 
BINT = $(wildcard Bint/*.cpp) 

TSRC = $(wildcard tests/*.cpp) 
TST = $(notdir $(TSRC))
TST := $(TST:.cpp=)
TSTDIR = tests
TSTS = $(addprefix test-,$(TST))

OBJ=$(SRC:.cpp=.o)
OBJF=$(SRC:.cpp=.fast.o)


all: main 

fast: main-fast

test: $(TSTS)

run-test: test
	for f in $(TSTS); do \
		./$$f; \
	done;

main: $(OBJ) 
	$(CXX) $(OPTS) $(OBJ) -o $@
main-fast: $(OBJF) 
	$(CXX) $(OPTS) -Ofast $(OBJF) -o $@ 
Bint.o: Bint.cpp $(BINT)
	$(CXX) $(OPTS) -c $< -o $@ 
test-%: $(TSTDIR)/%.cpp Bint.o Math.o
	$(CXX) $(OPTS) $^ -o $@ 
%.fast.o: %.cpp
	$(CXX) $(OPTS) -Ofast -c $< -o $@ 
%.o: %.cpp
	$(CXX) $(OPTS) -c $< -o $@ 

clean: 
	rm -rf main main-fast *.o test-* 
