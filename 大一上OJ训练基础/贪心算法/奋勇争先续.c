#include<stdio.h>
#include<string.h>
typedef struct student{
	char name[15];
	int num;
	int time;
}stu;
int compare(stu *p,int i){
	if(p[i].num>p[i+1].num){
		return 1;
	}
	else if(p[i].num<p[i+1].num)return 0;
	else{
		if(p[i].time<p[i+1].time)return 1;
		else return 0;
	}
}
int main(){
	int n,a,b,k;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%d %d",&a,&b);
		stu p[a];
		stu temp;
		int i,j;
		for(i=0;i<a;i++){
			scanf("%s %d %d",&p[i].name,&p[i].num,&p[i].time);
		}
		for(i=0;i<a-1;i++){
			for(j=0;j<a-i-1;j++){
				if(!compare(p,j)){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}	
		}
		for(i=0;i<b;i++){
			printf("%s %d %d\n",p[i].name,p[i].num,p[i].time);
		}
	}
	return 0;
}
