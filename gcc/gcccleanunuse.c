/**
  *Author:      yulmx
**/
#include <stdio.h>
#include <stdlib.h>

void func0(void)
{
    printf("%s: %d\n", __FUNCTION__, __LINE__);
}

void func1(void)
{
    printf("%s: %d\n", __FUNCTION__, __LINE__);
}

void func2(void)
{
    printf("%s: %d\n", __FUNCTION__, __LINE__);
}

void func3(void)
{
    printf("%s: %d\n", __FUNCTION__, __LINE__);
}


int main() {
    func1();
    func3();
    
    return 0;
}