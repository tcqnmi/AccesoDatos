#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//declaramos la función que posteriormente tendremos bajo el main
//porque sino el compilador no la reconocerá después
void sighandler(int);
void handler2(int);

int main(){
	//indicamos que cuando reciba la señal SIGUSR1, dejará
	//todo lo que está haciendo y ejecutará la función sighandler
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, handler2);
	
	printf("%d\n",getpid());
	
	//Hacemos un bulce infinito que muestre "esperando... " cada segundo
	//hasta que lo cancelamos
	while(1){
	
		printf("Esperando... \n");
		sleep(1);
	}
	return(0);	

}

//Declaramos la función sighandler definida al inicio del fichero
//Será llamado por nuestro proceso cuando reciba la señal SIGUSR1 
//Recibe como parámetros el número de la señal que recibe

void sighandler(int signum){

	printf("Recibida señal %d. \n",signum);
}

void handler2(int signum){

	printf("Test\n");

}
