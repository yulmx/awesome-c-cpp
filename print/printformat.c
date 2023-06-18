/**
  *Author:      yulmx
**/
#include <stdio.h>
#include <stdlib.h>


// flag: 对齐相关
void PrintWithFlag(void) {
    printf("-: '%-6d'\n", 123);
    printf("+: '%+6d'\n", 123);
    printf("+: '%+6d'\n", -123);
    printf("#: '%#x'\n", 0x123);
    printf("0: '%06d'\n", 123);
    printf("blankspace: '% d'\n", 123);
    printf("blankspace: '% d'\n", -123);
}

// 精度: 表示最大长度
void PrintPrecision(void) {
    printf("'%.6d'\n", 123);
    printf("'%.3d'\n", 1234);
    printf("'%5.3f'\n", 1.23567);
    printf("'%5.3f'\n", 1.23);
    printf("'%.5s'\n", "a.bc");
    printf("'%.5s'\n", "a.bcdefg");
}


void PrintNumber(void) {
    __uint32_t num = 0x123456abc;
    __uint64_t num1 = 0x123456abc;
    printf("%x: %lu\r\n", num, num);
    printf("%x: %llu\r\n", num1, num1);
}

void PrintCases(void) {
    PrintNumber();
    PrintWithFlag();
    PrintPrecision();
}



int main() {
    PrintCases();
    
    return 0;
}