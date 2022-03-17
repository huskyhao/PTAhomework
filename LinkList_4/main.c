#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* next;
};
struct node* input(struct node* head);
struct node* place(struct node*,int );
void output(struct node*);
void to_free(struct node*);
int main() {
    int s1,t1,s2,t2;
    struct node *head;
    struct node *front1,*front2,*last1,*last2;
    struct node*temp1,*temp2,*temp3,*temp4;
    head = (struct node*) malloc(sizeof(struct node));//让头指针指向空节点

    head = input(head);

    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    temp1 = place(head, s1 - 1);
    front1 = place(head, s1);
    front2 = place(head, t1);
    temp2 = place(head, t1 + 1);
    temp3 = place(head, s2 - 1);
    last1 = place(head, s2);
    last2 = place(head, t2);
    temp4 = place(head, t2 + 1);
    //分别获得交换部分头和尾位置以及前面和后面一个的位置

    //交换的操作
    //当第一部分和第二部分之间没有其余节点
    if(temp2 == last1) {
        front2->next = temp4;
        temp1->next = last1;
        last2->next = front1;
    } else {
        front2->next = temp4;
        temp3->next = front1;
        temp1->next = last1;
        last2->next = temp2;
    }
    //在链表中各个node出现次序为：temp1,front1,front2,temp2,temp3,last1,last2,temp4.
    output(head);
    to_free(head);

    return 0;
}
struct node* input(struct node* head) {
    struct node *current,*prev;
    int temp;
    scanf("%d",&temp);
    prev = head;
    while(temp != -1) {
        current = (struct node*)malloc(sizeof(struct node));
        prev->next = current;
        current->next = NULL;
        current->val = temp;
        prev = prev->next;
        scanf("%d", &temp);
    }
    return head;
}
struct node* place(struct node* head,int p) {
    int i;
    struct node * ret;
    ret = head;
    for(i = 1; i <= p; i++) {
        ret = ret->next;
    }
    return ret;
}
void output(struct node*head){
    struct node* current;
    current = head->next;
    printf("The new list is:");
    while(current->next != NULL) {
        printf("%d ",current->val);
        current = current->next;
    }
    printf("%d\n",current->val);
}
void to_free(struct node*head) {
    struct node*current;
    current = head;
    while(current != NULL) {
        current = current->next;
        free(head);
        head = current;
    }
}