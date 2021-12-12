#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

int main(){

	int fp;
	fp = open("FIFO1",0);
	char pidChar [10];
	read(fp,pidChar, sizeof(pidChar));
	int pidB = atoi(pidChar); 
	while(1){
	
		printf("Enviar SIGUSR1 -> 0 \n");
		printf("Enviar SIGUSR2 -> 1 \n");
		
		int opc;
		scanf("%d",&opc);
		if(opc ==0){
			kill(pidB,SIGUSR1);		
		}else if(opc ==1){
			kill(pidB,SIGUSR2);
		}
	}

	return(0);
}
