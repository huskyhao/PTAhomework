#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node* next;
};
void sort(struct node*, int );
void output(struct node*);
void free_node(struct node*);
int main() {
    struct node*head = NULL;
    struct node* current, *prev;
    int temp,len = 0;
    scanf("%d",&temp);
    //让头指针指向一个空节点
    head = (struct node*) malloc(sizeof(struct node));
    prev = head;
    while(temp != -1){
        current = (struct node*) malloc(sizeof(struct node));
        prev->next = current;
        current->val = temp;
        current->next = NULL;
        prev = prev->next;
        len++;
        scanf("%d",&temp);
    }
    sort(head,len);
    output(head);
    free_node(head);
    return 0;
}
void sort(struct node* head,int len){
    struct node* prev, *current;
    int i;
    for(i = 1; i <= len + 1; i++) {
        prev = head;
        current = head->next;
        while(current->next != NULL) {
            if(current->val > current->next->val){
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = current;
                prev = prev->next;
            } else {
                current = current->next;
                prev = prev->next;
            }
        }
    }
}

void output(struct node * head) {
    struct node* current;
    current = head->next;
    printf("The new list is:");
    while(current->next != NULL){
        printf("%d ",current->val);
        current = current->next;
    }
    printf("%d",current->val);
}

void free_node(struct node* head) {
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