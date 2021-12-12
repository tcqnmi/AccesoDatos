#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

void handler1(int);
void handler2(int);
void muerte(int);


int interruptor1 = 0;
int interruptor2 = 0;
int cont1 = 0;
int cont2 = 0;
int contMuerte=0;

void main(){

	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler2);
	signal(SIGINT, muerte);
	
	pid_t pid;
	pid = getpid();
	
	char pidChar [10];
	
	sprintf(pidChar,"%d",pid), 
	
	mkfifo("FIFO1",0666);
	
	int fp;
	fp=open("FIFO1",1);
	
	write(fp, pidChar, sizeof(pidChar));
	close(fp);
	
	
	while(1){
	
		if(interruptor1==0 && interruptor2==0 ){
			sleep(1);
			printf("Nada  nuevo por ahora, todo tranquilo \n");
		
		}else if(interruptor1 == 1){
			sleep(1);
			printf("Ha recibido %d señales SIGUSR1 \n",cont1);
		}else if(interruptor2 == 1){
			sleep(1);
			printf("Ha recibido %d señales SIGUSR1 \n",cont2);
		}
	}
	

}

void handler1(int signum){
	interruptor1 = 1;
	interruptor2 = 0;
	cont1 = cont1+1;	

}
void handler2(int signum){
	interruptor1 = 0;
	interruptor2 = 1;
	cont2 = cont2+1;	

}

void muerte(int signum){
	contMuerte = contMuerte+1;
	if(contMuerte>=3){
		exit(0);
	}
}

