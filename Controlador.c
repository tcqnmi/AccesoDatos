#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc, char** argv){

	int factoria;
	
	factoria = atoi (argv[1]);
	
	int opc; 
	int opcionSeleccionada = 1;

	do{

		printf("\n OPCIONES: \n");
		printf("1. Arrancar factoría \n");
		printf("2. Aumentar producción \n");
		printf("3. Disminuir producción \n");
		printf("4. Detener factoría \n");
		
		
		
		printf("\n Opción seleccionada:  %d",opcionSeleccionada);
		
		printf("\n0. Cambiar opción");
		printf("\n1. Ejecutar opción");
		
		printf("\n Opción:  ");
		
		
		
		scanf("%d",&opc);
		
		if(opc == 0){
		
			kill(factoria,SIGUSR1);
			if(opcionSeleccionada < 4){
				
				opcionSeleccionada ++;
			}else{
				opcionSeleccionada = 1;
			}
			
			
		}else if(opc == 1){
			kill(factoria,SIGUSR2);
			
			
		}
	
	
	}while(opc>-1);
	
	

}
