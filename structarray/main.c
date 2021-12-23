#include <stdio.h>
struct STUDENT{
    char name[21];
    char id[21];
    int score[5];
    int total;
    double average;
};
void input(struct STUDENT* ,int );
void output(struct STUDENT* ,int );
int main() {
    int n;
    struct STUDENT std[100];
    scanf("%d", &n);
    getchar();
    input(std,n);
    output(std,n);
    return 0;
}
void input(struct STUDENT *st,int n) {
    int peo,i;
    for(peo = 1; peo <= n; peo++) {
        st->total = 0;
        fgets(st->name,20,stdin);
        fgets(st->id,20,stdin);
        for(i = 0; i < 5; i++) {
            scanf("%d",&st->score[i]);
            getchar();
            st->total += st->score[i];
        }
        st->average = st->total / 5.0;
        st++;
    }
}
void output(struct STUDENT *st,int n) {
    int peo,i;
    for(peo = 1; peo <= n; peo++) {
        printf("Name:%s",st->name);
        printf("ID:%s",st->id);
        printf("Score:");
        for(i = 0; i < 4; i++) {
            printf("%d ",st->score[i]);
        }
        printf("%d\n", st->score[i]);
        printf("average:%.2lf total:%d\n",st->average,st->total);
        printf("\n");
        st++;
    }
}