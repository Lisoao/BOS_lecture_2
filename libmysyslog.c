#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

// Функция для записи в журнал
void mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    // Определение уровня журналирования
    switch (level) {
        case DEBUG:
            syslog(LOG_DEBUG, "%s", msg);
            break;
        case INFO:
            syslog(LOG_INFO, "%s", msg);
            break;
        case WARN:
            syslog(LOG_WARNING, "%s", msg);
            break;
        case ERROR:
            syslog(LOG_ERR, "%s", msg);
            break;
        case CRITICAL:
            syslog(LOG_CRIT, "%s", msg);
            break;
    }
}

int main() {
    // Запись в журнал
    mysyslog("This is a test message", INFO, 0, 0, "/var/log/syslog");

    return 0;
}
