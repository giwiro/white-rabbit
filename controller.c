#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "microhttpd.h"
#include "logger.h"
#include "controller.h"

int method_not_allowed(struct MHD_Connection *connection) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(0, "", MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_METHOD_NOT_ALLOWED, response);
    MHD_destroy_response(response);
    return ret;
}

int not_found(struct MHD_Connection *connection) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(0, "", MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
    MHD_destroy_response(response);
    return ret;
}


int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls)
{
    // Methods that are not allowed
    if (strcmp(method, MHD_HTTP_METHOD_GET) != 0
        && strcmp(method, MHD_HTTP_METHOD_OPTIONS) != 0) {
        return method_not_allowed(connection);
    }
    // Route check
    if (strcmp(url, URL) != 0) {
        return not_found(connection);
    }
    printf ("[%s], New %s request for route: %s using version %s\n", hostname, method, url, version);

    return MHD_NO;
}
