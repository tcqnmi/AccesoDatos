#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){

	pid_t proc1;
	pid_t proc2;
	pid_t proc3;

	int fd[2];

	pipe(fd);
	
	proc1=fork();
	
	if(proc1 == -1){
	
		printf("Ha habido un error");
	
	}else if(proc1 == 0){
	
		proc3=fork();
		
		if(proc3 == -1){
	
			printf("Ha habido un error");
	
		}else if(proc3 == 0){
	
			printf("Estamos en el proceso C \n");	
	
		}else{
	
			wait(NULL);
			printf("Estamos en el proceso B1 \n");
		
		}
		
			
	
	}else{
	
		proc2=fork();
		
		if(proc2 == -1){
	
			printf("Ha habido un error");
	
		}else if(proc2 == 0){
	
			printf("Estamos en el proceso B2 \n");
			char mensaje [20] = "Mensaje de prueba";
			close(fd[0]);
			write(fd[1],mensaje,sizeof(mensaje)); 	
	
		}else{
	
			wait(NULL);
			printf("Estamos en el proceso A \n");
			char mensaje [20];
			wait(NULL);
			close(fd[1]);
			
			read(fd[0],mensaje, sizeof(mensaje));
			
			printf("%s \n",mensaje);
			char comando [40];
			sprintf(comando, "echo %s > mensaje.txt",mensaje);
			system(comando);
		
		}
		
	
	}




}
