#include <stdio.h>
#define MAX 10
void input(int [][MAX],int ,int );
int sum(int [][MAX],int ,int ,int ,int );
int main() {
    int array[MAX][MAX],row,col,x,y;
    scanf("%d %d",&row,&col);
    input(array,row,col);
    scanf("%d %d",&x,&y);
    printf("%d",sum(array,x,y,row,col));
    return 0;
}
void input(int array[MAX][MAX],int row, int col) {
    int i,j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col ; j++) {
            scanf("%d",&array[i][j]);
        }
    }
}
int sum(int array[MAX][MAX],int x,int y,int row,int col) {
    int sum = 0;
    if(x == 1) {
        if(y == 1) {
            sum = array[1][1] + array[0][1] + array[1][0];
        } else
            if(y == col) {
                sum = array[0][col - 2] + array[1][col - 1] + array[1][col - 2];
            }else{
                sum = array[0][y] + array[0][y - 2] + array[1][y - 2] + array[1] [y - 1] + array[1][y];
            }
    } else
        if(x == row) {
            if(y == 1) {
                sum = array[row - 1][1] + array[row - 2][0] + array[row - 2][1];
            }else
                if(y == col) {
                    sum = array[row - 1][col - 2] + array[row - 2][col - 2] + array[row - 2][col - 1];
                }else {
                    sum = array[row - 1][y] + array[row - 1][y - 2] + array[row - 2][y] + array[row - 2][y - 1] + array[row - 2][y - 2];
                }
        }else
            if(y == 1) {
                sum = array[x][0] + array[x - 2][0] + array[x][1] + array[x - 1][1] + array[x - 2][1];
            }else
                if(y == col) {
                    sum = array[x][col - 1] + array[x - 2][col - 1] + array[x][col - 2] + array[x - 1][col - 2] + array[x - 2][col - 2];
                }else{
                    sum = array[x][y] + array[x - 1][y] + array[x - 2][y] + array[x - 2][y - 1] + array[x - 2][y - 2] + array[x - 1][y - 2] + array[x][y - 2] + array[x][y - 1];
                }
    return sum;
}