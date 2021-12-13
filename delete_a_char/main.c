#include<stdio.h>

void delcharfun(char *str,char ch);

int main()
{
    char ch,str[110];

    scanf("%s",str);    //读入字符串
    getchar();            //读取回车符号
    scanf("%c",&ch);    //读入字符
    delcharfun(str,ch);    //删除
    printf("%s\n",str);    //输出删除后结果
    return 0;
}

/* 请在这里填写答案 */
void delcharfun(char *str,char ch) {
    int i,j;
    for(i = 0; *(str + i) ;i++) {
        if(ch == *(str + i)) {
            for(j = 0; *(str + i + j); j++) {
            *(str + i + j) = *(str + i + j + 1);
            }
            i--;
        }
    }
}