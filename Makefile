all: hi geo
hi: hello_world.c
		gcc -Wall -Werror -o hi hello_world.c
geo: geometry.c
		gcc -Wall -Werror -o geo geometry.c -lm
