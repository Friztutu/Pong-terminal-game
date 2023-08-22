CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror
LDFLAGS=-c -std=c11 -Wall -Wextra -Werror $(CFLAGS)

all : for_one for_two

for_two : main.o pong.o render.o
	$(CC) $(CFLAGS) ../build/main.o ../build/pong.o ../build/render.o -lncurses -o ../build/for_two

pong.o : pong.c
	$(CC) $(LDFLAGS) -DTWO pong.c -lncurses -o ../build/pong.o

main.o : main.c
	$(CC) $(LDFLAGS) main.c -lncurses -o ../build/main.o

render.o : render.c
	$(CC) $(LDFLAGS) render.c -lncurses -o ../build/render.o

for_one : main.o pong_s.o render.o
	$(CC) $(CFLAGS) ../build/main.o ../build/pong_s.o ../build/render.o -lncurses -o ../build/for_one

pong_s.o : pong.c
	$(CC) $(LDFLAGS) pong.c -lncurses -o ../build/pong_s.o

clean : 
	rm -rf ../build/*

rebuild : clean all

style-format : 
	mv ../linters/.clang-format .
	clang-format -i *.c *.h
	mv .clang-format ../linters/.clang-format

test :
	mv ../linters/.clang-format .
	clang-format -n *.c *.h
	mv .clang-format ../linters/.clang-format
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
