#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Уровни журналирования
typedef enum {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR,
    CRITICAL
} LogLevel;

// Функция для вывода данных в журнал
int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    // Проверка уровня журналирования
    if (level < DEBUG || level > CRITICAL) {
        return -1;
    }

    // Формирование строки журнала
    char log_str[1024];
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(log_str, sizeof(log_str), "%Y-%m-%d %H:%M:%S", tm);
    strcat(log_str, " [");
    switch (level) {
        case DEBUG:
            strcat(log_str, "DEBUG");
            break;
        case INFO:
            strcat(log_str, "INFO");
            break;
        case WARN:
            strcat(log_str, "WARN");
            break;
        case ERROR:
            strcat(log_str, "ERROR");
            break;
        case CRITICAL:
            strcat(log_str, "CRITICAL");
            break;
    }
    strcat(log_str, "] ");
    strcat(log_str, msg);

    // Вывод журнала в выбранный формат
    switch (format) {
        case 0: // текстовый формат
            printf("%s\n", log_str);
            break;
        case 1: // JSON формат
            printf("{\"level\": \"%s\", \"message\": \"%s\"}\n", log_str, log_str);
            break;
        default:
            return -1;
    }

    // Запись журнала в файл
    FILE* file = fopen(path, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", log_str);
        fclose(file);
    }

    return 0;
}
