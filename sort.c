#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{


    int number[] ={2,3,10,5,15,5,4,5,11,18,18};
    int numSize = sizeof(number) / sizeof(int);
    int i;

    qsort(number, numSize, sizeof(int), compare);

    

    for(i = 0; i < numSize - 1; i++)
    {
        for(int j = 0; j < numSize - 1; j++)
        {
                if(number[j] == number[j + 1])
            {
                memmove(number + j + 1, number+ j + 2, sizeof(int));
                
            }
        }
    }

    for(int i = 0; i < numSize - 1; i++)
    {
        if(number[i] != number[i+1])
            printf("%d\n", number[i]);
    }
    return 0;
}

//Big O(n^) 이라고 생각한다.
// 정렬과 중복 제거가 동시에 이루어질 수 있으면 더 빠른 답이 있지 않을까 생각한다.
// 어느 블로그 글을 보면 병합정렬의 변형을 이용하여 n log n으로 나온다고 하지만 아직 이해가 되지 않았다.