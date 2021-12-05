#include <stdio.h>
#define MAX 100
void snack(int [][MAX],int );
void output_array(int [][MAX],int );
int main() {
    int ar[MAX][MAX],size;
    scanf("%d", &size);
    snack(ar,size);
    output_array(ar,size);
    return 0;
}
void snack(int ar[MAX][MAX], int size) {
    int num,move,i = 0,j = 0;
    int up_down = 1;//1代表上行，0代表下行
    ar[i][j] = 1;
    i++;
    for(num = 2; num <= size * size && i < size && j < size; num++) {
        ar[i][j]=num;
        if(up_down){
            if(j == size - 1) {
                i++;
                up_down = 0;
                move = 1;
            }
            if(i == 0) {
                j++;
                up_down = 0;
                move = 1;
            }
        } else{
            if(i == size - 1) {
                j++;
                up_down = 1;
                move = 1;
            }
            if(j == 0) {
                i++;
                up_down = 1;
                move = 1;
            }
        }
        if(!move) {
            if(up_down) {
                i--;
                j++;
            } else {
                i++;
                j--;
            }
        }
        move = 0;
    }
}
void output_array(int ar[][MAX],int size) {
    int i,j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - 1; j++) {
            printf("%d ",ar[i][j]);
        }
        printf("%d\n",ar[i][j]);
    }
}