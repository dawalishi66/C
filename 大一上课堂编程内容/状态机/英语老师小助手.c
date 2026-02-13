/*英语老师要求学生按照如下规则写一串字母：

规则1、如果写了某个大写字母，下一个就必须写同个字母的小写，或者写字母表中前一个字母的大写；

规则2、如果写了某个小写字母，下一个就必须写同个字母的大写，或者写字母表中下一个字母的小写。

例如 zZzZYXWwxyYX 就是一个合法的字母串；而 wVUuvUTsR 就是非法的。

现在面对全班学生交上来的作业，老师请你写个程序自动批改。

输入格式:
每行给出一位学生的作业，即仅由英文字母组成的非空字母串，长度大于2。

输出格式:
对每位学生的作业，如果正确就在一行中输出 Y，否则输出 N。

输入样例1:
zZzZYXWwxyYX
输出样例1:
Y
输入样例2:
wVUuvUTsR
输出样例2:
N*/
#include<stdio.h>
#define supper 1
#define lower 2
#define start 3
int main(){
    char ch,b;
    int state=start,a=0;
    while((ch=getchar())!='\n'&&ch!='\0'&&ch!=EOF){
        switch(state){
            case start:
                if(ch>='a'&&ch<='z'){state=lower;b=ch;}
                else if(ch>='A'&&ch<='Z'){state=supper;b=ch;}
                break;
            case supper:
                if(ch==b+32)state=lower;
                else if(ch==((b+25-'A')%26+'A'))state=supper;
                else a+=1;
                b=ch;
                break;
            case lower:
                if(ch==b-32)state=supper;
                else if(ch==((b+27-'a')%26+'a'))state=lower;
                else a+=1;
                b=ch;
                break;
        }
    }
    if(a==0)printf("Y");
    else printf("N");
    return 0;
}
