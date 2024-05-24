#include <stdio.h>

int main(void) {
    int arr[3][3] ={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int x,y;
    char answer;
    int c;
    int k,l;
    int i,j;
    int cnt=0;
    for(j=0;j<9;j++) {
        printf("위치를 입력해주세요 (x,y) : ");
        scanf("%d %d", &x, &y);
        while (1) {
            if(arr[x - 1][y - 1] == 'O' || arr[x - 1][y - 1] == 'X'){
                printf("이미 점령된 자리입니다. 다른 곳을 골라주세요\n");
                printf("좌표를 입력해주세요 (x,y) : ");
                scanf("%d %d", &x, &y);
            }
            else if((x > 3 || x < 1) || (y > 3 || y < 1)){
                printf("x와 y는 1~3의 범위 내에서 골라주세요\n");
                printf("좌표를 입력해주세요 (x,y) : ");
                scanf("%d %d", &x, &y);
            }
            else {
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
        for(c=0;c<3;c++){
            if(arr[c][0] == arr[c][1] && arr[c][0] == arr[c][2]){
                if(arr[c][0] == 'O'){
                    printf("1번 플레이어가 승리했습니다.\n");
                    cnt = 9;
                    break;
                }
                else if(arr[c][0] == 'X'){
                    printf("2번 플레이어가 승리했습니다.\n");
                    cnt = 9;
                    break;
                }
            }
            if(arr[0][c] == arr[1][c] && arr[0][c] == arr[2][c]){
                if(arr[0][c] == 'O'){
                    printf("1번 플레이어가 승리했습니다.\n");
                    cnt = 9;
                    break;
                }
                else if(arr[0][c] == 'X'){
                    printf("2번 플레이어가 승리했습니다.\n");
                    cnt = 9;
                    break;
                }
            }
            if(c == 0){
                if(arr[c][0] == arr[1][1] && arr[c][0] ==  arr[2][2]){
                    if(arr[c][0] == 'O'){
                        printf("1번 플레이어가 승리했습니다.\n");
                        cnt = 9;
                        break;
                    }
                    else if(arr[c][0] == 'X'){
                        printf("2번 플레이어가 승리했습니다.\n");
                        cnt = 9;
                        break;
                    }
                }
                else if(arr[c][2] == arr[1][1] && arr[c][2] ==  arr[2][0]){
                    if(arr[c][2] == 'O'){
                        printf("1번 플레이어가 승리했습니다.\n");
                        cnt = 9;
                        break;
                    }
                    else if(arr[c][2] == 'X'){
                        printf("2번 플레이어가 승리했습니다.\n");
                        cnt = 9;
                        break;
                    }
                }
            }
        }
        if(cnt == 9){
            printf("게임이 끝났습니다.\n");
            printf("한 번 더 하시겠습니까? (y/n) : \n");
            scanf(" %c",&answer);
            if(answer == 'n'){
                printf("게임이 종료되었습니다.");
                return 0;
            }
            else if(answer == 'y'){
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
