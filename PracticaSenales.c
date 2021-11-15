#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int cont = 0;
void sighandler(int); 
void sighandler2(int);

void main(){
	
	
	pid_t hijo;
	
	hijo = fork();
	
	if(hijo == -1){
		printf("Error");	
	}else if(hijo ==0){
	
		int i = 0;
		for(i ; i<10; i++){
			
			kill(getppid(),SIGUSR1);
			sleep(1);
		}
		
	
	}else{
	
		char mensaje [10];
		while(1){
		
			signal(SIGUSR1, sighandler);
			signal(SIGINT,sighandler2);

		}	
	}
	
}
void sighandler(int signum){
	printf("Recibidida señal %d \n",signum);
}
void sighandler2(int signum){
	cont++;
	if(cont==1){
		kill(getpid(),SIGKILL);
	}else{
		printf("Vuelva a seleccionar ctrl+C para salir");
	}
	
	
	
	
}
