#include<stdio.h>
void xu(int *shu,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=shu[i]; 
		for(j=i-1;j>=0&&shu[j]>temp;j--){
			shu[j+1]=shu[j];
		}
		shu[j+1]=temp;
	}
}
int main(){
	int shu[10]={9,8,7,6,5,4,3,2,1,0};
	int n=10,i;
	xu(shu,n);
	for(i=0;i<n;i++){
		printf("%d ",shu[i]);
	}
	return 0;
} 
