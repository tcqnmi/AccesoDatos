#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void encender(int);
void aumentar(int);
void disminuir(int);
void apagar(int);
void modif1(int);

int cont =1;
int encendido = 0;
int espera = 3;

void main(){

	
	

	signal(SIGUSR1, modif1);
	
	signal(SIGUSR2, encender);
	
	printf("%d\n",getpid());
	
	while(1){
	
		while(encendido == 1){
			printf("Se ha producido un producto");
			sleep(espera);
		}
		
	}
}

void modif1(int signum){

	if(cont<4){
		cont = cont+1;
	}else{
		cont =1;
	}
	
	if(cont ==1){
	
		signal(SIGUSR2, encender);
	
	}else if(cont ==2){
	
		signal(SIGUSR2, aumentar);
	
	}else if(cont ==3){
	
		signal(SIGUSR2, disminuir);
	
	}else if(cont ==4){
		signal(SIGUSR2, apagar);
	}
	
}
void encender (int signum){
	

	if(encendido ==1){
	
		printf("La fábrica ya está encendida");
	
	}else{
	
		printf("Se ha arrancado la factoría");
		encendido =1;
		espera = 3;
	
	}
}		
	
void aumentar(int signum){

	printf("Aumentando la velocidad de producción en 1 segundo");
	
	if(espera>1){
		
		espera = espera-1;
	}

}	
void disminuir(int signum){

	printf("Disminuyendo la velocidad de producción en 1 segundo");
	espera = espera+1;

}	
		
		
void apagar(int signum){

	printf("Se ha detenido la factoría");
	encendido = -1;

}
	
		
	
