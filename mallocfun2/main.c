#include <stdio.h>
#include <stdlib.h>
void input(int **,int ,int );
void output(int **,int ,int );
int main() {
    int **a, n, m, i;
    scanf("%d %d",&n,&m);
    a=(int **)malloc(sizeof(int *)*n);//建立长度为n的动态指针数组
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(sizeof(int)*m);//建立长度为m的一维整型数组
    input(a,n,m);
    output(a,n,m);
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);//释放动态内存。
    return 0;
}
void input(int **a,int n,int m) {
    int i,j;
    for(i = 0; i < n; i++) {
        for( j = 0; j < m; j++) {
            scanf("%d",*(a + i) + j);
        }
    }

}
void output(int **a,int n, int m) {
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m - 1; j++) {
            printf("%d ",*(*(a + i) + j) * (-10));
        }
        printf("%d\n",*(*(a + i) + j) * (-10));
    }
}