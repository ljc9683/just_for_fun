#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randnum() {
    return rand() % 10;
}
int main(void) {
    int baseball[3] = {' ',' ',' '};
    int com;
    int cnt=0;
    int i;
    srand(time(NULL));
    for(i=0;i<3;i++){
        baseball[i] = randnum();
    }
    while(1){
        for(int j=1;j<3;j++){
            for(int k=0;k<3;k++){
                if(j == k){
                    continue;
                }
                if(baseball[j] == baseball[k]){
                    baseball[j] = randnum();
                }
                if(baseball[j] != baseball[k]){
                    cnt++;
                }
            }
        }
        if(cnt == 4){
            break;
        }
        cnt = 0;
    }
    for(i=0;i<3;i++){
        printf("%d   ",baseball[i]);
    }
    return 0;
}
