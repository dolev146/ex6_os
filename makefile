CC=g++
CFlags=-g -Wall
BINS=main1
Main1OBJ=main1.o myqueue.o blockqueue.o ActiveObject.o Pipeline.o

all: $(BINS)

main1: $(Main1OBJ)
	$(CC) $(CFlags) -o $@  $^ -lpthread

%: %.cpp
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

clean:
	rm -f *.dSYM $(BINS) *.o client clienttest