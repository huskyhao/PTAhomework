#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    char val;
    struct node* next;
};
void input(struct node*);
void divide(struct node*, struct node*, struct node*, struct node*);
void sort(struct node*);
void output(struct node*,char );
void to_free(struct node*);
int main() {
    struct node *letter, *num, *symbol,*origin;
    origin = (struct node*) malloc(sizeof(struct node));
    origin->next = NULL;
    letter = (struct node*) malloc(sizeof(struct node));
    letter->next = NULL;
    num = (struct node*) malloc(sizeof(struct node));
    num->next = NULL;
    symbol = (struct node*) malloc(sizeof(struct node));
    symbol->next = NULL;
    input(origin);
    divide(origin,letter,num,symbol);//区分完后将origin的空节点删除
    sort(letter);
    sort(num);
    sort(symbol);
    output(letter,'A');
    output(num,'B');
    output(symbol,'C');
    to_free(letter);
    to_free(num);
    to_free(symbol);
    return 0;
}
void input(struct node* origin) {
    char temp[3];
    char end[3] = "-1";
    scanf("%s",temp);
    struct node* current,*prev;
    prev = origin;
    while (strcmp(temp,end) != 0) {
        current = (struct node*) malloc(sizeof(struct node));
        current->val = temp[0];
        current->next = NULL;
        prev->next = current;
        prev = prev->next;
        scanf("%s",temp);
    }
}
void divide(struct node *origin,struct node*letter,struct node* num, struct node *symbol) {
    struct node*current,*prev_L,*prev_N,*prev_S;
    current = origin->next;
    prev_L = letter;
    prev_N = num;
    prev_S = symbol;
    while (current != NULL) {
        if(isalpha(current->val)) {
            origin->next = current->next;
            prev_L->next = current;
            current->next = NULL;
            prev_L = prev_L->next;
        } else
            if(isdigit(current->val)) {
                origin->next = current->next;
                prev_N->next = current;
                current->next = NULL;
                prev_N = prev_N->next;
            } else {
                origin->next = current->next;
                prev_S->next = current;
                current->next = NULL;
                prev_S = prev_S->next;
            }
        current = origin->next;
    }
    free(origin);
}
void sort(struct node*head) {
    int len = 0,i;
    struct node*prev,*current;
    prev = head;
    current = head->next;
    while ( current != NULL) {
        current = current->next;
        len++;
    }
    current = head->next;
    for(i = 1; i <= len; i++) {
        prev = head;
        current = head->next;
        while(current->next != NULL) {
            if((int)current->val > (int) current->next->val){
                prev->next = current->next;
                current->next = current->next->next;
                prev->next->next = current;
                current = prev->next;
            } else {
                current = current->next;
                prev = prev->next;
            }
        }
    }
}
void output(struct node* head,char type) {
    struct node *current;
    if(head->next == NULL) {
        printf("There is no item in %c list.\n",type);
    } else {
        current = head->next;
        printf("The list %c is: ",type);
        while (current != NULL) {
            printf("%c ",current->val);
            current = current->next;
        }
        printf("\n");
    }
}
void to_free(struct node*head) {
    struct node* current;
    current = head->next;
    while (current != NULL) {
        free(head);
        head = current;
        current = head->next;
    }
    free(head);
}