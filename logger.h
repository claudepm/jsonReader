#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void log_print(char *filename, int line, char *fmt, ...);

#define LOG_PRINT(...) log_print(__FILE__, __LINE__, __VA_ARGS__)

#endif /* LOGGER_H */