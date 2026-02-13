#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *p1,const void *p2){
	return strcmp(p1,p2);
}
int main(){
	char s[10]="ihgfedcba";
	qsort(s,10,sizeof(s[0]),compare);
	int i;
	for(i=0;i<10;i++){
		printf("%c ",s[i]);
	}
	return 0;
}  
