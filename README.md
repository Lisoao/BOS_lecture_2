# mysyslog-daemon
## Описание
Модуль mysyslog-daemon - это демон, который выводит журнал с разными уровнями в формате текста или JSON.

## Сборка
Модуль собирается с помощью Makefile:
```makefile
all: mysyslog-daemon

mysyslog-daemon: mysyslog-daemon.c
    $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
    rm -f mysyslog-daemon
    rm -f mysyslog-daemon.o
    rm -f mysyslog-daemon.so
