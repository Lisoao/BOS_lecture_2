# Makefile для libmysyslog-json
CC=gcc
CFLAGS=-Wall -O2
LDFLAGS=-shared
TARGET=libmysyslog-json.so

libmysyslog-json.so: libmysyslog-json.c
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

install:
    cp libmysyslog-json.so /usr/lib/libmysyslog-json.so
    echo "libmysyslog-json installed"
