#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t) )

void sort(int [], int); // selection sort

void main(void)
{
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of to generate: "); 
    scanf("%d", &n); // 배열 크기 입력받기

    if(n<1 || n>MAX_SIZE)
    {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) // 배열에 랜덤 숫자 추가하기
    {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }
    selection_sort(list, n);
    printf("\n Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    
}

int compare(int x, int y){ // compare (two integers)
// compare x and y, return -1 for less than, 0 for equal, 1 for greater
    if (x<y)
        return -1;
    
    else if (x==y) return 0;

        else return 1;

}

void selection_sort(int list[], int n) // selection sort (integer array)
{
    int i, j, min, temp;
    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++)
            if(list[j]<min)
                min = j; //최솟값 위치 지정
        SWAP(list[i], list[min], temp); // 최솟값을 맨 앞과 자리 변경
    }
}

int binary_search(int list[], int searchnum, int left, int right){ // binary search (integer array)
    int middle;
    while(left <= right){
        middle = (left+right)/2;
        switch (compare(list[middle], searchnum))
        {
        case -1: 
            left = middle+1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle-1;
        }
    }

    return -1;
}

