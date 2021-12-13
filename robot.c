#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>



void atmosfera(int);
void terreno(int);

void main(){

	pid_t pid;
	pid = getpid();

	//Imprimimos el pid del robot
	printf("Pid del robot: %d \n",pid);
	
	//Indicamos qué realizar al recibir las señales pertinentes
	signal(SIGUSR1, atmosfera);
	signal(SIGUSR2, terreno);
	
	//Generamos un bucle infinito con el mensaje idicado cada segundo
	while(1){
		sleep(1);
		printf("Explorando... \n");
	
	}
}

//El método atmósfera muestra por pantalla el mensaje de su análisis y almacena en el fifo
//la información sobre este
void atmosfera (int signumber){

	printf("Analizando composición de la atmósfera \n");
	char mensaje [50] = "Resultados del análisis de la atmósfera \n";
	
	mkfifo("FIFO1",0666);
	int fp;
	fp = open("FIFO1", 1);
	
	write(fp, mensaje, sizeof(mensaje));

}

//El método terreno realiza lo mismo que el método atmósfera pero en este caso con los
//cambios pertinentes en el texto
void terreno (int signumber){

	printf("Analizando composición del terreno \n");
	char mensaje [50] = "Resultados del análisis del terreno \n";
	
	mkfifo("FIFO1",0666);
	int fp;
	fp = open("FIFO1", 1);
	
	write(fp, mensaje, sizeof(mensaje));

}
