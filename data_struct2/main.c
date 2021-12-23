#include <stdio.h>
typedef struct {
    char name[22];
    char id[22];
    int score[5];
    int total;
    double average;
}STUDENT;
void input_data(STUDENT *);
void output_data(STUDENT *);
void sort(int *);

int main() {
    STUDENT std;
    std.total = 0;
    input_data(&std);
    sort(std.score);
    output_data(&std);
    return 0;
}
void input_data(STUDENT *st) {
    int i;
    fgets(st->name,22,stdin);
    fgets(st->id,22,stdin);
    for(i = 0; i < 5; i++) {
        scanf("%d",&st->score[i]);
        st->total += st->score[i];
    }
    st->average = st->total / 5.0;
}
void output_data(STUDENT *st) {
    int i;
    printf("Name:%s",st->name);
    printf("ID:%s",st->id);
    printf("Score:");
    for(i = 0; i < 4; i++) {
        printf("%d ",st->score[i]);
    }
    printf("%d\n",st->score[i]);
    printf("average:%.2lf total:%d\n",st->average,st->total);
}
void sort(int * score) {
    int i,temp;
    int pass;
    for(pass = 1; pass <= 5; pass++) {
        for(i = 0; i < 4; i++) {
            if(score[i] < score[i + 1]) {
                temp = score[i];
                score[i] = score[i + 1];
                score[i + 1] = temp;
            }
        }
    }
}
