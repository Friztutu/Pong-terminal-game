CC=gcc
CFLAGS=-Wall -Wextra -Werror -lncurses -fsanitize=address
LDFLAGS=-c $(CFLAGS)

all : main

main : main.o pong.o
	$(CC) $(CFLAGS) ../build/main.o ../build/pong.o -o ../build/main

pong.o : pong.c
	$(CC) $(LDFLAGS) pong.c -o ../build/pong.o

main.o : main.c
	$(CC) $(LDFLAGS) main.c -o ../build/main.o

clean : 
	rm -rf *.o 
	rm -rf ../build/main

rebuild : clean all