/*本题要求你计算A-B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A?B。

输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10 
4
 ，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：
在一行中打印出A?B的结果字符串。

输入样例：
I love GPLT!  It's a fun game!
aeiou
输出样例：
I lv GPLT!  It's  fn gm!*/
#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,n1,n2,a;
    char str1[10005]={0},str2[10005]={0};
    fgets(str1,10005,stdin);
    fgets(str2,10005,stdin);
    str1[strcspn(str1,"\n")]='\0';
    str2[strcspn(str2,"\n")]='\0';
    n1=strlen(str1);
    while(1){
        a=strcspn(str1,str2);
        if(a>=n1){
            break;
        }
        n1=strlen(str1),n2=strlen(str2);
        for(i=a;i<n1-1;i++){
            str1[i]=str1[i+1];
        }
        str1[i]='\0';
    }
    printf("%s\n",str1);
    return 0;
}
