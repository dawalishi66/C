/*已知正整数n，n的范围是1—100。你要从键盘读入n个字符串，每个字符串的长度不确定，
但是n个字符串的总长度不超过100000。你要利用字符指针数组将这n个字符串按照ASCII码
顺序进行升序排序，然后再打印到屏幕上。字符串中可能包含ASCII码中的任意字符，每个字符串以换行符结束输入。

要求：不允许定义如char str[100][100000];这样的二维数组，因为会极大的浪费内存空间。
你应定义char str[100000];这样的存储空间，将n个字符串连续的存储在一维字符空间内，
然后将这n个字符串的起始位置保存在字符指针数组中，再进行排序操作。

输入格式:
输入一个正整数n，代表待排序字符串的个数，n不超过100，然后是n个字符串，每个字符串的长度不确定，但至少包含1个字符。n个字符串的总长度不会超过100000。

输出格式:
排序后的n个字符串，每个字符串占一行。

输入样例:
4
Where there is hope ,there is a way.
Welcome Beijing.
Nice idea.
Have fun.

输出样例:
Have fun.
Nice idea.
Welcome Beijing.
Where there is hope ,there is a way.*/
#include<stdio.h>
#include<string.h>
void zhuan(char ** p,int n){
    int i,j;
    char * a;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(strcmp(*(p+j),*(p+j+1))>0){
                a=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=a;
            }
        }
    }
}

int main(){
    char str[100005]={0};
    int a=1,n1=0,n,i,j=0;
    scanf("%d",&n);
    char *p[n];
    getchar();
    for(i=0;i<n;i++){
        p[i]=str+j;
        fgets(p[i],100005,stdin);
        n1=strlen(p[i]);
        if(*(str+j+n1-1)=='\n'){
            *(str+j+n1-1)='\0';
        }
        j+=n1;
    }
    zhuan(p,n);
    for(i=0;i<n;i++){
        printf("%s\n",p[i]);
    }
    return 0;
}
