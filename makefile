CC=g++
CFlags=-g -Wall
BINS=main1
OBJS=main1.o myqueue.o blockqueue.o 

all: $(BINS)

main1: $(OBJS)
	$(CC) $(CFlags) -o $@  $^ -lpthread

%: %.cpp
	$(CC) $(CFlags) -c -o $@  $^ -lpthread

clean:
	rm -f *.dSYM $(BINS) *.o client clienttest