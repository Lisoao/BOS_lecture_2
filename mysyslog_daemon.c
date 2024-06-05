#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

// Структура конфигурационного файла
typedef struct {
    char path[256];
    int format;
    int driver;
} Config;

// Функция для чтения конфигурационного файла
Config read_config() {
    Config config;
    FILE* file = fopen("/etc/mysyslog/mysyslog.cfg", "r");
    if (file == NULL) {
        return config;
    }

    if (fscanf(file, "%s %d %d", config.path, &config.format, &config.driver) != 3) {
        fclose(file);
        return config;
    }

    fclose(file);
    return config;
}

// Функция для вывода журнала
void log_message(const char* msg, int level) {
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
    switch (config.format) {
        case 0: // текстовый формат
            printf("%s\n", log_str);
            break;
        case 1: // JSON формат
            printf("{\"timestamp\": %ld, \"log_level\": \"%s\", \"process\": \"mysyslog-daemon\", \"message\": \"%s\"}\n", now, get_log_level_str(level), log_str);
            break;
        default:
            printf("Unknown format\n");
    }
}

// Функция для преобразования уровня журналирования в строку
const char* get_log_level_str(int level) {
    switch (level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARN:
            return "WARN";
        case ERROR:
            return "ERROR";
        case CRITICAL:
            return "CRITICAL";
    }
    return "";
}

int main() {
    // Чтение конфигурационного файла
    Config config = read_config();

    // Вывод журнала с разными уровнями
    while (1) {
        log_message("This is a debug message", DEBUG);
        log_message("This is an info message", INFO);
        log_message("This is a warning message", WARN);
        log_message("This is an error message", ERROR);
        log_message("This is a critical message", CRITICAL);
        sleep(1);
    }

    return 0;
}
