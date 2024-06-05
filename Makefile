CC = gcc
CFLAGS = -Wall -Wextra

TARGET = mysyslog-daemon
SRC = mysyslog_daemon.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
