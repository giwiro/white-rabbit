#ifndef _UTILS_H
#define _UTILS_H

#define PORT_ENV_KEY "PORT"
#define THREAD_POOL_SIZE_KEY "THREAD_POOL_SIZE"
#define DEFAULT_PORT 6969
#define DEFAULT_THREAD_POOL_SIZE 2

void print_banner();
uint32_t get_port();
uint32_t get_thread_pool_size();

#endif

