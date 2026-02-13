#include<stdio.h>
int main(){
    int n,i,j,r=0,c=0;
    scanf("%d",&n);
    int shu[n][n];
    for(i=1;i<=n*n;i++){
        shu[r][c]=i;
        if((r+c)%2==0){
            if(c==0&&r<n-1)r++;
            else if(r==n-1)c++;
            else r++,c--;
        }
        else{
            if(r==0&&c<n-1)c++;
            else if(c==n-1)r++;
            else r--,c++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",shu[i][j]);
            if(j==n-1)printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
