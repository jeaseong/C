#include <stdio.h>
#include <stdlib.h>

int *divisor;

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int N;
    scanf("%d",&N);

    divisor = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        divisor[i] = tmp;
    }

    qsort(divisor, N, sizeof(int), compare);

    int count;

   for(int i = 0; i < N; i++)
   {
       if(N % divisor[i] == 0)
       {
           count = divisor[i];
       }
       
   } 

    int answer = count;
    printf("N: %d\n", answer);

    return 0;
}