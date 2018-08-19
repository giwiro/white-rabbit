#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/select.h"
#include "sys/socket.h"
#include "microhttpd.h"
#include "utils.h"
#include "defaults.h"
#include "logger.h"
#include "controller.h"

char *hostname;

int main() {
    hostname = (char *)malloc(DEFAULT_HOSTNAME_BUFFER_SIZE + 1);
    print_banner();
    uint32_t port = get_port();
    uint32_t threads = get_thread_pool_size();
    get_hostname(hostname);
#ifdef DEBUG
    log_message(stdout, "[ENV]: Development\r\n");
#else
    log_message(stdout, "[ENV]: Release\r\n");
#endif
    log_message(stdout, "[LOG]: Initializing white-rabbit with:\r\n");
    log_message(stdout, "\t├─ PORT=%d\r\n", port);
    log_message(stdout, "\t├─ THREAD_POOL_SIZE_KEY=%d\r\n", threads);
#if EPOLL_SUPPORT
    log_message(stdout, "\t├─ EPOLL_SUPPORT\r\n");
#endif
    log_message(stdout, "\t└─ hostname=%s\r\n\n", hostname);

    // Daemon
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(
    // MHD_FEATURE
        MHD_USE_SELECT_INTERNALLY
#if DEBUG
        | MHD_USE_DEBUG
#endif
#if EPOLL_SUPPORT
        | MHD_USE_EPOLL_LINUX_ONLY
#endif
        ,
        port, NULL, NULL,
        &answer_to_connection, NULL,
    // MHD_OPTION
        MHD_OPTION_THREAD_POOL_SIZE, (unsigned int) threads,
        MHD_OPTION_CONNECTION_TIMEOUT, (unsigned int) DEFAULT_TIME_OUT,
        MHD_OPTION_END);
    if (NULL == daemon)
        return 1;
    log_message(stdout, "[LOG]: (/¯◡ ‿ ◡)/¯﻿ wh1t3-r4bb1t listening...\r\n");
    getchar();

    log_message(stdout, "[LOG]: Killing daemon\r\n");
    MHD_stop_daemon (daemon);
    log_message(stdout, "[LOG]: Freeing allocated variables\r\n");
    free(hostname);
    return 0;
}
