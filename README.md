# ybacklight

Adjust backlight brightness using sysfs.

## Build

Prior compilation, configure the desired sysfs backlight driver to control in `ybacklight.h`.
Optionally, adjust the desired minimum and maximum brightness levels (defaults to 0-100).

```sh
# Example for Apple SMC keyboard backlight.

sed -i 's/\(#define CLASS\s*"\)[^"]*"/\1leds"/' ybacklight.h
sed -i 's/\(#define DRIVER\s*"\)[^"]*"/\1smc::kbd_backlight"/' ybacklight.h
```

Then, build the binary. Depending on the specific sysfs driver _ybacklight_ is compiled with, you may want to override `TARGET` to differentiate the binaries later.

```sh
make TARGET=ybacklight-kbd_backlight
make install
```

As writing to sysfs requires elevated privileges, the binary has to be run as root. Therefore, you'll most probably want to set the SUID bit afterwards to make _ybacklight_ accessible to normal users.

```sh
chown root:root /usr/bin/ybacklight-kbd_backlight
chmod 4755 /usr/bin/ybacklight-kbd_backlight
```

## Usage

`ybacklight [-get|-set|-inc|-dec] [value]`

- `-get`: Get current brightness.
- `-set [value]`: Set brightness to `value` (percentage).
- `-inc [value]`: Increase brightness by `value` (percentage)
- `-dec [value]`: Decrease brightness by `value` (percentage)

