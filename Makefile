# Сборка библиотеки
all: libmysyslog-json.so

libmysyslog-json.so: libmysyslog-json.c libmysyslog-json.h
    gcc -shared -o libmysyslog-json.so libmysyslog-json.c

# Удаление временных файлов
clean:
    rm -f libmysyslog-json.so
