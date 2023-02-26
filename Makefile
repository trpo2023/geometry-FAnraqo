all:hello
hello: hello_world.c
	gcc -Wall -Werror -o hi hello_world.c
