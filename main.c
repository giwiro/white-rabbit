#include "stdio.h"
#include "utils.h"
#include "logger.h"
#include "microhttpd.h"

#include "string.h"

int main() {
	char hostname[DEFAULT_HOSTNAME_BUFFER_SIZE];
	print_banner();
    uint32_t port = get_port();
	uint32_t threads = get_thread_pool_size();
	get_hostname(hostname);
    log_message(stdout, "[LOGG]: Initializing white-rabbit with:\r\n");
    log_message(stdout, "    ├─ PORT=%d\r\n", port);
    log_message(stdout, "    ├─ THREAD_POOL_SIZE_KEY=%d\r\n", threads);
    log_message(stdout, "    └─ hostname=%s\r\n", hostname);
    return 0;
}
