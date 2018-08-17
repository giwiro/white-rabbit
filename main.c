#include "stdio.h"
#include "sys/types.h"
#include "sys/select.h"
#include "sys/socket.h"
#include "microhttpd.h"
#include "utils.h"
#include "logger.h"

#define _BSD_SOURCE

int main() {
	char hostname[DEFAULT_HOSTNAME_BUFFER_SIZE];
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
    log_message(stdout, "    ├─ PORT=%d\r\n", port);
    log_message(stdout, "    ├─ THREAD_POOL_SIZE_KEY=%d\r\n", threads);
    log_message(stdout, "    └─ hostname=%s\r\n", hostname);
    return 0;
}
