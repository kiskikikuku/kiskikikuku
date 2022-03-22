#include<stdio.h>
#include<stdlib.h>

void main(){
    int list[5];
    int *plist[5] = {NULL, };

    plist[0] = (int *)malloc(sizeof(int)); // plist[0]에 int*형의 공간(4바이트)를 할당한다.

    list[0] = 1; // list[0] 에 1을 대입
    list[1] = 100; // list[1] 에 100을 대입

    *plist[0] = 200; // plist[0]이 가리키는 주소에 200을 대입

    printf("value of list[0] = %d\n", list[0]); // list[0]의 값 -> 1
    printf("address of list[0] = %p\n", &list[0]); // list[0]의 주소
    printf("value of list = %p\n", list); // list값 
    printf("address of list (&list) = %p\n", &list); // list의 주소


    printf("----------------------------------------\n\n");
    printf("value of list[1] = %d\n", list[1]); // list[1]의 값 -> 100
    printf("address of list[1] = %p\n", &list[1]); // list[1]의 주소
    printf("value of *(list+1) = %d\n", *(list+1)); // (list+1)이 가리키는 주소의 값 -> (list+1) == &list[1] -> 100이 출력된다.
    printf("address of list+1 = %p\n", list+1); // list+1 == &list[1] -> list[1]의 주소가 출력된다.

    
    printf("----------------------------------------\n\n"); 

    printf("value of *plist[0] = %d\n", *plist[0]); // plist[0]이 가리키는 주소의 값을 출력 -> 200
    printf("&plist[0] = %p\n", &plist[0]); // plist[0]의 주소
    printf("&plist = %p\n", &plist); // &plist[0]과 같은 값
    printf("plist = %p\n", plist); // &plist]과 같은 값
    printf("plist[0] = %p\n", plist[0]); //plist[0]이 가리키고 있는 주소(정수 200이 저장된 주소)를 출력한다.
    printf("plist[1] = %p\n", plist[1]);
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]); // plist[0]~plist[4]-> NULL로 초기화 한 후 값이 할당된 적이 없으므로 0이 출력된다.

    free(plist[0]);

    return;
}