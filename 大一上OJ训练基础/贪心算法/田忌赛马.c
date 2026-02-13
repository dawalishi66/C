#include<stdio.h>
#include<stdlib.h>
int compare(const void* p1,const void* p2){
	return *(int*)p2-*(int*)p1;
}
int main(){
	int n,i,j,k,price,tian_fast=0,wang_fast=0,tian_slow,wang_slow;
	while(scanf("%d",&n)==1){
		if(n==0){
			break;
		}else{
			price=0,tian_fast=0,wang_fast=0,tian_slow=n-1,wang_slow=n-1;
			int tian[n],wang[n];
			for(i=0;i<n;i++){
				scanf("%d",&tian[i]);
			}
			getchar();
			for(i=0;i<n;i++){
				scanf("%d",&wang[i]);
			}	
			qsort(tian,n,sizeof(tian[0]),compare);	
			qsort(wang,n,sizeof(tian[0]),compare);
			for(i=0;i<n;i++){
				if (tian[tian_fast]>wang[wang_fast]) {//情况1:田忌最快的马比齐王最快的马快
                price+=200;
                tian_fast++;
                wang_fast++;
            } else if (tian[tian_fast]<wang[wang_fast]) {// 情况2：田忌最快的马比齐王最快的马慢
                price-=200;
                tian_slow--;
                wang_fast++;
            } else {// 情况3：双方最快的马速度相等
                if (tian[tian_slow]>wang[wang_slow]){// 比较最慢的马
                    price+=200;
                	tian_slow--;
                	wang_slow--;
            	}else{
            		price-=200;
            		tian_slow--;
            		wang_fast++;
				}
            }
			}
			printf("%d\n",price);
		}
	} 
	return 0;
}
