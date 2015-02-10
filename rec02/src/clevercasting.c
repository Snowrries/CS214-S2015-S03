#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
#define PLAW plaw(__LINE__);
void plaw(int i) {
    char buf[100] = {0};
    printf("\nLINE: %i\n", i);
    fgets(buf, 100, stdin);
}

int main(int argc, char **argv)
{
    //Is there anything wrong with this?
    PLAW uint32_t *u32_arr = malloc(sizeof(uint8_t));
    u32_arr[0] = 0xff;
    u32_arr[1] = 0x000aa;
    PLAW printf("%i, 0x%x\n", u32_arr[0], u32_arr[0]);
    PLAW printf("%i, 0x%x\n", u32_arr[1], u32_arr[1]);
    free(u32_arr);

    PLAW u32_arr = malloc(sizeof(uint32_t) * 4);
    uint8_t ui8 = 15;
    u32_arr[0] = ui8;

    PLAW
    //What does this loop do?
    for (int i = 0; i < 14; i++) {
        printf("0x%x\n", u32_arr[0]);
        u32_arr[0] <<= 2;
    }
    printf("0x%x\n", u32_arr[0]);

    //We'll talk about operator precedence later
    PLAW u32_arr[0] |= (0xaabb << 4 * 4 | 0xccdd);
    printf("0x%x\n", u32_arr[0]);
    
    PLAW u32_arr[0] &= 0xaabbffff;
    printf("0x%x\n", u32_arr[0]);

    PLAW printf("0x%x\n", (uint16_t)u32_arr[0]);
    PLAW printf("0x%x\n", (uint8_t)u32_arr[0]);
    //Some interesting pointer math
    PLAW printf("0x%x\n",  ((uint16_t *)(void *)u32_arr)[0]);
    //Some veeeery interesting pointer math
    PLAW printf("0x%x\n",  ((uint16_t *)&(((uint8_t *)u32_arr)[1]))[0]);

    uint32_t *u32_arr2 = &u32_arr[0];
    *u32_arr2 = htonl(u32_arr[0]);
    PLAW printf("0x%x\n",  ((uint16_t *)&(((uint8_t *)u32_arr2)[1]))[0]);
    printf("0x%x\n", *u32_arr2);
    
    free(u32_arr);
}
