#include<stdio.h>
void xu(int *shu,int n){
	int i,j,temp,max;
	for(i=1;i<n-1;i++){
		max=n-i;
		for(j=0;j<n-1-i;j++){
			if(shu[max]<shu[j]){
				max=j;
			}
		}
		if(max!=n-i){
			temp=shu[max];
			shu[max]=shu[n-i];
			shu[n-i]=temp;
		}
	}
	
} 
int main(){
	int shu[10]={9,8,7,6,5,4,3,2,1,0};
	int i,n=10;
	xu(shu,n);
	for(i=0;i<n;i++){
		printf("%d ",shu[i]);
	}
	return 0;
} 
