#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <arpa/inet.h> 

int main(void) {
    struct sockaddr_in *saddr = malloc(sizeof(*saddr));
    inet_aton("192.168.10.45", &saddr->sin_addr);
    printf("%s\n", inet_ntoa(saddr->sin_addr));
    return 0;
}
