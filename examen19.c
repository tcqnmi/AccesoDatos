#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	int fdb [2];
	
	pipe(fdb);
	
	pid_t proca;
	pid_t procb;
	
	procb = fork();
	
	if(procb == -1){
	
		printf("Ha habido un error");
	
	
	}else if(procb == 0){
	
		procb = getpid();
		proca = getppid();
		printf("Proceso B. Mi pid es: %d, el pid de mi padre es: %d \n",procb,proca);
		
		int i;
		int limit = rand()%11;
		for (i=0; i<limit; i++){
			
			printf("Proceso B. Iteración %d \n",i);
			
			
			
		}
		char sendBtoA [15];
		sprintf (sendBtoA, "%d", limit);
		close(fdb[0]);
		write(fdb[1], sendBtoA, sizeof(sendBtoA));
		char comando [50];
		sprintf(comando," echo %d >> numAleatorio.txt", limit );
		
		
		system(comando);
	}else{
	
		proca = getpid();
		printf("Proceso A. Mi pid es: %d, el pid de mi hijo es: %d \n ",proca,procb);
		char sendBtoA [15];
		close(fdb[1]);
		
		wait(NULL);
		
		read(fdb[0], sendBtoA, sizeof(sendBtoA));
		printf("Proceso  A. El proceso B ha compeltado %s iteraciones \n",sendBtoA);
		
		
	
	}
	
}

