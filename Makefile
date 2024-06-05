CC = gcc
CFLAGS = -Wall -Wextra -ldl

TARGET = mysyslog-client
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
