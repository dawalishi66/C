/*给定一个字符串，请分析该字符串格式，检查它是否符合10进制整数的表示格式（除了特别提醒以外其他均按正常整数格式处理）。

特别提醒：
1、字符串如果有前导0，如0123，则该字符串不符合整数格式；
2、+0，-0是不符合整数格式的，但+1和-1都是符合的；
3、科学记数法是不符合的。

输入格式:
第一行为一个整数t(0<t<=10)，代表测试用例组数。后边t行字符串（每个字符串长度都不超过30，且不包含空格和制表符tab），每行代表一个待检测字符串。

输出格式:
共t行，依次对应输入的测试用例，如果符合则输出yes，否则输出no。

输入样例:
8
1
-1
200
999
-999
0123
+0
-0

输出样例:
yes
yes
yes
yes
yes
no
no
no
*/
#include<stdio.h>
#define start 1
#define sign 2
#define data 3
#define zero 4
#define err 5
#define end 6
int main(){
    int t,i;
    scanf("%d",&t); 
    getchar();
    for(i=0;i<t;i++){
        int state=start;
        char ch;
        while(1){
            ch=getchar();
            if(ch=='\n'){
                break;
            }
            switch(state){
                case start:
                    if(ch=='0')state=zero;
                    else if(ch=='+'||ch=='-')state=sign;
                    else if(ch>='0'&&ch<='9')state=data;
                    else state=err;
                    break;
                case zero:
                    state=err;
                    break;
                case sign:
                    if(ch>='1'&&ch<='9')state=data;
                    else if(ch=='0')state=err;
                    else state=err;
                    break;
                case data:
                    if(ch>='0'&&ch<='9')state=data;
                    else state=err;
                    break;
            }
        }
            if(state==end||state==zero||state==data){
                printf("yes\n");
            }else{
                printf("no\n");
            }
    }
    return 0;
}
 
