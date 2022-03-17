#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
int input(struct node*);//创建链表并输入数据，返回链表长度，不包含头指针指向的空节点
int comp(struct node*, struct node*, int, int);//比较是否为子链表，1为真，0为假
void to_free(struct node*);//释放内存
int main() {
    struct node * head_1,*head_2;
    int len_1,len_2;
    head_1 = (struct node*) malloc(sizeof(struct node));
    head_2 = (struct node*) malloc(sizeof(struct node));
    len_1 = input(head_1);
    len_2 = input(head_2);
    if(comp(head_1, head_2, len_1, len_2)){
        printf("ListB is the sub sequence of ListA.");
    } else{
        printf("ListB is not the sub sequence of ListA.");
    }
    to_free(head_1);
    to_free(head_2);
    return 0;
}
int input(struct node* head){
    int len = 0;
    int temp;
    struct node* current, *prev;
    scanf("%d",&temp);
    prev = head;
    while(temp != -1) {
        current = (struct  node*) malloc(sizeof(struct node));
        prev->next = current;
        current->val = temp;
        current->next = NULL;
        prev = prev->next;
        len++;
        scanf("%d",&temp);
    }
    return len;
}
int comp(struct node* head_1, struct node* head_2, int len_1, int len_2){
    int ret = 0,i,j;
    struct node* equal_place;
    struct node *current_1, *current_2;
    if(len_1 < len_2) {
        return ret;
    } else{
        current_1 = head_1->next;
        current_2 = head_2->next;
        for(i = 1; i <= len_1; i++){
            if(current_1->val == current_2->val){
                equal_place = current_1;
                for(j = 1; j <= len_2; j++){
                    if(current_1->next == NULL || current_2->next == NULL){
                        break;
                    }
                    current_1 = current_1->next;
                    current_2 = current_2->next;
                    if(current_1->val != current_2->val){
                        break;
                    }
                }//内层循环两个链表同时遍历
                if(j == len_2){
                    ret = 1;
                    break;
                } else {
                    current_1 = equal_place;
                    current_2 = head_2->next;
                }
            }
            current_1 = current_1->next;
        }//外层循环遍历List1
    }
    return  ret;
}
void to_free(struct node* head){
    struct node* current;
    current = head->next;
    free(head);
    head = current;
    while(current != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
}