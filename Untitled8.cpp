#include<stdio.h>
int main()
{
 int n,s,nn[10],delay[10],m,rt[20][30],i,j,min,node;
 printf("\n enter no of nodes in a network:");
 scanf("%d",&n);
 printf("\n enter node no(A-0,B-1,..,H-7,I-8,J-9,K-10 to update roouting table:");
 scanf("%d",&s);
 printf("\n enter no of neighbours for %c",s+65);
 scanf("%d",&m);
 for(i=0;i<m;i++)
 {
 printf("\n enter neighbouring node no:");
 scanf("%d",&nn[i]);
 printf("\n enter delay from %c to neighbour %c:",s+65,nn[i]+65);
 scanf("%d",&delay[i]);
 }
 printf("\n enter routing tables of all %d neighbours:",m);
 for(i=0;i<m;i++)
 {
 for(j=0;j<n;j++)
 {
scanf("%d",&rt[i][j]);
rt[i][j]+=delay[i];
 }
 }
 // find neighbour with min delay from all its neighbour to other nodes
 printf("\n The updated routing of %c is:\n",s+65);
printf("\nTo|delay|line");
 for(i=0;i<n;i++)
 {
 min=32767;
 for(j=0;j<m;j++)
 {
 if(rt[j][i] <min)
 {
 min=rt[j][i];
 node=nn[j];
 }
 }
 if(s!=i)
 printf("\n %c| %d | %c|",i+65,min,node+65);
else
printf("\n %c| 0| - |",s+65);
 }
 //getch();
}

