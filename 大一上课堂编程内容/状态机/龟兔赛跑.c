/*乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟，于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？

输入格式：
输入在一行中给出比赛时间T（分钟）。

输出格式：
在一行中输出比赛的结果：乌龟赢输出@_@，兔子赢输出^_^，平局则输出-_-；后跟1空格，再输出胜利者跑完的距离（平局输出乌龟或兔子跑完的距离均可）。

输入样例：
242
输出样例：
@_@ 726*/
#include<stdio.h>
#define up 2
#define down 3
#define end 4
int main(){
    int t,a=0,b=0;
    scanf("%d",&t);
    int state=down;
    while(state!=end){
        switch(state){
            case up:
                if(t>30){
                    b+=90;
                    state=down;
                    t-=30;
                }
                else{
                    b+=t*3;
                    if(a>b){printf("^_^ %d",a);state=end;}
                    else if(a<b){printf("@_@ %d",b);state=end;}
                    else{printf("-_- %d",a);state=end;}
                }
                break;
            case down:
                if(t>10){
                    a+=90,b+=30;
                    if(a>b)state=up;
                    else state=down;
                    t-=10;
                }
                else{
                    a+=t*9,b+=t*3;
                    if(a>b){printf("^_^ %d",a);state=end;}
                    else if(a<b){printf("@_@ %d",b);state=end;}
                    else{printf("-_- %d",a);state=end;}
                }
                break;
        }
    }
    return 0;
}
