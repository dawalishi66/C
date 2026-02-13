/*给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过500 000的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用若干个空格分开。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子，并且保证单词间只有1个空格。

输入样例：
Hello World   Here I Come
输出样例：
Come I Here World Hello*/
#include<stdio.h>
#include<string.h>
void zhuan(char * s,int left,int right){
    int i;
    char x;
    right--;
    while(left<right){
        x=s[left];
        s[left]=s[right];
        s[right]=x;
        left++,right--;
    }
}
int main(){
    char str1[500005]={0},temp;
    fgets(str1,500005,stdin);
    str1[strcspn(str1,"\n")]='\0';
    int n=strlen(str1),i=0,j,new_start=0;
    while(i<n&&str1[i]==' '){//去除段落初始空格 
        i++;
    }
    while(i<n){//去除段落中途多余（大于1）空格 
        if(str1[i]!=' '){
            str1[new_start++]=str1[i++];
        }else{
            str1[new_start++]=' ';
            while(i<n&&str1[i]==' '){
                i++;
            }
        }
    }
    if(new_start>0&&str1[new_start-1]==' '){//去除段落末尾空格 
        new_start--;
    }
    str1[new_start]='\0';
    zhuan(str1,0,new_start);
    int x=0;
    for(i=0;i<=new_start;i++){
        if(str1[i]==' '||str1[i]=='\0'){
            zhuan(str1,x,i);
            x=i+1;
        }
    }
    printf("%s\n",str1);
    return 0;
}
