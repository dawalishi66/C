/*小老鼠准备了M磅的猫粮，准备去和看守仓库的猫做交易，因为仓库里有小老鼠喜欢吃的五香豆。
仓库有N个房间；
第i个房间有J[i] 磅的五香豆，并且需要用F[i]磅的猫粮去交换；
老鼠不必交换该房间所有的五香豆，换句话说，它可以用 F[i]* a% 磅的猫粮去换取J[i]* a%磅的五香豆，其中a是一个实数。

现在，请帮忙计算一下，小老鼠最多能够得到多少磅的五香豆？
输入
输入包含多组测试用例。
每组测试数据首先一行是2个非负整数M和N，接着的N行，每行分别包含2个非负整数J[i]和F[i]。
输入数据以两个-1结束。
题目保证所有的数据不超过1000.
输出
请计算并输出小老鼠最多能够得到的五香豆数量。
每组数据输出一行，保留3位小数。
样例输入 Copy
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
样例输出 Copy
13.333
31.500*/
#include<stdio.h>
#include<string.h>
void max(int *a,int n){
	int x,y; 
	for(x=0;x<n-1;x++){
		int c;
		for(y=0;y<n-1-x;y++){
			if(a[y]<a[y+1]){
				c=a[y];
				a[y]=a[y+1];
				a[y+1]=c;
			}
		}
	}
}
int pan(char *str,int *shu,int n){
    int i,j,p;
    for(i=0;i<n;i++){
        shu[str[i]-'A']++;
    }
    p=0;
    for(i=0;i<26;i++){
        if(shu[i]!=0){
            shu[p]=shu[i];
            p++;
        }
    }
    max(shu,p);
    return p;
}
int main(){
    int i,j,p=1;
    char str1[105]={0},str2[105]={0};
    int shu1[26]={0},shu2[26]={0};
    scanf("%s",str1);
    scanf("%s",str2);
    int a=strlen(str1),b=strlen(str2);
    int x=pan(str1,shu1,a);
    int y=pan(str2,shu2,b);
    if(x==y){
        for(i=0;i<x;i++){
            if(shu1[i]!=shu2[i])p=0;
        }
        if(p){
                printf("YES\n");
                return 0;
            }
    }
    printf("NO\n");
    return 0;
}
