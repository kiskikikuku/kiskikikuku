#include<stdio.h>
#include<stdlib.h>

char nextchar();
char nexttoken();
void expr();
void rest1();
void term();
void rest2();
void factor();

char lookahead;

void main(){
        lookahead = nextchar();
        expr();
        if(lookahead == '$')
            printf("\n");
        else
            printf(" error\n");

}

void match(char token) {
    if(lookahead == token)
        lookahead = nextchar(); //예측기호와 같으면 다음 토큰을 받음
    else {
            printf(" error\n");
            exit(1);
    }
}


char nexttoken(){

    char c;

    while(1){
            c = getchar(); // 문자 1개를 토큰으로 입력받음
            if(c==' '|| c=='\t'|| c == '\n' || c == '\0') continue; // 공백, 줄바꿈,탭, NULL문자의 경우에 한하여 다시 입력받음
            return(c); // 입력받은 토큰값을 반환
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
        printf("error \n"); exit(1); //연산기호가 두번 연속 들어오는 경우 체크
    }
    return;
}


