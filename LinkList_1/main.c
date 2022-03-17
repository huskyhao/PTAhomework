#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};
int max_val(struct node*);
int min_val(struct node*);
int sum_val(struct node*);
int main() {
    int temp_val;
    int max,min,sum;
    struct node *head = NULL;
    struct node *prev,*current;
    scanf("%d",&temp_val);
    while(temp_val != -1){
        current = (struct node*) malloc(sizeof(struct node));
        if(head == NULL) {
            head = current;
        } else{
            prev->next = current;
        }//判断是否为第一个节点
        current->val = temp_val;
        current->next = NULL;
        prev = current;
        scanf("%d",&temp_val);
    }//获取数据

    max = max_val(head);
    min = min_val(head);
    sum = sum_val(head);

    current=head;
    while(current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }//释放内存

    printf("The maximum,minmum and the total are:%d %d %d",max,min,sum);
    return 0;
}
int max_val(struct node* head){
    struct node*current;
    int max;
    max = head->val;
    current = head;
    while(current != NULL) {
        if(current->val > max){
            max = current->val;
        }
        current = current->next;
    }
    return max;
}

int min_val(struct node* head){
    struct node*current;
    int min;
    min = head->val;
    current = head;
    while(current != NULL) {
        if(current->val < min){
            min = current->val;
        }
        current = current->next;
    }
    return min;
}

int sum_val(struct node* head){
    struct node*current;
    int sum = 0;
    current = head;
    while(current != NULL){
        sum += current->val;
        current = current->next;
    }
    return sum;
}