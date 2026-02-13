#include<stdio.h>
void wakeup(int x,void (*p)()){
	printf("已经%d点了",x);
	p();
}
void wakeup1(){
	printf(",响铃5下");
}
void wakeup2(){
	printf(",敲门");
}
int main(){
	int a;
	scanf("%d",&a);
	switch(a){
		case 1:
			wakeup(7,wakeup1);
			break;
		case 2:
			wakeup(7,wakeup2);
			break;
	}
	return 0;
}
