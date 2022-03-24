#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* next;
};
int input(struct node*);//返回值为链表长度，若无元素则返回0
void sort(struct node* ,struct node* ,int ,int );//进行两个链表之间的比较和插入，小则前插，大则后插，相同不动
void output(struct node*, char );//分别输出链表A、B
void to_free(struct node*);//释放链表

int main() {
    struct node *headA,*headB;
    int len_a,len_b;
    //初始化AB两个头指针指向一个不含数据的空节点
    headA = (struct node *) malloc(sizeof(struct node));
    headA->next = NULL;
    headB = (struct node *) malloc(sizeof(struct node));
    headB->next = NULL;
    len_a = input(headA);
    len_b= input(headB);
    sort(headA,headB,len_a,len_b);
    output(headA,'A');
    output(headB,'B');
    to_free(headA);
    to_free(headB);
    return 0;
}
int input(struct node* head) {
    int ret = 0;
    int temp;
    struct node *current,*prev;
    scanf("%d", &temp);
    prev = head;
    while (temp != -1) {
        current = (struct node*) malloc(sizeof(struct node));
        prev->next = current;
        current->val = temp;
        current->next = NULL;
        prev = current;
        scanf("%d", &temp);
        ret++;
    }
    return ret;
}

void sort(struct node*headA,struct node *headB, int len_a, int len_b) {
    struct node *prevA, *prevB;
    struct node *currentA, *currentB;
    int equ = 0;

    prevB = headB;
    currentB = headB->next;
    prevA = headA;
    currentA = headA->next;
    while(currentA != NULL && currentB != NULL) {
        if(currentB->val < currentA->val) {
            prevB->next = currentB->next;
            prevA->next = currentB;
            currentB->next = currentA;
            prevA = prevA->next;
            currentB = prevB->next;
            len_b--;
        } else
        if(currentB->val == currentA->val) {
            equ++;
            prevB = prevB->next;
            currentB = currentB->next;
        } else{
            prevA = prevA->next;
            currentA = currentA->next;
        }
    }
    if(equ < len_b) {
        prevA->next = currentB;
        prevB->next = NULL;
    }
}
void output(struct node*head,char name) {
    struct node *current;
    current = head->next;
    if(current == NULL) {
        printf("There is no item in %c list.\n",name);
    } else {
        printf("The new list %c:",name);
        while(current->next != NULL) {
            printf("%d ",current->val);
            current = current->next;
        }
        printf("%d\n",current->val);
    }
}

void to_free(struct node* head) {
    struct node* current;
    current = head->next;
    while (current != NULL) {
        free(head);
        head = current;
        current = current->next;
    }
}