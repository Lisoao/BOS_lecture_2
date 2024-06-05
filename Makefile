# Сборка библиотеки
all: libmysyslog.so

libmysyslog.so: libmysyslog.c libmysyslog.h
    gcc -shared -o libmysyslog.so libmysyslog.c

# Удаление временных файлов
clean:
    rm -f libmysyslog.so
