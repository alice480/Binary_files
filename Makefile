CC = gcc
CFLAGS = -Wall -Wextra
DIR = ../build/

all: state_sort

state_sort.o: state_sort.c
	$(CC) $(CFLAGS) -c state_sort.c

state_search.o: state_search.c
	$(CC) $(CFLAGS) -c state_search.c

clear_state.o: clear_state.c
	$(CC) $(CFLAGS) -c clear_state.c

state_sort: state_sort.o
	$(CC) -o $(DIR)Quest_1 state_sort.o

state_search: state_search.o
	$(CC) -o $(DIR)Quest_2 state_search.o

clear_state: clear_state.o
	$(CC) -o $(DIR)Quest_3 clear_state.o

clean:
	rm -rf *.o
	rm -rf ../build/Quest_*

rebuild: clean all
