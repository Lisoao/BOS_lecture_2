#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H

// Функция для записи в журнал
void mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif
