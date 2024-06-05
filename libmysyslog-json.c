#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <json-c/json.h>

// Функция для записи в журнал в формате JSON
void mysyslog_json(const char* msg, int level, int driver, int format, const char* path) {
    // Определение уровня журналирования
    switch (level) {
        case DEBUG:
            syslog(LOG_DEBUG, "{\"level\":\"DEBUG\",\"message\":\"%s\"}", msg);
            break;
        case INFO:
            syslog(LOG_INFO, "{\"level\":\"INFO\",\"message\":\"%s\"}", msg);
            break;
        case WARN:
            syslog(LOG_WARNING, "{\"level\":\"WARN\",\"message\":\"%s\"}", msg);
            break;
        case ERROR:
            syslog(LOG_ERR, "{\"level\":\"ERROR\",\"message\":\"%s\"}", msg);
            break;
        case CRITICAL:
            syslog(LOG_CRIT, "{\"level\":\"CRITICAL\",\"message\":\"%s\"}", msg);
            break;
    }
}

int main() {
    // Запись в журнал в формате JSON
    mysyslog_json("This is a test message", INFO, 0, 0, "/var/log/syslog");

    return 0;
}
