#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "kbdbacklight.h"

int
read_sysfs_int(const char* path)
{
	FILE *f = fopen(path, "r");

	if (!f) {
		return -1;
	}

	int value;

	if(fscanf(f, "%d\n", &value) != 1) {
		value = -1;
	}

	fclose(f);

	return value;
}

int
write_sysfs_int(const char* path, int value)
{
	FILE *f = fopen(path, "w");

	if (!f) {
		return -1;
	}

	int ret = 0;

	if(fprintf(f, "%d\n", value) < 0) {
		ret = -1;
	}

	fclose(f);

	return ret;
}

int
max_brightness()
{
	return read_sysfs_int(MAX_BRIGHTNESS);
}

int
brightness()
{
	return read_sysfs_int(BRIGHTNESS);
}

int
set_brightness(int value)
{
	value = fmin(fmax(value, MIN_PERCENTAGE), MAX_PERCENTAGE);
	int absolute_brightness = (max_brightness() * value) / 100;

	return write_sysfs_int(BRIGHTNESS, absolute_brightness);
}

int
inc_brightness(int value)
{
	int current_percentage = (brightness() * 100) / max_brightness();

	return set_brightness(current_percentage + value);
}

int
dec_brightness(int value)
{
	int current_percentage = (brightness() * 100) / max_brightness();

	return set_brightness(current_percentage - value);
}

