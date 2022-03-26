#include<stdio.h>
#include<stdlib.h>
char nexttoken();
void expr();
void rest1();
void term();
void rest2();
void factor();
char lookahead;

void main(){
        lookahead = nexttoken();
        expr();
        if(lookahead == '$')
            printf("\n");
        else
            printf(" error\n");

}

void match(char token) {
    if(lookahead == token)
        lookahead = nexttoken(); //예측기호와 같으면 다음 토큰받음
    else {
            printf(" error\n");
            exit(1);
    }
}

char nexttoken() {
    char c;

    while(1){
            c = getchar();
            if(c==' '|| c=='\t'|| c == '\n' || c == '\0') continue;
            return(c);
    }
}

void expr(){
    if (isdigit(lookahead) || lookahead =='(')
    {
        term(); printf("3 "); rest1();
    }
    
    return;
}

void rest1(){
    if (lookahead == '+'){
        match('+'); term(); printf("1 "); rest1();
    }
    else if(lookahead == '-'){
        match('-'); term(); printf("2 "); rest1();
    }
    else return;

}

void term(){
    factor(); printf("6 "); rest2();
}

void rest2(){
    if (lookahead == '*'){
        match('*'); factor(); printf("4 "); rest2();
    }
    else if(lookahead == '/'){
        match('/'); factor(); printf("5 "); rest2();}
    
    else return;
}

void factor(){
    if (lookahead == '('){
        match('('); expr(); match(')'); printf("7 ");
    }
    else if (isdigit(lookahead)){
        match(lookahead);
    }
    else{
        printf("error "); exit(1); //연산기호가 두번 연속 들어오면 에러
    }
    return;
}


