#include<stdio.h>
#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

void main(void){

    char list[4] = {'A', 'B', 'C', 'D'};
    perm(list, 0, 3);
}


void perm(char *list, int i, int n){ 
    int j, temp;
    
    if(i==n){ // i가 배열의 끝에 도달하면 출력
        for (j = 0; j <=n; j++)
        {
            printf("%c", list[j]);
        }       
        printf("    ");
    }

    else{
        for (j = i; j <= n; j++)
        {
            SWAP(list[i], list[j], temp);
            perm(list, i+1, n);
            SWAP(list[i], list[j], temp);
        }
        


    }

    
}