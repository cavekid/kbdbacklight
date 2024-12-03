#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "ybacklight.h"

int
main(int argc, char *argv[])
{
	char *command;
	int value, result;

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
		result = set_brightness(value);
	} else if (strncmp(command, "-inc", 4) == 0) {
		result = inc_brightness(value);
	} else if (strncmp(command, "-dec", 4) == 0) {
		result = dec_brightness(value);
	} else {
		goto usage;
	}

	if (result != 0) {
		goto error;
	}

	return 0;

error:
	fprintf(stderr, "Error: failed to adjust brightness (%s)\n", strerror(errno));
	return 2;

usage:
	fprintf(stderr, "Usage: ybacklight [-get | -set PERCENT | -inc PERCENT | -dec PERCENT]\n\n");
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "  -get             Get the current backlight brightness in percent (%d-%d).\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	fprintf(stderr, "  -set PERCENT     Set the backlight brightness to the specified PERCENT (%d-%d).\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	fprintf(stderr, "  -inc PERCENT     Increase the current brightness by the specified PERCENT.\n");
	fprintf(stderr, "  -dec PERCENT     Decrease the current brightness by the specified PERCENT.\n\n");
	fprintf(stderr, "Examples:\n");
	fprintf(stderr, "  ybacklight -get              # Prints the current brightness.\n");
	fprintf(stderr, "  ybacklight -set 75           # Sets the brightness to 75%%.\n");
	fprintf(stderr, "  ybacklight -inc 10           # Increases brightness by 10%%.\n");
	fprintf(stderr, "  ybacklight -dec 20           # Decreases brightness by 20%%.\n\n");
	fprintf(stderr, "Note:\n");
	fprintf(stderr, "  PERCENT must be a value between %d and %d.\n", MIN_PERCENTAGE, MAX_PERCENTAGE);
	return 1;
}
