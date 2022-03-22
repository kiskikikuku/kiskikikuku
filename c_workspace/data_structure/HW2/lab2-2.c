#include<stdio.h>

int main(){

    int i;
    int *ptr;
    int **dptr;

    i = 1234;
    printf("[---------- [Park Taehyun] ---------- [2018068040] ----------]\n");
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i); // 1234
    printf("address of i == %p\n", &i); // i의 주소
    printf("value of ptr == %p\n", ptr); // 쓰레기값(초기화 되지 않은 포인터)
    printf("address of ptr == %p\n", &ptr); // ptr의 주소

    ptr = &i; /* ptr is now holding the address of i */

    printf("[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i); // 1234
    printf("address of i == %p\n", &i); // i의 주소
    printf("value of ptr == %p\n", ptr); // i의 주소(ptr은 i의 주소를 가리킴)
    printf("address of ptr == %p\n", &ptr); // ptr의 주소
    printf("value of *ptr == %d\n", *ptr); // 1234 (ptr이 가리키는 주소의 값)

    dptr = &ptr; /* dptr is now holding the address of ptr */

    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i); 
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);
    printf("value of *ptr == %d\n", *ptr); // 여기까지 위와 동일
    printf("value of dptr == %p\n", dptr); // ptr의 주소 (dptr은 ptr의 주소를 가리킴)
    printf("address of dptr == %p\n", &dptr); // dptr의 주소
    printf("value of *dptr == %p\n", *dptr); // i의 주소 (dptr이 가리키는 ptr의 값은 i의 주소)
    printf("value of **dptr == %d\n", **dptr); // 1234 (dptr이 가리키는 ptr이 가리키는 i의 값)
    
    *ptr = 7777; // changing the value of *ptr
    
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i); // ptr -> i 이므로 7777
    printf("value of *ptr == %d\n", *ptr); // 7777
    printf("value of **dptr == %d\n", **dptr); // dptr -> ptr -> i 이므로 7777

    **dptr = 8888; // changing the value of **dptr

    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i); // dptr -> ptr -> i 이므로 8888
    printf("value of *ptr == %d\n", *ptr); // ptr -> i 이므로 8888
    printf("value of **dptr == %d\n", **dptr); // 8888

    return 0;
}