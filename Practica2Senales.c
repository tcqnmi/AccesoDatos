#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void envioB1(int);
void envioB2(int);
void reciboB1(int);
void reciboB2(int);

void main(){

	pid_t hijoB1;
	pid_t hijoB2;

	hijoB1 = fork();
	
	if(hijoB1 == -1){
		printf("Error");
	}else if(hijoB1 == 0){
	
		signal(SIGUSR1,envioB1);
		printf("Soy hijo B1");
		
	}else{
	
		hijoB2 = fork();
		
		if(hijoB2 == -1){
			printf("Error");
		}else if(hijoB2 == 0){
				
			signal(SIGUSR2, envioB2);
			printf("Soy hijo B2");			
		
		}else{
		
			signal(SIGUSR2, reciboB1);
			signal(SIGUSR1, reciboB2);
		
			while(1){	
			
				kill(hijoB1, SIGUSR1);
				printf("Envío señal a B1 \n");
				
				kill(hijoB2, SIGUSR2);
				printf("Envío señal a B2 \n");
				
				sleep(1);
				
			}	
		
		}		
	
	}

}
void envioB1(int signum){

	kill(getppid(), SIGUSR2);

}
void envioB2(int signum){

	kill(getppid(), SIGUSR1);

}
void reciboB1(int signum){

	printf("EL hijo B1 ha respondido a la señal \n");

}
void reciboB2(int signum){

	printf("El hijo B2 ha respondido a la señal \n ");
	
}

