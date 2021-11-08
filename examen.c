#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

void main () {

	pid_t proc1;
	pid_t proc2;
	pid_t padre;
	
	time_t t;
	srand((unsigned) time(&t));			
	
	int fd[2];
	pipe (fd);
	
	proc1 = fork();

	if(proc1 == 0){
	
		padre = getppid();
		proc1 = getpid();
		
		printf("Soy el proceso B0. Mi pid es: %d, el pid de mi padre es: %d \n", proc1, padre);
				
		close(fd[1]);
		char mensaje [5];
		char comparativa [5];
		sprintf(comparativa, "%d",0);
		
		
		
		read(fd[0],mensaje,sizeof(mensaje));
		
		if(strcmp(comparativa,mensaje)==0){
		
			printf("Soy el proceso B0. Mi pid es: %d \n",proc1);
		}
		
		
		
	}else{
		
		proc2 = fork();
		
		if(proc2 == 0){
		
			padre = getppid();
			proc2 = getpid();
			
			
			printf("Soy el proceso B1. Mi pid es: %d, el pid de mi padre es: %d \n",proc2, padre);
						
			close(fd[1]);
			char mensaje [5];
			char comparativa [5];
			sprintf(comparativa, "%d",1);
				
			wait(NULL);
						
			read(fd[0],mensaje,sizeof(mensaje));
			
			if(strcmp(comparativa,mensaje)==0){
			
				printf("Soy el proceso B1. Mi pid es: %d \n",proc2);
				char comando[20];
				
				system("echo 'He generado un fichero' > B1.txt");
				
			}
			 
			
			
		}else{
			
			padre = getpid();
			printf("Soy el proceso A. Mi pid es: %d, el pid de mi hijo B0 es %d y el pid de mi hijo B1 es %d \n", padre, proc1, proc2);
			
			int random = rand() %2;
			printf("Proceso A. Número aleatorio: %d \n",random);
			
			char mensaje[5];
			sprintf(mensaje, "%d", random);
			
			close(fd[0]);
			write(fd[1],mensaje,sizeof(mensaje));
						
		}wait(NULL);
		
		
	}wait(NULL);
	
	
}

