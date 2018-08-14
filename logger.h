#ifndef _LOGGER_H
#define _LOGGER_H

#include "stdio.h"
#define MAX_SIZE_LOGGER_BUFFER 1024

// The magical rest parameter, basically we get the format str as first parameter
// and the rest is optional, it will fill into the formatted characters (Ex: %s %d %c %p)
void log_message(FILE *stream, const char* fmt, ...);

#endif

