#include<stdio.h>
void xu(int *shu,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(shu[j]>shu[j+1]){
				temp=shu[j];
				shu[j]=shu[j+1];
				shu[j+1]=temp;
			}
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
