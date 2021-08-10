block_plain: block_plain.c sdl_wrapper.o hit.o block_function.o ball_function.o racket_function.o
	gcc -lSDL2 $(sdl2-config --libs) block_plain.c sdl_wrapper.o hit.o block_function.o ball_function.o racket_function.o -o block_plain

sdl_wrapper: sdl_wrapper.c
	gcc -c sdl_wrapper.c $(sdl2-config --cflags)

hit: hit.c
	gcc -c hit.c

block_function: block_function.c
	gcc -c block_function.c

ball_function: ball_function.c
	gcc -c ball_function.c

racket_function: racket_function.c
	gcc -c racket_function.c

clear:
	rm *.o block_plain
