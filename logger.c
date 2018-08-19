#include "logger.h"
#include "stdarg.h"
#include "stdio.h"
#include "stdlib.h"

void log_message(FILE *stream, const char* fmt, ...) {
    char buffer[MAX_SIZE_LOGGER_BUFFER];
    va_list args;
    va_start(args, fmt);
    int n = vsnprintf(buffer, MAX_SIZE_LOGGER_BUFFER, fmt, args);
    if (n < 0 || n > MAX_SIZE_LOGGER_BUFFER) {
        printf("[CRIT]: Overflow attempt in logger D:");
        return;
    }
    fprintf(stream, "%s", buffer);
    // Facilitate a normal return when va_start is used
    va_end(args);
    fflush(stdout);
}

