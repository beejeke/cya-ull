CC=g++ 
CXXFLAGS=-g

OBJS = main.o dfa.o status.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o dfa ${OBJS}

clean: 
	rm -rf *.o dfa
