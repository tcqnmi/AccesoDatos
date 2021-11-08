#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(){

	mkfifo("FIFO1", 0666);
	
	//puntero al fifo que se crea
	int fp= open("FIFO1",0);
	
	// con el 0 indicamos que vamos a leer el fifo
	
	char buffer [10];
	while(1){
		read (fp,buffer,10);
		printf("%s",buffer);
	}
	
	


}



