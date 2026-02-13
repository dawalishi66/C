#include<stdio.h>
int main(){
	int arr1[]={1,2,3,4,5};
	int arr2[]={6,7,8,9,10};
	int* arr[]={arr1,arr2};
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<5;j++){
			printf("%d",arr[i][j]);
		}
	}
	return 0;
}
