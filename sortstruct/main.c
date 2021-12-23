#include <stdio.h>
#include <string.h>
struct STUDENT{
    char name[21];
    int total;
};
void input(struct STUDENT *,int );
void sort(struct STUDENT *,int );
void output(struct STUDENT *,int );
int main() {
    struct STUDENT std[100];
    int n;
    scanf("%d",&n);
    getchar();
    input(std,n);
    sort(std,n);
    output(std,n);
    return 0;
}
void input(struct STUDENT *st, int n){
    int i;
    for(i = 1; i <= n; i++) {
        scanf("%s",st->name);
        getchar();
        scanf("%d",&st->total);
        getchar();
        st++;
    }
}
void output(struct STUDENT *st,int n) {
    int i;
    for(i = 1; i <= n; i++) {
        printf("Name:%s\n",st->name);
        printf("total:%d\n\n", st->total);
        st++;
    }
}
void sort(struct STUDENT *st,int n) {
    struct STUDENT temp;
    int i,pass;
    for(pass = 1; pass <= n; pass++) {
        for(i = 0; i < n - 1; i++) {
            if((st[i].total < st[i +1].total) || ( (st[i].total == st[i + 1].total) && strcmp(st[i].name,st[i+1].name) > 0)) {
                temp = st[i];
                st[i] = st[i + 1];
                st [i + 1] = temp;
            }
        }
    }
}