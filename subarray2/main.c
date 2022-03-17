#include <stdio.h>
#define SIZE 1000
int input_array ( int a[],int size);
int compare(int a[], int b[],int a_size, int b_size);
void result(int);
int main() {
    int a[SIZE],b[SIZE];
    int found = 0,i,a_size,b_size;
    a_size = input_array(a,SIZE);
    b_size = input_array(b,SIZE);
    for(i = 0; i < a_size && !found; i++) {
        if(a[i] == b[0]) {
            found = compare(&a[i],b,a_size - i,b_size);
        }
    }
    result(found);
    return 0;
}
int input_array(int a[],int size) {
    int i = 0;
    scanf("%d", &a[i]);
    while(a[i] != -1 && i < size) {
        i++;
        scanf("%d", &a[i]);
    }
    return i;
}
int compare(int a[], int b[],int a_size, int b_size){
    int found = 1;
    int i;
    for(i = 0; i < b_size && i < a_size; i++) {
        if(a[i] != b[i]) {
            found = 0;
        }
    }
    return found;
}
void result(int found) {
    if(found) {
        printf("ListB is the sub sequence of ListA.");
    } else {
        printf("ListB is not the sub sequence of ListA.");
    }
}