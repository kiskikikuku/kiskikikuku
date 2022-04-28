#include<stdio.h>
#include<stdlib.h>

#define MAX_ELE 200
#define HEAP_FULL(n) (n == MAX_ELE -1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
    int key;
}element;

element heap[MAX_ELE];
int n = 0;

void push(element item, int *n);
element pop(int *n);

void main(){



    return;
}

void push(element item, int* n){

    int i;
    if(HEAP_FULL(*n)){
        printf(stderr, "Heap is full\n");
        exit(1);
    }

    i = ++(*n);
    while ((i != 1) && (item.key > heap[i/2].key)){
        heap[i] = heap [1/2];
        i /=2;
    }

    heap[i] = item;
}

element pop(int *n){
    int parent, child;
    element item, temp;

    if(HEAP_EMPTY(*n)){
        printf(stderr, "Heap is empty\n");
        exit(1);
    }
    
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while(child <= *n){
        if ((child<*n) && (heap[child].key < heap[child+1].key))
            child++; // right child쪽에서 max 발견
        if (temp.key >= heap[child].key) break; // max 찾기
        heap[parent]  = heap[child]; // 현재 레벨의 max를 부모로
        parent = child; // 현재 레벨을 parent로
        child *= 2; // 다음레벨의 leftchild
    }
    heap[parent]  = temp;
    return item;
}




