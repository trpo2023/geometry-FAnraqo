all: hi geom
hi: hello_world.c
		gcc -Wall -Werror -o hi hello_world.c
geom: geometry.c
		gcc -Wall -Werror -o geo geometry.c -lm
