#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void handler(int);
void modif1(int);

int cont =0;

void main(){

	
	

	signal(SIGUSR1, modif1);
	
	signal(SIGUSR2, handler);
	
	printf("%d\n",getpid());
	
	while(1){
		
	}
}

void modif1(int signal){

	if(cont<4){
		cont = cont+1;
	}else{
		cont =1;
	}
	
}
void handler(int signal){
	int encender = 0;
	int espera = 0;

	if(cont ==1){
	
		printf("Se ha arrancado la factoría");
		encender =1;
		espera = 3;
		
	
	}else if(cont ==2){
	
		printf("Aumentando la velocidad de producción en 1 segundo");
	
		if(espera>1){
		
			espera = espera-1;
		}
	
	
	}else if(cont ==3){
		
		printf("Disminuyendo la velocidad de producción en 1 segundo");
		espera = espera+1;
	
	}else if(cont ==4){
	
		printf("Se ha detenido la factoría");
		encender = -1;
	
	}
	
	while(encender > 0){
			printf("Se ha producido un producto");
			sleep(espera);
	}
	

}
