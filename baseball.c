#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randnum() {
    return rand() % 10;
}

int duplication (int com[],int size,int num){
    for(int d=0; d<size; d++){
        if(com[d] == num){
            return 1;
        }
    }
    return 0;
}

void baseball (int arr[], int size){
    int com[size],num;
    for(int clear=0; clear<size; clear++){
        com[clear] = -1;
    }
    srand(time(NULL));
    for(int i=0; i<size; i++){
        num = randnum();
        while(duplication(com,size,num)){
            num = randnum();
        }
        com[i] = num;
        arr[i] = com[i];
    }
}

void strikeball (int answer[], int arr[],int len,int *strike,int *ball){
    for(int a=0; a<len; a++){
        for(int b=0; b<len; b++) {
            if (answer[a] == arr[b]){
                if(a == b){
                    (*strike)++;
                }
                else{
                    (*ball)++;
                }
            }
        }
    }
}

int howlong(char input[]){
    int length=0;
    while(input[length] != '\0'){
        length++;
    }
    return length;
}

int main(void) {
    int len;
    int arr[len];
    int strike=0, ball=0;
    int cnt=1,win=0;

    printf("플레이 할 숫자의 자릿수(2~10) :");
    scanf("%d",&len);
    getchar();

    while(1){
        if(len < 2 || len > 10){
            printf("잘못 입력하셨습니다.\n");
            printf("다시 입력해주세요(2~10) :");
            scanf("%d",&len);
        }
        else{
            break;
        }
    }

    printf("%d자리 숫자야구를 시작합니다.\n",len);
    printf("숫자는 중복 될수 없습니다.\n");
    baseball(arr,len);

    while(win != 1) {
        printf("%d번째 시도 : ", cnt);
        char input[len];
        gets(input);
        int length;
        length = howlong(input);

        if(length != len) {
            while (length != len) {
                printf("잘못된 입력입니다. 다시 입력해주세요.");
                gets(input);
                length = howlong(input);
            }
        }

        int answer[len];
        for (int c = 0; c < len; c++) {
            answer[c] = input[c] - '0';
        }

        strikeball(answer, arr, len, &strike, &ball);

        if(strike == len){
            printf("%d스트라이크 입니다. %d번 만에 승리했습니다.",strike,cnt);
            win = 1;
        }
        else {
            printf("%d볼 %d스트라이크\n", ball, strike);
            cnt++;
        }
        strike = 0;
        ball = 0;
    }
}
