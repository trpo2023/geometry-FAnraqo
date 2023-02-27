all: geo
geo: geometry.c
		gcc -Wall -Werror -o geo geometry.c -lm
