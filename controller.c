#include "stdio.h"
#include "stdlib.h"
#include "microhttpd.h"
#include "logger.h"
#include "controller.h"

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls)
{
  printf ("[%s], New %s request for %s using version %s\n", hostname, method, url, version);

  return MHD_NO;
}
