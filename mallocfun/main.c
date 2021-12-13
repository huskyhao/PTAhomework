#include <stdio.h>
#include <stdlib.h>
#define RATE -10
void input(int *, int );
void down(int *,int );
void output(int *,int );
int main() {
    int *a,n;
    scanf("%d",&n);
    a=(int * )malloc(sizeof(int) * n);// 建立长度为n的动态整型数组
    input(a,n);
    down(a,n);
    output(a,n);
    free(a);//释放动态内存。
    return 0;
}
void input(int *a,int n) {
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
}
void down(int * a, int n) {
    int i;
    for(i = 0; i < n; i++) {
        *(a + i) *= RATE;
    }
}
void output(int *a,int n) {
    int i;
    for(i = 0; i < n - 1; i++) {
        printf("%d ",*(a + i));
    }
    printf("%d",*(a + i));
}