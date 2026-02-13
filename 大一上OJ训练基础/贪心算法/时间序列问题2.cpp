#include<stdio.h>
void min(int *a,int *b,int n){
	int x,y; 
	for(x=0;x<n-1;x++){
		int c,g;
		for(y=0;y<n-1-x;y++){
			if(a[y]>a[y+1]){
				c=a[y],g=b[y];
				a[y]=a[y+1],b[y]=b[y+1];
				a[y+1]=c,b[y+1]=g;
			}
		}
	}
}
int main(){
	int n,i;
	while(scanf("%d",&n)==1&&n!=0){
		int ti_s[n],ti_e[n];
		for(i=0;i<n;i++){
			scanf("%d %d",&ti_s[i],&ti_e[i]);
		}
		min(ti_e,ti_s,n);		
		int num=0,x=0,start=0,min1=24,max1=0,min2=24;
		for(i=0;i<n;i++){
			min1=min1<ti_s[i]?min1:ti_s[i];
			max1=max1>ti_s[i]?max1:ti_s[i];
		}
		start=min1;
		while(start<=max1){
			for(i=0;i<n;i++){
				if(ti_s[i]>=start){
					start=ti_e[i];
					num++;
					break;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
