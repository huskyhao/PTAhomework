#include <stdio.h>
#define MAX 100
void input(int [][MAX],int ,int );
void find(int [][MAX],int ,int );
int main() {
    int array[MAX][MAX],row,col;
    scanf("%d %d",&row,&col);
    input(array,row,col);
    find(array,row,col);
    return 0;
}
void input(int arrat[MAX][MAX],int row,int col) {
    int i,j;
    for(i = 0; i < row; i++) {
        for( j = 0; j < col; j++) {
            scanf("%d", &arrat[i][j]);
        }
    }
}
void find(int array[MAX][MAX], int row,int col) {
    int point,i,j;
    int big,test;
    int Found = 0;
    for(i = 0;i < row && !Found; i++) {
        point = array[i][0];
        test = 1;
        for(j = 0; j < col; j++) {
            if(array[i][j] >= point) {
                point = array[i][j];
                big = j;
            }
        }
        for(j = 0; j < row; j++) {
            if(array[j][big] < point) {
                test = 0;
            }
        }
        if(test) {
            Found = 1;
        }
    }
    if(!Found) {
        printf("There is no saddle point in the matrix.");
    } else {
        printf("The saddle point is (%d,%d)=%d.",i - 1,big,point);
    }
}