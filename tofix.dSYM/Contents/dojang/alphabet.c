#include <stdio.h>

int main()
{
    int money;
    scanf("%d", &money);

    while(money >= 0)
    {
        money = money - 1200;
        printf("%d", money);
    }
    return 0;
}