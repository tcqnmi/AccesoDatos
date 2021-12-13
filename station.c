#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void main(){
	
	//Recibimos por pantalla el pid del robot inicial
	int pidRobot;
	
	printf("Pid del robot: \n");
	scanf("%d",&pidRobot);
	
	int opc;
	
	//lanzamos un bucle infinito con el menú y acciones pertinentes que se repetirá
	//hasta que el usuario desee salir
	while(1){
		printf("1. Analizar la composición de la atmósfera \n");
		printf("2. Analizar la composición de las rocas \n");
		printf("3. Ver resultados del análisis \n");
		printf("4. Desconectar robot \n");
		printf("5. Cambiar de robot \n");
		printf("6. Salir \n");
		//Recogemos la opción del usuario
		scanf("%d",&opc);
		printf("\n");
		
		if(opc ==1 ){
			//Si elegimos la primera opción enviamos la señal pertinente 
			//al robot el cual comenzará con el método atmósfera	
			kill(pidRobot, SIGUSR1);
			
		}else if(opc == 2){
			//De igual manera con la señal 2 que recibirá el robot comenzará
			//con el método terreno
			kill(pidRobot, SIGUSR2);
			
		}else if(opc == 3){
			//En la opción 3 recibimos el fifo escrito en el robot y lo mostramos
			//por pantalla
			char mensaje [50];
			int fp = open("FIFO1",0);
			read(fp, mensaje, sizeof(mensaje));
			printf("%s \n",mensaje);
			
		}else if(opc == 4){
			//Enviamos una señal de cierre del programa al robot
			kill(pidRobot, SIGINT);
			
		}else if(opc == 5){
			//Recibimos por pantalla el nuevo pid y lo sustiuimos en la variable que
			//ocupaba el robot anterior
			printf("Pid del nuevo robot: \n");
			scanf("%d",&pidRobot);
			
		}else if(opc == 6){
			//Salimos del programa
			printf("Adios.");
			exit(0);
		
		}
		
	
	
	}
}
