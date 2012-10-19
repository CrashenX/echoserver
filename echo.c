#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define LISTEN_PORT 7777

int echo(int fd)
{
    static char buffer[65536] = {0};
    int size_in;
    if(0 <= (size_in = read(fd, buffer, sizeof(buffer)))) {
        write(fd, buffer, size_in);
    }
    return size_in;
}

int main()
{
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    int cli_fd = 0;
    struct sockaddr cli_addr;
    socklen_t cli_len;
    struct sockaddr_in sa;

    if(-1 == fd) {
        fprintf(stderr, "Socket Error: %s\n", strerror(errno));
        return 1;
    }
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_port = htons(LISTEN_PORT);
    sa.sin_addr = (struct in_addr) {0};
    if(-1 == bind(fd, (struct sockaddr*)&sa, sizeof(struct sockaddr_in))) {
        fprintf(stderr, "Bind Error: %s\n", strerror(errno));
        return 1;
    }
    if(-1 == listen(fd, 5)) {
        fprintf(stderr, "Listen Error: %s\n", strerror(errno));
        return 1;
    }
    while(-1 != (cli_fd = accept(fd, &cli_addr, &cli_len)))
    {
        if(-1 == echo(cli_fd)) {
            fprintf(stderr, "Echo Error\n");
            return -1;
        }
        close(cli_fd);
    }
}
