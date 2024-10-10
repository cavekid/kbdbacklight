# kbdbacklight

Adjust keyboard backlight brightness using sysfs.

## Build

Prior compilation, the sysfs driver path can be configured according to your hardware in `kbdbacklight.h`.

Then, build the binary with

```
make
make install
```

## Usage

`kbdbacklight [-get|-set|-inc|-dec] [value]`

- `-get`: Get current brightness.
- `-set [value]`: Set brightness to `value` (percentage).
- `-inc [value]`: Increase brightness by `value` (percentage)
- `-dec [value]`: Decrease brightness by `value` (percentage)

