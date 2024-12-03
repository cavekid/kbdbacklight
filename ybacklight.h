#ifndef YBACKLIGHT_H
#define YBACKLIGHT_H

/* Name of the sysfs backlight device class. */
#define CLASS			"backlight"

/* Name of the sysfs backlight device driver. */
#define DRIVER			"intel_backlight"

/* Minimum brightness allowed to set. */
#define MIN_PERCENTAGE	0

/* Maximum brightness allowed to set. */
#define MAX_PERCENTAGE	100

#define BRIGHTNESS		"/sys/class/" CLASS "/" DRIVER "/brightness"
#define MAX_BRIGHTNESS	"/sys/class/" CLASS "/" DRIVER "/max_brightness"

int get_brightness();

int set_brightness(int value);

int inc_brightness(int value);

int dec_brightness(int value);

#endif
