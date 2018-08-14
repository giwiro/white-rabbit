#include "stdio.h"
#include "microhttpd.h"
#include "utils.h"
#include "logger.h"

int main() {
	print_banner();
    uint32_t port = get_port();
	uint32_t threads = get_thread_pool_size();
    log_message(stdout, "[LOGG]: Initializing white-rabbit with:\r\n");
    log_message(stdout, "    ├─ PORT=%d\r\n", port);
    log_message(stdout, "    └─ THREAD_POOL_SIZE_KEY=%d\r\n", threads);
    return 0;
}
