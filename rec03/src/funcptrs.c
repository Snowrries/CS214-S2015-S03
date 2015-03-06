#include <stdio.h>
#include <stdlib.h>
#include "ipaddr.h"

int main(int argv, char **args) {
    IP_ADDRESS gateway, arkanoid, dns, totoro;
    gateway.ip = 3232235777; 
    arkanoid.ip = 2147878176;
    dns.ip = 134744072;
    totoro.ip = 2165649803;
    IP_ADDRESS ips[] = {gateway, arkanoid, dns, totoro};

    char * (*printfunc)(void *);
    printfunc = &printIP;
    for (int i = 0; i < 4; i++) {
        printf("%u\n", ips[i].ip);
        char *s = printfunc(&ips[i]);
        puts(s);
        free(s);
    }   
}
