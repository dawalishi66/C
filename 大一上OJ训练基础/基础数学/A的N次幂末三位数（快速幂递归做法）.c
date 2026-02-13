#include<stdio.h>
int life(int a,int n){
	if(n==0){
		return 1;
	}
	else{
		int half=life(a*a%1000,n/2);
		if(n%2==1){
			return half%1000*a%1000;
		}
		else return half%1000;	
	}
}
int main(){
	int a,b,c;
	while(scanf("%d %d",&a,&b)==2){
		if(a==0&&b==0){
			break;
		}
		c=life(a,b);
		printf("%d\n",c);
	}
	return 0;	
}
