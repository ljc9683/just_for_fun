#include <stdio.h>

int main(void) {
    int arr[3][3] ={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int x,y;
    char answer;
    int i,j;
    int cnt=0;
    for(j=0;j<9;j++) {
        printf("위치를 입력해주세요 (x,y) : ");
        scanf("%d %d", &x, &y);
        while (arr[x - 1][y - 1] != ' ') {
            if (x != 1 || x != 2 || x != 3 || y != 1 || y != 2 || y != 3) {
                printf("x와 y는 1~3의 범위 내에서 골라주세요\n");
                printf("좌표를 입력해주세요 (x,y) : ");
                scanf("%d %d", &x, &y);
            } else {
                printf("이미 점령된 자리입니다. 다른 곳을 골라주세요\n");
                printf("좌표를 입력해주세요 (x,y) : ");
                scanf("%d %d", &x, &y);
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
        printf("---|---|---");
        if(cnt == 9){
            printf("게임이 끝났습니다.\n");
            printf("한 번 더 하시겠습니까? (y/n) : \n");
            scanf("%c",&answer);
            if(answer == 'n'){
                printf("게임이 종료되었습니다.");
                return 0;
            }
            else if(answer == 'y'){
                cnt = 0;
                j = 0;
            }
        }
    }
}
