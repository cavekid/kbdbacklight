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
		printf("%d\n", get_brightness());
		return 0;
	}

	if (argc < 3) {
		goto usage;
	}

	value = strtol(argv[2], NULL, 10);

	if (value < MIN_PERCENTAGE || value > MAX_PERCENTAGE) {
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
	fprintf(stderr, "Usage: kbdbacklight [-get | -set PERCENT | -inc PERCENT | -dec PERCENT]\n\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "  -get             Get the current keyboard backlight brightness in percent (%d-%d).\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	fprintf(stderr, "  -set PERCENT     Set the keyboard backlight brightness to the specified PERCENT (%d-%d).\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	fprintf(stderr, "  -inc PERCENT     Increase the current brightness by the specified PERCENT.\n");
	fprintf(stderr, "  -dec PERCENT     Decrease the current brightness by the specified PERCENT.\n\n");
	fprintf(stderr, "Examples:\n");
	fprintf(stderr, "  kbdbacklight -get              # Prints the current brightness.\n");
	fprintf(stderr, "  kbdbacklight -set 75           # Sets the brightness to 75%%.\n");
	fprintf(stderr, "  kbdbacklight -inc 10           # Increases brightness by 10%%.\n");
	fprintf(stderr, "  kbdbacklight -dec 20           # Decreases brightness by 20%%.\n\n");
	fprintf(stderr, "Note:\n");
	fprintf(stderr, "  PERCENT must be a value between %d and %d.\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	return 1;

}
