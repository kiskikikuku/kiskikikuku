#include<stdio.h>

int main()
{
    int i, *p; // 정수형 변수 i와 정수형 포인터 변수 p 선언

    i = 10; // i에 10 대입

    printf("value of i = %d\n", i); // i의 값 출력 -> 10
    printf("address of i = %p\n", &i); // i의 주소 출력
    printf("value of p = %p\n", p); // p가 가리키는 주소 출력(초기화 하지 않아 덤프값)
    printf("address of p = %p\n", &p); // p의 주소 출력
    
    p = &i; //p에 i의 주소 대입(p가 가리키는 주소는 i의 주소가 됨)

    printf("\n\n----- after p = &i ------------\n\n");

    printf("value of p = %p\n", p); // p가 가리키는 주소인 i의 주소 출력
    printf("address of p = %p\n", &p); // p의 주소 출력
    printf("dereferencing *p = %d\n", *p); // p가 가리키는 주소에 저장된 값(i의 값) 출력 (10)

    return 0;
}