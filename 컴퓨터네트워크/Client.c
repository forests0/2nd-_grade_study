#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_LEN 80
int main(int argc, char *argv[])
{
    int skt, n, len_in, len_out;
    struct sockaddr_in server_addr;
    char *host_addr;
    char buf[BUF_LEN + 1];

    if (argc != 2)
    {
        printf("사용법: %s ip_address\n", argv[0]);
        return -1;
    }
    host_addr = argv[1];

    if ((skt = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("소켓 생성 실패\n");
        return -1;
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(3030);

    if (connect(skt, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("연결 실패\n");
        return -1;
    }
    printf("문자열을 입력하시요 : ");
    if (fgets(buf, BUF_LEN, stdin))
    {
        buf[BUF_LEN] = '\0';
        len_out = strlen(buf);
    }
    else
    {
        printf("오류\n");
        return -1;
    }
    if (write(skt, buf, len_out) < 0)
    {
        printf("write 오류\n");
        return -1;
    }
    printf("%s", buf);
    close(skt);
    return 0;
}
