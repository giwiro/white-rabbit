#include "stdio.h"
#include "sys/types.h"
#include "sys/select.h"
#include "sys/socket.h"
#include "microhttpd.h"
#include "utils.h"
#include "logger.h"

static int
answer_to_connection (void *cls, struct MHD_Connection *connection,
                      const char *url, const char *method,
                      const char *version, const char *upload_data,
                      size_t *upload_data_size, void **con_cls)
{
  printf ("New %s request for %s using version %s\n", method, url, version);

  return MHD_NO;
}


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
    log_message(stdout, "\t├─ PORT=%d\r\n", port);
    log_message(stdout, "\t├─ THREAD_POOL_SIZE_KEY=%d\r\n", threads);
    log_message(stdout, "\t└─ hostname=%s\r\n\n", hostname);

    // Daemon
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY, port, NULL, NULL,
                             &answer_to_connection, NULL, MHD_OPTION_END);
	if (NULL == daemon)
		return 1;
	log_message(stdout, "[LOG]: (/¯◡ ‿ ◡)/¯﻿ wh1t3-r4bb1t listening...\r\n");
	getchar ();

	MHD_stop_daemon (daemon);
	return 0;
}
