#include<stdio.h>
void main(){
	int a[100][100],c,v[100],i,j,k,l,n,min=32765;
	printf("\nEnter num of subnets:");
	scanf("%d",&n);
	printf("\nenter -1 for no link for adjacent matrix:");
	for(i=0;i<n;i++){
		v[i] = 0;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=-1 && min>a[i][j]){
				min = a[i][j];
				k=i;
				l=j;
			}	
		}
	}
	printf("\nThe links of broadcast tree are:");
	printf("%c - %c with delay %d\n",k+65,l+65,min);
	v[k]=v[l]=1;
	c=1;
	while(c<=n-2){
		min=32765;
		for(i=0;i<n;i++){
			if(v[i]==1){
				for(j=0;j<n;j++){			
				if(a[i][j]!=-1 &&v[j]==0 && min>a[i][j]){
					min = a[i][j];
					k=i;
					l=j;
			}	
			}
			}
			
		}
		v[l]=1;
		printf("%c - %c with delay %d\n",k+65,l+65,min);
		c++;
	}
	
}
