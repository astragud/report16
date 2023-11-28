#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

int com = 0, swaps = 0;
int sorted[MAX_SIZE];

static void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l, comparisons = 0, moves = 0;
    i = left; j = mid + 1; k = left;

    // 분할 정렬된 list의 합병
    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
        {
            sorted[k++] = list[i++];
        }

        else
        {
            sorted[k++] = list[j++];
        }
        comparisons++; // 비교 횟수 증가
        moves++; // 이동 횟수 증가
    }
   
    if (i > mid) // 남아 있는 레코드의 일괄 복사
    {
        for (l = j; l <= right; l++)
        {
            sorted[k++] = list[l];
            moves++; // 이동 횟수 증가
        }
    }

    else // 남아 있는 레코드의 일괄 복사
    {
        for (l = i; l <= mid; l++)
        {
            sorted[k++] = list[l];
            moves++; // 이동 횟수 증가
        }
    }
   
    // 배열 sorted[]의 리스트를 배열 list[]로 복사
    for (l = left; l <= right; l++)
    {
        list[l] = sorted[l];
    }
    com = com + comparisons;
    swaps = swaps + moves;
}



static void merge_sort(int list[], int left, int right, int k)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2; // 리스트의 균등분할
        merge_sort(list, left, mid, k); // 부분리스트 정렬
        merge_sort(list, mid + 1, right, k);//부분리스트 정렬
        
        if (k == 0)
        {
            for (int i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", list[i]);
            }
            printf("\n");
        }

        merge(list, left, mid, right); // 합병
    }
}

int main()
{
    com = 0, swaps = 0;
    int list[MAX_SIZE]{};
    srand(time(NULL));

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            list[i] = rand() % 100;
        }

        if (j == 0)
        {// 초기 배열 출력
            printf("초기 배열\n");
            for (int i = 0; i < MAX_SIZE; i++)
            {
                printf("%d ", list[i]);
            }
            printf("\n\n");

        }

        // 합병 정렬 수행
        if (j == 0)
        {
            printf("Merge Sort\n");
        }
        
        merge_sort(list, 0, MAX_SIZE - 1, j);
    }
    
    printf("average compare count  : %d\n", com / 20);
    printf("average move count  : %d\n", swaps / 20);
    return 0;
}