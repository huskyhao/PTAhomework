#include <stdio.h>
#define MAX 100
void input(int [][MAX],int);
void reverse(int [][MAX],int );
void output(int [][MAX],int );
int main() {
    int ar[MAX][MAX],size;
    scanf("%d", &size);
    input(ar,size);
    reverse(ar,size);
    output(ar,size);
    return 0;
}
void input(int ar[MAX][MAX],int size) {
    int i,j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j ++) {
            scanf("%d",&ar[i][j]);
        }
    }
}
void reverse(int ar[MAX][MAX],int size) {
    int sum_former,sum_latter,times,trans;
    int i,j;
    for(times = 1; times <= size; times++) {
        for(i = 0;i < size - 1; i++) {
            sum_former = 0;
            sum_latter = 0;
            for(j = 0; j < size; j++) {
                sum_former += ar[i][j];
                sum_latter += ar[i + 1][j];
            }
            if(sum_former > sum_latter) {
                for(j = 0; j < size; j++) {
                    trans = ar[i][j];
                    ar[i][j] = ar[i + 1][j];
                    ar[i + 1][j] = trans;
                }
            }
        }
    }
}
void output(int ar[MAX][MAX],int size) {
    int i,j;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - 1; j++) {
            printf("%d ",ar[i][j]);
        }
        printf("%d\n",ar[i][j]);
    }
}