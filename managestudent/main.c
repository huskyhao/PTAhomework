#include <stdio.h>
#include <string.h>
struct STUDENT{
    char name[12];
    char id[12];
    int score[3];
    int status;
};
void init(struct STUDENT*);
void operate(struct STUDENT*,int );
void add(struct STUDENT *);
void input(struct STUDENT*);
void delete(struct STUDENT *);
void change(struct STUDENT *);
void show(struct STUDENT *);
int judge(struct STUDENT *,struct STUDENT);

int main() {
    struct STUDENT std[150];
    int n;
    init(std);
    scanf("%d",&n);
    operate(std,n);
    return 0;
}

void init(struct STUDENT *std) {
    int i;
    for(i = 0; i < 150; i++) {
        std->status = 0;
    }
}

void operate(struct STUDENT *std,int n) {
    int i;
    int action;
    for(i = 1; i <= n; i++) {
        scanf("%d",&action);
        switch (action) {
            case 1:
                add(std);
                break;
            case 2:
                delete(std);
                break;
            case 3:
                change(std);
                break;
            case 4:
                show(std);
                break;
            default:break;
        }
    }
}

void add(struct STUDENT *std) {
    struct STUDENT temp;
    int place;
    int add = 0,i;
    input(&temp);
    place = judge(std,temp);
    if(place != -1) {
        printf("Students already exist\n");
    } else {
        for(i = 0; add == 0;i++) {
            if(std[i].status == 0) {
                std[i] = temp;
                add = 1;
            }
        }
        printf("Add success\n");
    }
}
void input(struct STUDENT * temp) {
    int i;
    scanf("%s",temp->id);
    scanf("%s",temp->name);
    for(i = 0; i < 3; i++) {
        scanf("%d",&temp->score[i]);
        getchar();
    }
    temp->status = 1;
}
int judge(struct STUDENT*std,struct STUDENT test) {
    int ret = -1;
    int i;
    for(i = 0; i < 130; i++) {
        if(std[i].status == 1 && strcmp(std[i].id, test.id) == 0) {
            ret = i;
        }
    }
    return ret;
}//如果test存在于std中，则返回下标，否则返回-1

void delete(struct STUDENT* std) {
    int place;
    struct STUDENT test;
    scanf("%s",test.id);
    place = judge(std,test);
    if(place != -1) {
        std[place].status = 0;
        printf("Delete success\n");
    } else{
        printf("Students do not exist\n");
    }
}
void change(struct STUDENT *std) {
    struct STUDENT temp;
    int place;
    int i;
    scanf("%s",temp.id);
    scanf("%d%d%d",&temp.score[0],&temp.score[1],&temp.score[2]);
    place = judge(std,temp);
    if(place == -1) {
        printf("Students do not exist\n");
    } else {
        printf("Update success\n");
        for(i = 0; i < 3; i++) {
            std[place].score[i] = temp.score[i];
        }
    }
}
void show(struct STUDENT *std) {
    struct STUDENT temp;
    double average;
    int place;
    scanf("%s",temp.id);
    place = judge(std,temp);
    if(place == -1) {
        printf("Students do not exist\n");
    } else {
        printf("Student ID:%s\n",std[place].id);
        printf("Name:%s\n",std[place].name);
        average = (std[place].score[0] + std[place].score[1] + std[place].score[2] ) / 3.0;
        printf("Average Score:%.1lf\n",average);
    }
}