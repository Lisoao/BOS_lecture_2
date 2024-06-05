#ifndef LIBMYSYSLOG_JSON_H
#define LIBMYSYSLOG_JSON_H

// Функция для записи в журнал в формате JSON
void mysyslog_json(const char* msg, int level, int driver, int format, const char* path);

#endif
