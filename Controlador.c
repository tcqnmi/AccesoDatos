#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(int argc, char** argv){

	printf("OPCIONES: ");
	printf("1. Arrancar factoría");
	printf("2. Aumentar producción");
	printf("3. Disminuir producción");
	printf("4. Detener factoría");
	
	int opcionSeleccionada = 1;
	
	printf("Opción seleccionada: "+opcionSeleccionada);
	
	printf("0. Cambiar opción");
	printf("1. Ejecutar opción");
	
	int opc; 
	
	scanf("%d",&opc);
	
	if(opc == 0){
	
		KILL(argv[1],SIGUSR1);
		if(opcionSeleccionada < 4){
			
			opcionSeleccionada ++;
		}else{
			opcionSeleccionada = 1;
		}
		
		
	}else if(opc == 1){
		kill(argv[1],SIGUSR2);
		
		
	}
	
	
	
	
	




}
