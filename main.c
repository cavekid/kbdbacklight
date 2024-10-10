#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "kbdbacklight.h"

int
main(int argc, char *argv[])
{
	char *command;
	int value;

	if (argc < 2) {
		goto usage;
	}

	command = argv[1];

	if (strncmp(command, "-get", 4) == 0) {
		printf("%d\n", brightness());
		return 0;
	}

	if (argc < 3) {
		goto usage;
	}

	value = strtol(argv[2], NULL, 10);

	if (value < 0 || value > 100) {
		goto usage;
	}

	if (strncmp(command, "-set", 4) == 0) {
		if(set_brightness(value)) {
			goto fail;
		}
		return 0;
	}

	if (strncmp(command, "-inc", 4) == 0) {
		if(inc_brightness(value)) {
			goto fail;
		}
		return 0;
	}

	if (strncmp(command, "-dec", 4) == 0) {
		if(dec_brightness(value)) {
			goto fail;
		}
		return 0;
	}

fail:
	perror("failed to set brightness");
	return 2;

usage:
	fprintf(stderr, "Usage: kbdbacklight [-get|-set|-inc|-dec] [percent]\n");
	return 1;

}
