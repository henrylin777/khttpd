#ifndef KHTTPD_HTTP_SERVER_H
#define KHTTPD_HTTP_SERVER_H
#define MODULE_NAME "khttpd_cmwq"

#include <net/sock.h>

struct http_server_param {
    struct socket *listen_socket;
};

struct khttpd_task {
    struct socket *socket_fd;
    struct work_struct khttpd_work;
    struct list_head node;
};

struct khttpd_service {
    bool is_stopped;
    struct list_head worker;
};

extern int http_server_daemon(void *arg);

#endif
