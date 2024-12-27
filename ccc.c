#include<stdio.h>
void main(){
	int i,j,m,n,s,min,node,nn[10],rt[20][30],delay[10];
	printf("\nenter nodes in network:\n");
	scanf("%d",&n);
	printf("\nEnter node no to update table:\n");
	scanf("%d",&s);
	printf("Enter no. of neighbouring nodes:%c",s+65);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("\nEnter the node of neighbour:");
		scanf("%d",&nn[i]);
		printf("Enter delay from %c to neighbour %c:",s+65,nn[i]+65);
		scanf("%d",&delay[i]);
	}
	printf("Enter routing of all %d neighbours:\n",m);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&rt[i][j]);
			rt[i][j] += delay[i];
		}
	}
	printf("\n The updated routing of %c is:\n",s+65);
	printf("\nTo|delay|line");
	for(i=0;i<n;i++){
	min=32767;
	for(j=0;j<m;j++){
		if(rt[j][i] <min){
			min=rt[j][i];
			node=nn[j];
		}		
	}
		if(s!=i)
		printf("\n %c| %d | %c|",i+65,min,node+65);
		else
		printf("\n %c| 0| - |",s+65);
		}
}
