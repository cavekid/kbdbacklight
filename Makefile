CC = gcc
CFLAGS ?= -O2 -fPIC -pedantic -Wall
LDFLAGS = -lm

OBJ = main.o kbdbacklight.o
TARGET = kbdbacklight

PREFIX = /usr

.PHONY: clean all install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c kbdbacklight.h
	$(CC) $(CFLAGS) -c $^

kbdbacklight.o: kbdbacklight.c kbdbacklight.h
	$(CC) $(CFLAGS) -c $^

install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp kbdbacklight $(DESTDIR)$(PREFIX)/bin/kbdbacklight

uninstall:
	rm $(DESTDIR)$(PREFIX)/bin/kbdbacklight

clean:
	rm -f $(OBJ) $(TARGET) *.gch
