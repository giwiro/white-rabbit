#ifndef _UTILS_H
#define _UTILS_H

#include "stdint.h"

#define PORT_ENV_KEY "PORT"
#define THREAD_POOL_SIZE_KEY "THREAD_POOL_SIZE"

void print_banner();
uint32_t get_port();
uint32_t get_thread_pool_size();
void get_hostname(char *hostname);

#endif

