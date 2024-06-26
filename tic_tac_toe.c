#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int arr[3][3] ={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int randxy() {
    return rand() % 3;
}

int ingameWinner(){
    int c;
    for (c = 0; c < 3; c++) {
        if (arr[c][0] == arr[c][1] && arr[c][0] == arr[c][2]) {
            if (arr[c][0] == 'O') {
                return 1;
            }
            else if (arr[c][0] == 'X') {
                return 2;
            }
        }
        if (arr[0][c] == arr[1][c] && arr[0][c] == arr[2][c]) {
            if (arr[0][c] == 'O') {
                return 1;
            }
            else if (arr[0][c] == 'X') {
                return 2;
            }
        }
        if (c == 0) {
            if (arr[c][0] == arr[1][1] && arr[c][0] == arr[2][2]) {
                if (arr[c][0] == 'O') {
                    return 1;
                }
                else if (arr[c][0] == 'X') {
                    return 2;
                }
            } else if (arr[c][2] == arr[1][1] && arr[c][2] == arr[2][0]) {
                if (arr[c][2] == 'O') {
                    return 1;
                }
                else if (arr[c][2] == 'X') {
                    return 2;
                }
            }
        }
    }
}

int main(void) {
    int x,y;
    int comx,comy;
    char answer;
    int player;
    int i,j,l,k;
    int winner=0,cnt=0;
    srand(time(NULL));

    printf("플레이어의 인원 수를 입력해주세요(1~2) : \n");
    scanf("%d",&player);
    while(1){
        if(player == 1 || player == 2){
            break;
        }
        else{
            printf("잘못된 입력입니다. 다시 입력해주세요 : \n");
            scanf("%d",&player);
        }
    }
    if(player == 1){
        for (int j = 0; j < 9; j++) {
            if(cnt % 2 == 0) {
                printf("플레이어의 차례입니다.\n");
                printf("위치를 입력해주세요 (x,y) : ");
                scanf("%d %d", &x, &y);
                while (1) {
                    if (arr[x - 1][y - 1] == 'O' || arr[x - 1][y - 1] == 'X') {
                        printf("이미 점령된 자리입니다. 다른 곳을 골라주세요\n");
                        printf("좌표를 입력해주세요 (x,y) : ");
                        scanf("%d %d", &x, &y);
                    } else if ((x > 3 || x < 1) || (y > 3 || y < 1)) {
                        printf("x와 y는 1~3의 범위 내에서 골라주세요\n");
                        printf("좌표를 입력해주세요 (x,y) : ");
                        scanf("%d %d", &x, &y);
                    } else {
                        arr[x - 1][y - 1] = 'O';
                        cnt++;
                        break;
                    }
                }
            }
            else {
                printf("컴퓨터의 차례입니다.\n");
                while(1){
                    comx = randxy();
                    comy = randxy();
                    if(arr[comx][comy] == ' '){
                        arr[comx][comy] = 'X';
                        printf("컴퓨터가 입력한 위치 : (%d, %d)\n",comx+1,comy+1);
                        cnt++;
                        break;
                    }
                }
            }
            for (i = 0; i < 3; i++) {
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
            }

            printf("---|---|---\n");

            if(ingameWinner(arr) == 1){
                printf("플레이어가 승리했습니다.\n");
                winner++;
                cnt = 9;
            }
            else if(ingameWinner(arr) == 2){
                printf("컴퓨터가 승리했습니다.\n");
                winner++;
                cnt = 9;
            }
            if (cnt == 9) {
                if(winner == 0){
                    printf("무승부입니다. ");
                }
                printf("게임이 끝났습니다.\n");
                winner = 0;
                printf("한 번 더 하시겠습니까? (y/n) : \n");
                scanf(" %c", &answer);
                if (answer == 'n') {
                    printf("게임이 종료되었습니다.");
                    return 0;
                } else if (answer == 'y') {
                    cnt = 0;
                    j = -1;
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            arr[k][l] = ' ';
                        }
                    }
                }
            }
        }
    }
    else if(player == 2) {
        for (j = 0; j < 9; j++) {
            printf("위치를 입력해주세요 (x,y) : ");
            scanf("%d %d", &x, &y);
            while (1) {
                if (arr[x - 1][y - 1] == 'O' || arr[x - 1][y - 1] == 'X') {
                    printf("이미 점령된 자리입니다. 다른 곳을 골라주세요\n");
                    printf("좌표를 입력해주세요 (x,y) : ");
                    scanf("%d %d", &x, &y);
                } else if ((x > 3 || x < 1) || (y > 3 || y < 1)) {
                    printf("x와 y는 1~3의 범위 내에서 골라주세요\n");
                    printf("좌표를 입력해주세요 (x,y) : ");
                    scanf("%d %d", &x, &y);
                } else {
                    break;
                }
            }
            if (cnt % 2 == 0) {
                arr[x - 1][y - 1] = 'O';
                cnt++;
            } else {
                arr[x - 1][y - 1] = 'X';
                cnt++;
            }
            for (i = 0; i < 3; i++) {
                printf("---|---|---\n");
                printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
            }
            printf("---|---|---\n");

            if(ingameWinner(arr) == 1){
                printf("1번 플레이어가 승리했습니다.\n");
                winner++;
                cnt = 9;
            }
            else if(ingameWinner(arr) == 2){
                printf("2번 플레이어가 승리했습니다.\n");
                winner++;
                cnt = 9;
            }

            if (cnt == 9) {
                if(winner == 0){
                    printf("무승부입니다. ");
                }
                printf("게임이 끝났습니다.\n");
                winner = 0;
                printf("한 번 더 하시겠습니까? (y/n) : \n");
                scanf(" %c", &answer);
                if (answer == 'n') {
                    printf("게임이 종료되었습니다.");
                    return 0;
                } else if (answer == 'y') {
                    cnt = 0;
                    j = -1;
                    for (k = 0; k < 3; k++) {
                        for (l = 0; l < 3; l++) {
                            arr[k][l] = ' ';
                        }
                    }
                }
            }
        }
    }
}
