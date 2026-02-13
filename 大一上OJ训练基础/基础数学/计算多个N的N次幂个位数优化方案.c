#include<stdio.h>
int main(){
	long long a,b,c,i,j,n;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a); 
		b=a;
		c=b%4+4;
		for(j=0;j<c-1;j++){
			a=a*b%10;	
		}
		printf("%lld\n",a);
	}	
	return 0;
}
