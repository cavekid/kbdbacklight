# kbdbacklight

Adjust keyboard backlight brightness using sysfs.

## Build

Prior compilation, the sysfs driver path can be configured according to your hardware in `kbdbacklight.h`.

Then, build the binary.

```
make
make install
```

As writing to sysfs requires elevated privileges, the binary has to be run as `root`. Therefore, you'll most probably want to set the `SUID` bit afterwards to make `kbdbacklight` accessible to  normal users.

```
chown root:root /usr/bin/kbdbacklight
chmod 4755 /usr/bin/kbdbacklight
```

## Usage

`kbdbacklight [-get|-set|-inc|-dec] [value]`

- `-get`: Get current brightness.
- `-set [value]`: Set brightness to `value` (percentage).
- `-inc [value]`: Increase brightness by `value` (percentage)
- `-dec [value]`: Decrease brightness by `value` (percentage)

