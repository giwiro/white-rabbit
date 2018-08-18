#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "utils.h"
#include "unistd.h"
#include "defaults.h"
#include "logger.h"

void print_banner() {
    printf("\n\n%s\n", "                          .\".");
    printf("%s\n", "                         /  |");
    printf("%s\n", "                        /  /");
    printf("%s\n", "                       / ,\"");
    printf("%s\n", "           .-------.--- /");
    printf("%s\n", "          \"._ __.-/ o. o\\     Follow the_       _                   _     _       _          ");
    printf("%s\n", "             \"   (    Y  )    =========| |===(_) |=================| |===| |===(_) |==       ");
    printf("%s\n", "                  )     /     __      _| |__  _| |_ ___   _ __ __ _| |__ | |__  _| |_             ");
    printf("%s\n", "                 /     (      \\ \\ /\\ / / '_ \\| | __/ _ \\ | '__/ _` | '_ \\| '_ \\| | __|                    ");
    printf("%s\n", "                /       Y      \\ V  V /| | | | | ||  __/ | | | (_| | |_) | |_) | | |_                    ");
    printf("%s\n", "            .-\"         |       \\_/\\_/ |_| |_|_|\\__\\___| |_|  \\__,_|_.__/|_.__/|_|\\__|                ");
    printf("%s\n", "           /  _     \\    \\    ========================================================                    ");
    printf("%s\n", "          /    `. \". ) /' )              ");
    printf("%s\n", "         Y       )( / /(,/                  ");
    printf("%s\n", "        ,|      /     )             ");
    printf("%s\n", "       ( |     /     /");
    printf("%s\n", "        \" \\_  (__   (__      ");
    printf("%s\n\n\n", "            \"-._,)--._,)");
}

uint32_t get_port() {
    const char *port_str = getenv(PORT_ENV_KEY);
    if (port_str == NULL) {
        return DEFAULT_PORT;
    }
    const size_t port_size = strlen(port_str);
    if (port_size != 4) {
        log_message(stderr, "[ERRO]: PORT is not 4-sized, returning default.\r\n");
        // exit(EXIT_FAILURE);
        return DEFAULT_PORT;
    }
    // Use of strtol
    char *end_ptr;
    const uint32_t port = strtol(port_str, &end_ptr, 10);
    if (port_str == end_ptr || port == 0) {
        log_message(stderr, "[ERRO]: PORT is not a valid number, returning default.\r\n");
        return DEFAULT_PORT;
    }
    return port;
}

uint32_t get_thread_pool_size() {
    const char *threads_str = getenv(THREAD_POOL_SIZE_KEY);
    if (threads_str == NULL) {
        return DEFAULT_THREAD_POOL_SIZE;
    }
    const size_t threads_str_size = strlen(threads_str);
    if (threads_str_size < 2) {
        log_message(stderr, "[ERRO]: THREAD_POOL_SIZE_KEY must have al least one digit, returning default.\r\n");
        // exit(EXIT_FAILURE);
        return DEFAULT_THREAD_POOL_SIZE;
    }
    // Use of strtol
    char *end_ptr;
    const uint32_t threads = strtol(threads_str, &end_ptr, 10);
    if (threads <= 1) {
        log_message(stderr, "[ERRO]: THREAD_POOL_SIZE_KEY must be 1 or more, returning default.\r\n");
        return DEFAULT_THREAD_POOL_SIZE;
    }
    return threads;
}

void get_hostname(char *hostname) {
    if (gethostname(hostname, DEFAULT_HOSTNAME_BUFFER_SIZE) == -1) {
        strncpy(hostname, DEFAULT_HOSTNAME, DEFAULT_HOSTNAME_LENGTH);
    }
}

