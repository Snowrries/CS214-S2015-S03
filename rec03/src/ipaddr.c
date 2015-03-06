#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "ipaddr.h"


char * printIP (void *_ip) {
    uint32_t *ip = _ip;
    IP_ADDRESS addr;
    addr.ip = *ip;
    
    char *s;
    asprintf(&s, "%d.%d.%d.%d\n",
            addr.octet[3],
            addr.octet[2],
            addr.octet[1],
            addr.octet[0]
          );
    return s;
}
