#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 12345

typedef struct data {
    char name[8];
    uint8_t  age;
} Data;

int main(int argc, char* argv[]) {
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    socklen_t len;
    int soc;
    int acc;
    int ret;
    uint8_t backlog_size = 12;
    char* ip_addr;

    soc = socket(AF_INET, SOCK_STREAM, 0);

    if (soc < 0) {
        // if(errno == ) {}
        perror("socket");
        exit(1);
    }

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    if ((bind(soc, (struct sockaddr*)&s_addr, sizeof(s_addr))) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(soc, backlog_size) < 0) {
        perror("listen");
        exit(1);
    }

    ip_addr = inet_ntoa(s_addr.sin_addr);
    printf("listen...\n");
    printf("address: %s\n", ip_addr);
    printf("port: %d\n", ntohs(s_addr.sin_port));
    printf("\n");

    len = sizeof(c_addr);
    acc = accept(soc, (struct sockaddr*)&c_addr, &len);

    if (acc < 0) {
        perror("accept");
        exit(1);
    }

    ip_addr = inet_ntoa(c_addr.sin_addr);
    printf("listen...\n");
    printf("address: %s\n", ip_addr);
    printf("port: %d\n", ntohs(c_addr.sin_port));
    printf("\n");

    Data data;

    ret = read(acc, &data, sizeof(Data));
    
    if (ret < 0) {
        perror("read");
        exit(1);
    }

    printf("%s %d\n", data.name, data.age);

    close(acc);
    close(soc);

    return 0;
}
