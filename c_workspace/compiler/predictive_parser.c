#include<stdio.h>

char nexttoken();

char lookahead;

void main(){
        if(lookahead == '$')
            printf("\n");
        else
            printf(" error\n");
}

void match(char token) {
    if(lookahead == token)
        lookahead = nexttoken();
    else {
            printf("error\n");
            exit(1);
    }
}

char nexttoken(){
    char c;

    while(1){
            c = getchar();
            if(c==' '|| c=='\t'|| c == '\n' || c == '\0') continue;
            return(c);
    }
}

void rest1(){

}

void term() {

}

void rest2() {

}

void factor() {
    
}