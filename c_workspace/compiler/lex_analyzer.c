#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


int state=0; // 상태 번호
char* lexbuf[30]; // 렉심 버퍼
char c; // 문자 저장
int lexeme_count = 0; // 렉심 인덱스

char nextchar();
int fail();

void main(){

    
    while(1){

        switch (state)
        {
        case 0: c= nextchar();
                if (isalpha(c)) //알파벳이면
                {
                     if (c=='f') state = 1; //f인 경우 -> state 1
                     else if (c=='i') state = 4; // i인 경우 -> state 4
                     else state = 8; // 나머지 문자인 경우 -> state 8
                }

                else state = fail();
                break;
                
        case 1: c = nextchar();
                if (isalpha(c))
                {
                    if(c=='o') state = 2; // fo 까지 들어온 경우
                    else state = 8;
                }
                else if (isdigit(c)) 
                {
                    state = 8;
                }
                else state = 11;

        case 2: 
                
                


        default:
            break;
        }

    }



    
}




int fail(){


}


char nextchar() {
    char c;
    while(1){
            c = getchar(); // 문자 1개를 입력받음
            if(c==' '|| c=='\t'|| c == '\n' || c == '\0') {
                continue; // 공백, 줄바꿈,탭, NULL문자의 경우에 한하여 다시 입력받음
            }
            strcat(lexbuf, c); // 입력받은 문자를 렉심버퍼에 대입
            lexeme_count++; // 렉심버퍼 하나 +
            return(c); // 입력받은 문자를 반환
    }
} 