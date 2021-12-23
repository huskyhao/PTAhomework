#include <stdio.h>
typedef struct {
    char id[16];//学生账号
    int total ;//综合成绩
    int ce ;//机试成绩
    int ws ;//加权成绩
}STUDENT;
void Sort(STUDENT a[],int size) ;
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;
int main() {
    STUDENT stu[100] ;
    int i , n ;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }
    Sort(stu,n) ;
    for(i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;
    return 0;
}
void Swap(STUDENT * s1, STUDENT * s2) {
    STUDENT tran = {"bupt_2018210000",0,0,0};
    STUDENT *temp = &tran;
    *temp = *s1;
    *s1 = *s2;
    *s2 = *temp;
}
int Comp(STUDENT * s1, STUDENT * s2) {
    int ret = 0;
    if(s1->total > s2->total ) {
        ret = 1;
    } else
    if((s1->total == s2->total) && (s1->ce > s2->ce)) {
        ret = 1;
    }
    return ret;
}
void  Sort(STUDENT stu[100], int size) {
    int i;
    int pass;
    for(pass = 0; pass < size; pass++) {
        for(i = 0; i < size - pass - 1; i++) {
            if(!Comp(&stu[i],&stu[i+1])) {
                Swap(&stu[i], &stu[i + 1]);
            }
        }
    }
}
