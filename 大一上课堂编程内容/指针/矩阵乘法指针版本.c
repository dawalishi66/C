#include<stdio.h>
void multiply(int m,int n,int o,int (*p1)[n],int (*p2)[o]){
	int p3[m][o];
	int i,j,k;
	for(i=0;i<m;i++){
		for(j=0;j<o;j++){
			p3[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<o;j++){
			for(k=0;k<n;k++){
				p3[i][j]+=*(*(p1+i)+k);
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<o;j++){
			printf(" %d",p3[i][j]);
			if(j==o-1)printf("\n");
		}
	}
}
int main(){
	int m,n,o,i,j;
	printf("ÇëÊäÈëĞĞÁĞ£º\n");
	scanf("%d %d %d",&m,&n,&o);
	int arr1[m][n];
	int arr2[n][o];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<o;j++){
			scanf("%d",&arr2[i][j]);
		}
	}
	multiply(m,n,o,arr1,arr2);
	return 0;
}
