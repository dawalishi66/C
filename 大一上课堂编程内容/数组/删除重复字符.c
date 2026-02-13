/*本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

输入格式：
输入是一个以回车结束的非空字符串（少于80个字符）。

输出格式：
输出去重排序后的结果字符串。

输入样例：
ad2f3adjfeainzzzv
输出样例：
23adefijnvz*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compare(const void *p1,const void *p2){
    return strcmp(p1,p2);
}
int main(){
    int i,j,n,max,min,b=0;
    char str[85];
    int pan[128]={0};
    fgets(str,80,stdin);
    str[strcspn(str,"\n")]='\0';
    n=strlen(str);
    for(i=0;i<n;){
        if(pan[str[i]]==0)pan[str[i]]=1,i++;
        else{
            for(j=i;j<n-1;j++){
                str[j]=str[j+1];
            }
            str[j]='\0';
            n--;
        }
    }
    qsort(str,n,sizeof(str[0]),compare);
    printf("%s\n",str);
    return 0;
}
