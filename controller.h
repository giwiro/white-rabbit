#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#define URL "/whois"
#define URL_SIZE 6

// This little fucker here is a hack, because we ensure the hostname variable
// existance in the main.c file, but we put this in order to compile with no not found errors.
char *hostname;

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url, const char *method,
                         const char *version, const char *upload_data,
                         size_t *upload_data_size, void **con_cls);

#endif
