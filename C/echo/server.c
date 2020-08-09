#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 12345
#define BACKLOG_SIZE 32

int main(int argc, char* argv[]) {
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    socklen_t len;
    ssize_t ret;
    int soc;
    int acc;
    char buf[32];
    char msg[128];

    memset(buf, 0, sizeof(buf));
    memset(msg, 0, sizeof(msg));

    soc = socket(AF_INET, SOCK_STREAM, 0);

    if (soc < 0) {
        perror("socket");
        exit(1);
    }

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    ret = bind(soc, (struct sockaddr*)&s_addr, sizeof(s_addr));

    if (ret < 0) {
        perror("bind");
        exit(1);
    }

    ret = listen(soc, BACKLOG_SIZE);

    if (ret < 0) {
        perror("listen");
        exit(1);
    }
    
    printf("server ip address: %s\n", inet_ntoa(s_addr.sin_addr));
    printf("port      : %d\n", ntohs(s_addr.sin_port));
    printf("listen...\n");
    printf("\n");

    len = sizeof(c_addr);

    acc = accept(soc, (struct sockaddr*)&c_addr, &len);

    if (acc < 0) {
        perror("accept");
        exit(1);
    }

    printf("client ip address: %s\n", inet_ntoa(c_addr.sin_addr));
    printf("port      : %d\n", ntohs(c_addr.sin_port));
    printf("\n");

    while (1) {
        ret = read(acc, buf, sizeof(buf)-1);
        printf("ret: %ld\n", ret);

        strncat(msg, buf, sizeof(buf));
        memset(buf, 0, sizeof(buf));

        if (ret == -1) {
            perror("read");
            exit(1);
        }
        else if (ret < sizeof(buf)-1) {
            break;
        }
        else {
            printf("%ld\n", ret);
        }
    }

    printf("mgs: %s\n", msg);
    printf("%ld\n", strlen(msg));

    ret = write(acc, msg, strlen(msg));

    if (ret < 0) {
        perror("write");
        exit(1);
    }

    if (close(acc) < 0) {
        perror("close acc");
        exit(1);
    }

    if (close(soc) < 0) {
        perror("close soc");
        exit(1);
    }

    return 0;
}
