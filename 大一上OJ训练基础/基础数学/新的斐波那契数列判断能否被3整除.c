#include<stdio.h>
int main(){
	long long a,b,c,n,i,j;
	while(scanf("%lld",&n)==1){
		a=1;
		b=2;
		if(n<2){
			printf("no\n");
		}else{
			j=(n-1)%8;
			for(i=0;i<j;i++){
				c=(a+b)%3;//加法、乘法取模可直接分开取模，减法取模注意若分开计算为负数，需加上除数 
				a=b;
				b=c;
			}
			if(c%3==0){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}
	return 0;
}
