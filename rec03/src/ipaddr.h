#ifndef IPADDR_H_
#define IPADDR_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
typedef union {
    uint32_t ip;
    uint8_t octet[4];
} IP_ADDRESS;

char * printIP (void *_ip);
#endif
