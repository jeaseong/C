#include <stdio.h>

int main()
{
    unsigned char flag = 0;

    flag |= 1; //0000 0001 마스크와 비트 OR로 여덟 번쨰 비트를 켬
    flag |= 2; //0000 0010 마스크와 비트 OR로 일곱 번쨰 비트를 켬
    flag |= 4; //0000 0100 마스크와 비트 OR로 여섯 번쨰 비트를 켬

    printf("%u\n", flag);

    if(flag & 1)
        printf("0000 00001은 켜져 있음\n");
    else
        printf("0000 00001은 꺼져 있음\n");
    flag = 0;
    flag |= 1; // 0000 0001 마스크와 비트 비트 OR로 여덟 번째 비트를 켬
    printf("%u", flag);
    
    flag = 7;
    flag ^= 2;
    flag ^= 8;
    printf("%u", flag);

}