#include<stdio.h>
int main(){
	int n,i;
	while(scanf("%d",&n)==1&&n!=0){
		int ti_s[n],ti_e[n];
		for(i=0;i<n;i++){
			scanf("%d %d",&ti_s[i],&ti_e[i]);
		}
		int num=0,x=0,start=0,min1=24,max1=0,min2=24;
		for(i=0;i<n;i++){
			min1=min1<ti_s[i]?min1:ti_s[i];
			max1=max1>ti_s[i]?max1:ti_s[i];
		}
		start=min1;
		while(start<=max1){
			min2=24;
			for(i=0;i<n;i++){
				if(ti_s[i]>=start&&min2>ti_e[i]){
					min2=ti_e[i],x=i;
				}
			}
			start=min2;
			num++;
		}
		printf("%d",num);
	}
	return 0;
}
