/**
  *Author:      yulmx
**/
#include <stdio.h>
#include <stdlib.h>

#define USE_BIT_OPERATION 1

#if USE_BIT_OPERATION
void ConvertUint8ToUint32() {
    __uint32_t result;
    __uint8_t buff[4] = {0x12, 0x34, 0x56, 0x78};
 
    result = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3] << 0);

    printf("old: %x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
    printf("new: %x\n", result);
}

void ConvertUint32ToUint8() {
    __uint32_t result = 0x12345678;
    __uint8_t buff[4];

    buff[0] = result >> 24;
    buff[1] = result >> 16;
    buff[2] = result >> 8;
    buff[3] = result >> 0;

    printf("old: %x\n", result);
    printf("new: %x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
}
#else
#include <string.h>
void ConvertUint8ToUint32() {
    __uint32_t result;
    __uint8_t buff[4] = {0x12, 0x34, 0x56, 0x78};

    memcpy(&result, buff, 4);

    printf("old: %x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
    printf("new: %x\n", result);
}
void ConvertUint32ToUint8() {
    __uint32_t result = 0x12345678;
    __uint8_t buff[4];

    memcpy(buff, &result, 4);

    printf("old: %x\n", result);
    printf("new: %x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
}
#endif /* USE_BIT_OPERATION */



int main() {
    ConvertUint8ToUint32();
    ConvertUint32ToUint8();
    
    return 0;
}