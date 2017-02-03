CXX=g++
CXXFLAGS=-g

OBJS = Tape.o Tuple.o TuringMachine.o main.o
all: ${OBJS}
	$(CXX)	$(CXXFLAGS) -o turing ${OBJS}

clean:
	rm -rf $(OBJS)
