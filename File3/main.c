#include <stdio.h>
void GetLine(FILE*fp,int*);
void GetCode(FILE*,int ,int );//第一个为起使行数，第二个为终止行数，若为第五段则第二个为-1

int main() {
    int part[5] = {};//各段代码的结束行数
    int num;
    FILE * fp = NULL;
    scanf("%d",&num);
    fp = fopen("dict.dic","r");
    GetLine(fp,part);
    switch (num) {
        case 1:
            GetCode(fp,6,part[0]);
            break;
        case 2:
            GetCode(fp,part[0] + 1, part[1]);
            break;
        case 3:
            GetCode(fp, part[1] + 1, part[2]);
            break;
        case 4:
            GetCode(fp,part[2] + 1, part[3]);
            break;
        default:
            GetCode(fp,part[3] + 1, part[4]);
            break;
    }
    return 0;
}
void GetLine(FILE * fp,int *part) {
    int ch;
    int count = 0;
    ch = fgetc(fp);
    while(count < 5) {
        while(ch != '\n') {
            part[count] = part[count] * 10 + (ch - '0');
            ch = getc(fp);
        }
        count++;
        if(count != 5) {
            ch = getc(fp);
        }
    }
}//前五行为各段代码结尾在第几行
void GetCode(FILE * fp,int start, int end) {
    int count = 5;//已经读过了前五行，已有五个换行符
    int ch,status = 0;
    //如果是//注释则status为1，是/**/则为2，不是注释为0
    ch = fgetc(fp);
    while (count < start - 1) {
        if(ch == '\n') {
            count ++;
        }
        ch = fgetc(fp);
    }
    while (count < end ) {
        //先判断是否是‘/’
        if(ch == EOF) {
            break;
        }
        if(ch == '\n') {
            count++;
            if(count == end) {
                break;
            }
        }
        if(status == 0 && ch != '/') {
            printf("%c",ch);
            ch = fgetc(fp);
        }//不在注释中且读入的字符不为‘/’时，输出并且读下一个字符
        if(status == 0 && ch == '/') {
            ch = fgetc(fp);//再读一个
            if(ch == '/') {
                status = 1;
            } else
                if(ch == '*') {
                    status = 2;
                } else{
                    printf("/%c",ch);
                    ch = fgetc(fp);
                }
        }//读到'/'时判断一下是注释还是除号，注释则改变status，除号则照常输出
        if(status == 1) {
            while(ch != '\n') {
                ch = fgetc(fp);
            }
            status = 0;
        }//读到换行符跳出循环
        if(status == 2) {
            while(status == 2){
                if(ch == '\n') {
                    count++;
                }
                if(ch == '*'){
                    ch = fgetc(fp);
                    if(ch == '/') {
                        break;
                    }
                } else {
                    ch = fgetc(fp);
                }
            }
            status = 0;
            ch = getc(fp);
        }//读到‘*/’后一个字符
    }
}