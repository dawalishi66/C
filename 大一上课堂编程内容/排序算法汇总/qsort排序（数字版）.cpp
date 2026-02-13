#include<stdio.h>
#include<stdlib.h>
int compare(const void *p1,const void *p2){
	return (*(int *)p1-*(int *)p2);
}
int main(){
	int shu[10]={9,8,7,6,5,4,3,2,1,0};
	qsort(shu,10,sizeof(shu[0]),compare);
	int i;
	for(i=0;i<10;i++){
		printf("%d ",shu[i]);
	}
	return 0;
}  
