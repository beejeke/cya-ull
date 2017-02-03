CXX=g++ 
CXXFLAGS=-g

OBJS = transition.o state.o NFA.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o NFA ${OBJS}

clean: 
	rm -rf *.o nfa 
