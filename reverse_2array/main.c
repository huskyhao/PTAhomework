#include <stdio.h>
#define MAX 100
void reverse(int [][MAX],int [][MAX],int ,int );
void input_array(int [][MAX],int ,int );
void output_array(int [][MAX],int ,int );
int main() {
    int origin[MAX][MAX],row,col;
    int new[MAX][MAX];
    scanf("%d%d",&row,&col);
    input_array(origin,row,col);
    reverse(origin,new,row,col);
    output_array(new,row,col);
    return 0;
}
void input_array(int origin[MAX][MAX],int row,int col) {
    int i,j;
    for(i = 0;i < row; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d",&origin[i][j]);
        }
    }
}
void reverse(int origin[][MAX],int new[][MAX],int origin_row,int origin_col){
    int i,j;
    for(i = 0; i < origin_row; i++) {
        for(j = 0; j < origin_col; j++) {
            new[j][i] = origin[i][j];
        }
    }
}
void output_array(int new[][MAX],int new_col,int new_row) {
    int i,j;
    for(i = 0; i < new_row; i++) {
        for(j = 0; j < new_col - 1; j++) {
            printf("%d ",new[i][j]);
        }
        printf("%d\n",new[i][j]);
    }
}