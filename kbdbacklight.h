#ifndef KBDBACKLIGHT_H
#define KBDBACKLIGHT_H

#define DRIVER			"smc::kbd_backlight"
#define DRIVER_PATH		"/sys/class/leds/" DRIVER
#define BRIGHTNESS		DRIVER_PATH "/brightness"
#define MAX_BRIGHTNESS	DRIVER_PATH	"/max_brightness"
#define MIN_PERCENTAGE	0
#define MAX_PERCENTAGE	100

int max_brightness();

int brightness();

int set_brightness(int value);

int inc_brightness(int value);

int dec_brightness(int value);

#endif
