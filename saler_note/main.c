#include <stdio.h>
void input_array(float [][5],int );
void sum(float [][5]);
void output_array(float [][5]);
int main() {
    int num_notes;
    float sale_data[6][5] = {0};
    scanf("%d", &num_notes);
    input_array(sale_data,num_notes);
    return 0;
}
void input_array(float sale_data[6][5],int num_notes) {
    int i,person,object;
    float money;
    for(i = 1; i <= num_notes; i++) {
        scanf("%d %d %f",&person,&object,&money);
        sale_data[object - 1][person - 1] += money;
    }
    sum(sale_data);
    output_array(sale_data);
}//列代表销售员，行代表产品
void sum(float sale_data[6][5]) {
    int i,j;
    float sum;
    for(i = 0; i < 6;i++) {
        sum = 0;
        for(j = 0; j < 5; j++) {
            sum += sale_data[i][j];
        }
        sale_data[i][4] = sum;
    }
    for(j = 0; j < 5; j++) {
        sum = 0;
        for(i = 0; i < 6; i++) {
            sum += sale_data[i][j];
        }
        sale_data[5][j] = sum;
    }
}
void output_array(float sale_data[6][5]) {
    int i,j;
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 4; j++) {
            printf("%.1f\t",sale_data[i][j]);
        }
        printf("%.1f\n",sale_data[i][j]);
    }
}