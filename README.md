# ybacklight

Adjust backlight brightness using sysfs.

## Build

Prior compilation, the sysfs driver path can be configured according to your hardware in `ybacklight.h`.

Then, build the binary.

```
make
make install
```

As writing to sysfs requires elevated privileges, the binary has to be run as `root`. Therefore, you'll most probably want to set the `SUID` bit afterwards to make `ybacklight` accessible to  normal users.

```
chown root:root /usr/bin/ybacklight
chmod 4755 /usr/bin/ybacklight
```

## Usage

`ybacklight [-get|-set|-inc|-dec] [value]`

- `-get`: Get current brightness.
- `-set [value]`: Set brightness to `value` (percentage).
- `-inc [value]`: Increase brightness by `value` (percentage)
- `-dec [value]`: Decrease brightness by `value` (percentage)

