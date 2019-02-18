#include "star.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static void print_symbol_at_position(char symbol, int position, int size) {
	putchar('|');
	for (int i = 0; i < position - 1; ++i) putchar(' ');
	putchar(symbol);
	for (int i = 0; i < size - position; ++i) putchar(' ');
	putchar('|');
	putchar('\n');
}

static void usleep_p(int usec) {
	struct timespec req = { .tv_sec = 0, .tv_nsec = usec * 1000 };
	nanosleep(&req, NULL);
}

void star_shower(char star, int width, int speed) {
	if (!star) return;
	if (width < 0) return;
	if (speed < 0) return;

	int delay = 500000L / speed;

	int num = 0;
	int init_seed = 0;

	srand(rand());
	init_seed = rand();

	while(1) {
		srand(rand() + init_seed++);
		num = (rand() % width) + 1;
		print_symbol_at_position('*', num, width);
		usleep_p(delay);
	}
}
