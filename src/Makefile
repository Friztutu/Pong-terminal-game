CC=gcc
CFLAGS=-std=c11
LDFLAGS=-c $(CFLAGS)
CFTESTFLAGS=-Wall -Wextra -Werror -fsanitize=address -std=c11

all : main test

main : main.o pong.o render.o
	$(CC) $(CFLAGS) ../build/main.o ../build/pong.o ../build/render.o -lncurses -o ../build/main

pong.o : pong.c
	$(CC) $(LDFLAGS) pong.c -lncurses -o ../build/pong.o

main.o : main.c
	$(CC) $(LDFLAGS) main.c -lncurses -o ../build/main.o

render.o : render.c
	$(CC) $(LDFLAGS) render.c -lncurses -o ../build/render.o

clean : 
	rm -rf ../build/*.o 
	rm -rf ../build/*main

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
	$(CC) -c $(CFTESTFLAGS) pong.c -lncurses -o ../build/pong_test.o
	$(CC) -c $(CFTESTFLAGS) main.c -lncurses -o ../build/main_test.o
	$(CC) -c $(CFTESTFLAGS) render.c -lncurses -o ../build/render_test.o
	$(CC) $(CFTESTFLAGS) ../build/main_test.o ../build/pong_test.o ../build/render_test.o -lncurses -o ../build/test_main
