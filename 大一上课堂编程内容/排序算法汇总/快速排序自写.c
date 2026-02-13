#include<stdio.h>
void qs(int shu[],int low,int high){
	int a;
	if(low<high){
		a=sort(shu,low,high);
		qs(shu,low,a-1);
		qs(shu,a+1,high);
	}
}
int sort(int shu[],int low,int high){
	int b=shu[low];
	while(low<high){
		while(low<high&&shu[high]>=b){
			high--;
		}
		shu[low]=shu[high];
		while(low<high&&shu[low]<=b){
			low++;
		}
		shu[high]=shu[low];
	}
	shu[low]=b;
	return low;
}
int main(){
	int shu[]={36,2,5,7,36,8,34}; 
	qs(shu,0,6);
	int i;
	for(i=0;i<7;i++){
		printf("%d ",shu[i]);
	}
	return 0;	
}
