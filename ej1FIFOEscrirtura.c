#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(){


	char texto [20];
	while(1){
		printf("Introduce texto a enviar");
		fgets(texto, 20, stdin);
	
		int fp = open("FIFO1",1);
	
	
		write(fp, texto, 20);
	}

}

