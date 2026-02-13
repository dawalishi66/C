#include <stdio.h>
int main(void){
    long long n1,n2,a,b,c,i,j,k;
    scanf("%lld",&n1);
    for(i=0;i<n1;i++){
    	scanf("%lld",&n2);
        long long shu[n2];
        for(j=0;j<n2;j++){
            scanf("%lld",&shu[j]);
        }
        for(k=0;k<n2-1;k++){
            a=shu[k],b=shu[k+1];
            while(b!=0){
		        c=a%b;
		        a=b;
		        b=c;
	        }
            shu[k+1]=shu[k]*shu[k+1]/a;//最小公倍数等于两数乘积除以最大公约数 
        }
    	printf("%lld\n",shu[n2-1]);
    }
	return 0;
}
