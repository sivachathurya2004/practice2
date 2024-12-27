#include<stdio.h>
int main(){
	int windowsize,ack,sent=0,i;
	printf("Enter size of window:");
	scanf("%d",&windowsize);
	while(1){
	for(i=0;i<=windowsize;i++){
		printf("Frame %d has been transmitted.\n",sent);
		sent++;
		if(sent==windowsize)
		break;
	}
		printf("Enter the last Acknowledgement\n");
		scanf("%d",&ack);
		if(ack==windowsize)
		break;
		else
		sent = ack;
	}
	return 0;
}
