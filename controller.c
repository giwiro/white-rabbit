#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "microhttpd.h"
#include "logger.h"
#include "controller.h"

int handle_method_not_allowed(struct MHD_Connection *connection) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(0, "", MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "X-Powered-By", "wh1t3-r4bb1t");
    ret = MHD_queue_response(connection, MHD_HTTP_METHOD_NOT_ALLOWED, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_not_found(struct MHD_Connection *connection) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(0, "", MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "X-Powered-By", "wh1t3-r4bb1t");
    ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_options(struct MHD_Connection *connection) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(0, "", MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "Access-Control-Allow-Origin", ALLOWED_ORIGIN);
    MHD_add_response_header(response, "Access-Control-Allow-Methods", "GET, OPTIONS");
    MHD_add_response_header(response, "Access-Control-Allow-Credentials", "false");
    MHD_add_response_header(response, "Access-Control-Max-Age", "86400");
    MHD_add_response_header(response, "Access-Control-Allow-Headers", "X-Requested-With, X-HTTP-Method-Override, Content-Type, Accept");
    MHD_add_response_header(response, "X-Powered-By", "wh1t3-r4bb1t");
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int handle_whois_route(struct MHD_Connection *connection, char *hostname) {
    int ret;
    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(strlen(hostname), hostname, MHD_RESPMEM_PERSISTENT);
    MHD_add_response_header(response, "Access-Control-Allow-Origin", ALLOWED_ORIGIN);
    MHD_add_response_header(response, "X-Powered-By", "wh1t3-r4bb1t");
    MHD_add_response_header(response, "Content-Type", "text/plain");
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

void log_allowed_request(const char *url, const char *method, const char *version) {
    log_message(stdout, "[%s]: %s %s\r\n", method, version, url);
}

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls)
{
    // Methods that are not allowed
    if (strcmp(method, MHD_HTTP_METHOD_GET) != 0
        && strcmp(method, MHD_HTTP_METHOD_OPTIONS) != 0) {
        return handle_method_not_allowed(connection);
    }
    // Route check
    if (strcmp(url, URL) != 0) {
        return handle_not_found(connection);
    }
    // Log allowed req
    log_allowed_request(url, method, version);
    // Handle OPTIONS
    if (strcmp(method, MHD_HTTP_METHOD_OPTIONS) == 0) {
        return handle_options(connection);
    }
    // Handle GET request
    if (strcmp(method, MHD_HTTP_METHOD_GET) == 0) {
        return handle_whois_route(connection, hostname);
    }
    printf ("[%s], New %s request for route: %s using version %s\n", hostname, method, url, version);

    return MHD_NO;
}
