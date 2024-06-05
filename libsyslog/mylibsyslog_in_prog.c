#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmysyslog.h"

int main() {
    // Вывод сообщения в журнал
    mysyslog("This is a debug message", DEBUG, 0, 0, "log.txt");
    mysyslog("This is an info message", INFO, 0, 0, "log.txt");
    mysyslog("This is a warning message", WARN, 0, 0, "log.txt");
    mysyslog("This is an error message", ERROR, 0, 0, "log.txt");
    mysyslog("This is a critical message", CRITICAL, 0, 0, "log.txt");

    return 0;
}
