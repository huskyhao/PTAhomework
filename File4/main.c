#include <stdio.h>
#include <string.h>

int inputVocabulary(FILE*,char [10][10]);
void replace(char*,char [][10],int );
int isDirtyWord(char*,char[][10],int );
void getText(char[][10],int );
int main() {
    FILE * fp = NULL;
    char vocabulary[10][10];
    int len;//有几个屏蔽词汇
    fp = fopen("dict.dic","r");
    len = inputVocabulary(fp,vocabulary);
    getText(vocabulary,len);
    return 0;
}
void getText(char vocabulary[10][10],int len) {
    char str[120];
    while (gets(str)) {
        replace(str,vocabulary,len);
    }
}
int inputVocabulary(FILE*fp,char vocabulary[10][10]) {
    int count  = 0,ch,i = 0;
    char temp[10];
    ch = fgetc(fp);
    while (ch != EOF) {
        if(ch != '\n') {
            temp[i] = (char )ch;
            i++;
        } else {
            temp[i] = '\0';//字符串最后一个字符为'\0'
            strcpy(vocabulary[count],temp);
            count++;
            i = 0;
        }
        ch = fgetc(fp);
    }
    temp[i] = '\0';//字符串最后一个字符为'\0'
    strcpy(vocabulary[count],temp);
    return count;
}//得到屏蔽词汇
void replace(char str[110],char vocabulary[10][10],int len) {
    int i;
    int flag;
    for(i = 0; str[i];i++) {
        flag = isDirtyWord(&str[i],vocabulary,len);
        if(flag == -1){
            printf("%c",str[i]);
        } else {
            printf("!@#$%^&*");
            i += (int )strlen(vocabulary[flag]);
            i--;//减去strlen算上的‘\0’
        }
    }
    printf("\n");
}
int isDirtyWord(char* str,char vocabulary[10][10],int len) {
    int i,j;
    int ret = -1;
    char temp[10];//用来暂存单词以用strcmp函数
    int vocabulary_len;
    for(i = 0; i <= len; i++) {
        //最外层是用来遍历和谐词汇的二维数组的
        vocabulary_len = (int )strlen(vocabulary[i]);
        for(j = 0; j < vocabulary_len ; j++) {
            temp[j] = str[j];
            if(str[j] == '\0') {
                break;
            }
        }//将相同长度的字符串复制到temp中
        temp[j] = '\0';
        if(strcmp(temp,vocabulary[i]) == 0) {
            ret = i;//返回值为屏蔽词汇的第i个单词的i
            break;
        }
    }
    return ret;
}