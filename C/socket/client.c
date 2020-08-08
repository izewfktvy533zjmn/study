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
#define ADDR "127.0.0.1"

typedef struct data {
    char name[8];
    uint8_t age;
} Data;

int main(int argc, char* argv[]) {
    struct sockaddr_in s_addr;
    int len;
    int soc;
    int ret;

    if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        //if(errno == ) {}
        perror("");
        exit(1);
    }

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    ret = inet_pton(AF_INET, ADDR, &s_addr.sin_addr.s_addr);
    if(ret == 0) {
        fprintf(stderr, "Not in presentation format");
    }
    else if(ret < 0) {
        //if(errno == ) {}
        perror("");
        exit(1);
    }

    if(connect(soc, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0) {
       //if(errno == ) {}
        perror("");
        exit(1);
    }
    
    Data data = { "Taichi", 23 };

    if((len = write(soc, &data, sizeof(data))) < 0) {
        //if(errno == ) {}
        perror("");
        exit(1);
    }

    printf("%d, %s %d\n", len, data.name, data.age);

    if(close(soc) < 0) {
        //if(errno == ) {}
        perror("");
        exit(1);
    }

}
