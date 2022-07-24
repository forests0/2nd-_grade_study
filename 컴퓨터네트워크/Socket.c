#include <stdio.h>
#include <syc/socket.h>

struct sockaddr_in {
    u_char sin_len;
    u_short sin_family;
    u_short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
}

struct in_addr
{
    u_long s_addr;
};

int main() {
    int socket(int domain, int type, int protocol);
    int bind(int sockid, struct sockaddr *addr, int addr_len);
}