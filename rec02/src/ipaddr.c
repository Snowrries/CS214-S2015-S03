#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

typedef union {
    uint32_t ip;
    uint8_t octet[4];
} IP_ADDRESS;

void printIP (IP_ADDRESS ip) {
    printf("IP is: %d.%d.%d.%d\n",
            ip.octet[3],
            ip.octet[2],
            ip.octet[1],
            ip.octet[0]
          );
    for (int i = 3; i > -1; i--) {
        printf("Octet %d is 0x%x\n", i + 1, ip.octet[i]);
    }
    puts("");
    return;
}

int main(int argv, char **argc) {
    IP_ADDRESS gateway, arkanoid, dns, totoro;
    gateway.ip = 3232235777; 
    arkanoid.ip = 2147878176;
    dns.ip = 134744072;
    totoro.ip = 2165649803;
    printIP(gateway);
    printIP(arkanoid);
    printIP(dns);
    printIP(totoro);
}
