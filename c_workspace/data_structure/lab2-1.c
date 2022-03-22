#include<stdio.h>
int main(){
    char charType;
    int integerType;
    float floatType;
    double doubleType;
    printf("[---------- [Park Taehyun] ---------- [2018068040] ----------]\n");
    printf("Size of char : %ld byte\n", sizeof(charType));
    printf("Size of int  : %ld byte\n", sizeof(integerType));
    printf("Size of float : %ld byte\n", sizeof(floatType));
    printf("Size of double : %ld byte\n", sizeof(doubleType)); // 각 타입 변수들의 크기 출력 (1, 4, 4, 8 바이트)

    printf("-----------------------------------------\n");

    printf("Size of char : %ld byte\n", sizeof(char));
    printf("Size of int  : %ld byte\n", sizeof(int));
    printf("Size of float : %ld byte\n", sizeof(float));
    printf("Size of double : %ld byte\n", sizeof(double)); // 각 타입의 크기 출력 (1, 4, 4, 8 바이트)

    printf("-----------------------------------------\n");

    printf("Size of char* : %ld byte\n", sizeof(char*));
    printf("Size of int*  : %ld byte\n", sizeof(int*));
    printf("Size of float* : %ld byte\n", sizeof(float*));
    printf("Size of double* : %ld byte\n", sizeof(double*)); //각 타입 포인터형의 크기 출력 (32비트 컴파일러이므로 전부 4바이트이다)


    return 0;
}