#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int number[11] ={2,3,5,10,15,89,4,5,6,11,18};
    int numSize = sizeof(number) / sizeof(int);

    qsort(number, numSize, sizeof(int), compare);

    

    for(int i = 0; i < numSize - 1; i++)
    {
        if(number[i] == number[i + 1])
        {
            memmove(number+i + 1, number + i + 2, numSize - i);
        }
        
    }
    for(int i = 0; i < numSize - 1; i++)
    {
        printf("%d\n", number[i]);
    }

    return 0;
}

//Big O(n^) 이라고 생각한다.
// 정렬과 중복 제거가 동시에 이루어질 수 있으면 더 빠른 답이 있지 않을까 생각한다.
// 어느 블로그 글을 보면 병합정렬의 변형을 이용하여 n log n으로 나온다고 하지만 아직 이해가 되지 않았다.