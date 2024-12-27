#include<stdio.h>
#include<string.h>
#include<conio.h>
int main(){
	char ip[50],op[100];
	int i,j;
	printf("\nEnter the text:");
	gets(ip);
	for(i=0,j=0;ip[i]!='\0';i++,j++){
		op[j] = ip[i];
		if(strncmp(ip+i,"11111",5)==0){
			op[j] = '\0';
			strcat(op,"111110");
			i = i+4;
			j = j+5;
		}
	}
	op[j] = '\0';
	printf("\noutput is:01111110 %s 01111110",op);
	getch();
}
