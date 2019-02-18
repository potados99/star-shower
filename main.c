#include "star.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
	if (argc < 3) {
		fprintf(stderr, "Usage: star [width] [speed]\n");
		return -1;
	}

	char *pos = NULL;
	int width = (int)strtol(argv[1], &pos, 10);
	int speed = (int)strtol(argv[2], &pos, 10);

	star_shower('*', width, speed);

	return 0;
}
