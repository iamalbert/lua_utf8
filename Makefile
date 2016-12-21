CC := gcc


LUA_HOME := $(realpath $(dir $(shell which th))../)

LUA_INCDIR ?= $(LUA_HOME)/include
LUA_LIBDIR ?= $(LUA_HOME)/lib

CFLAGS ?= -Wall -pedantic -Wno-deprecated-register -I$(LUA_HOME)/include -std=c99

all: utf8.so

utf8.so: utf8.c
	$(CC) -o $@ -shared -fPIC $(CFLAGS) $^

install: utf8.so
	cp $^ $(LIBDIR)

clean:
	rm -rf *.o *.so
