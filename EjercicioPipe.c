#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	
	int fd[2];
	pipe(fd);
	
	int fd2[2];
	pipe(fd2);
	
	pid = fork();
	if (pid == -1){
		printf("Ha habido algún error");
		exit(-1);

	}else if(pid == 0){
		char mensaje[10];
		close(fd[1]);
		read(fd[0],mensaje,sizeof(mensaje));
		printf("\n Soy el proceso hijo. Recibo el mensaje %s \n",mensaje);
		close(fd2[0]);
		char mensaje2[10] = "Segundo";
		write(fd2[1], mensaje2, sizeof(mensaje2));
		printf("\n Soy el proceso hijo. Envío el mensaje %s \n",mensaje2);
		
		
		
	}else{
	
		char cadena[10] = "Test";
		close(fd[0]);
		printf("Soy el proceso padre. Envío mensaje %s  \n", cadena);
		write(fd[1],cadena,sizeof(cadena));
		
		char cadena2[10];
		close(fd2[1]);
		read(fd2[0],cadena2,sizeof(cadena2));
		printf("Soy el proceso padre. Recibo el mensaje %s  \n", cadena2);
		
	
		
	
	}

}
