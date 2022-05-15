#include<stdio.h>

int getLCM(int a, int b, int gcd){ // 두 정수의 최소공배수를 반환해주는 함수

    int lcm = a * b / gcd;
    return lcm;
}

int getGCD(int a, int b){ // 두 정수의 최대공약수를 반환해주는 함수 (유클리드 호제법)
    int mod = a % b; // 나머지

    while(mod > 0){

        a = b;
        b = mod;
        mod = a%b;
    
    }

    return b;
}

int main(){

    int a, b;
    scanf("%d%d", &a, &b);

    printf("LCM of A and B : %d , GCD of A and B : %d \n", getLCM(a, b, getGCD(a,b)), getGCD(a,b));

}