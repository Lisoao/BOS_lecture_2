
CC = gcc
CFLAGS = -Wall -Wextra -I.

TARGET = libmysyslog_text.so
SRC = mysyslog_text.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -shared -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
