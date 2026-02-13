#include<stdio.h>
int life(int a,int n){
	int answer=1;
	while(n!=0){
		if(n%2==1){
			answer=answer*a%1000;
		}
		a=a*a%1000;
		n=n/2;
	}
	return answer;
}
int main(){
	int a,b,c;
	while(scanf("%d %d",&a,&b)==2){
		c=life(a,b);
		printf("%d\n",c);
	}
	return 0;	
}
