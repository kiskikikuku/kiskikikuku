#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int state=0; // 상태 번호
char c; // 문자 저장

char nextchar(); // 다음 문자를 받음
int retraction(); // other의 경우, 처리해주는 함수
void main(){
    printf("-------------[2018068040]-----[Park Taehyun]-------------\n");
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

                else state = retraction(); // 나머지는 fail
                break;
                
        case 1: c = nextchar();
                if (isalpha(c))
                {
                    if(c=='o') state = 2; // fo 까지 들어온 경우
                    else state = 8;
  
                }
                else if (isdigit(c)) // f 다음 숫자인 경우
                {
                    state = 8; // state = 8
                }
                else {
                    printf("9 ");
                    state = retraction();
                }
                break;

        case 2: c = nextchar(); // 문자 하나 받기
                if(isalpha(c)){
                     if(c=='r') state = 3; // for 까지 들어온 경우
                    else state = 8;
                }
                else if (isdigit(c)){ // fo숫자의 경우
                    state = 8;
                }
                else {
                    printf("9 ");
                    state = retraction();
                }
                break;

        case 3: c = nextchar(); // for까지 받은 상태, 문자 하나 받기
                if (isalpha(c) || isdigit(c)) // 다음 문자가 알파벳이나 숫자인 경우 -> id
                {
                    state = 8;
                }

                else {  // for
                    printf("1 ");
                    state = retraction(); // 다음 문자는 invalid이므로 fail처리
                }
                break;
        
        case 4: c = nextchar(); // i까지받은 상태
                if(isalpha(c)){
                    if(c == 'f') // f인 경우 
                        state = 5; // state = 5
                    else if (c == 'n')
                        state = 6; // n인 경우 state = 6
                }
                else if (isdigit(c)) //숫자의 경우 -> id
                    state = 8; // state = 8로
                else{ //외의 문자
                    printf("9 "); //i까지는 식별자임
                    state = retraction(); // 그 다음 문자는 invalid 처리
                } 

                break;

        case 5: c = nextchar(); // if까지 받은 상태, 문자 하나 받기        
                if (isalpha(c) || isdigit(c)) // 다음 문자가 알파벳이나 숫자인 경우 -> id
                {
                    state = 8;
                }

                else {  // if
                    printf("2 ");
                    state = retraction(); // 다음 문자는 invalid이므로 fail처리
                }

                break;

        case 6: c = nextchar(); // in까지 받은 상태
                if (isalpha(c))
                {
                    if(c == 't') // 다음 문자 t
                        state = 7;
                    else  //외의 문자인 경우 -> id
                        state = 8; 
                }
                else if (isdigit(c)) // 숫자인 경우 -> id
                    state = 8;

                else{ // 외의 문자는 other임
                    printf("9 ");
                    state = retraction();
                }
                break;
        
        case 7: c = nextchar(); // int까지 받은 상태
                if (isalpha(c) || isdigit(c)) // 다음 문자가 알파벳이나 숫자인 경우 -> id
                {
                    state = 8; // state = 8
                }

                else {  // int
                    printf("3 "); // int가 인식됨, print 3
                    state = retraction(); // 다음 문자는 invalid이므로 fail처리
                }

                break;

        case 8: c= nextchar();
                if (isalpha(c) || isdigit(c)) // 다음 문자가 알파벳이나 숫자인 경우 -> id
                {
                    state = 8;
                }

                else { // other, 지금까지 인식된 문자들은 식별자토큰(print 9)
                    printf("9 ");
                    state = retraction(); 
                }
        default:
            break;
        }
    }
}

int retraction(){ // Invalid char의 경우, 리트랙션
    if(c == '$') //$면 종료
        exit(0);
    printf("Invalid char '%c' \n", c); // 나머지의 경우, 출력해준다.

    return 0; // state 0으로 보낸다
}

char nextchar() { //문자를 입력받는다 개행문자는 skip, 입력받은 문자 반환
    char c;
    while(1){
            c = getchar(); // 문자 1개를 입력받음
            if(c==' '|| c=='\t'|| c == '\n' || c == '\0') {
                continue; // 공백, 줄바꿈,탭, NULL문자의 경우에 한하여 다시 입력받음
            }
            return(c); // 입력받은 문자를 반환
    }
} 