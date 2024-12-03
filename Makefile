CC = gcc
CFLAGS ?= -O2 -fPIC -pedantic -Wall
LDFLAGS = -lm

OBJ = main.o ybacklight.o

PREFIX ?= /usr
TARGET ?= ybacklight

.PHONY: clean all install uninstall

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

main.o: main.c ybacklight.h
	$(CC) $(CFLAGS) -c $^

ybacklight.o: ybacklight.c ybacklight.h
	$(CC) $(CFLAGS) -c $^

install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp ybacklight $(DESTDIR)$(PREFIX)/bin/ybacklight

uninstall:
	rm $(DESTDIR)$(PREFIX)/bin/ybacklight

clean:
	rm -f $(OBJ) $(TARGET) *.gch
