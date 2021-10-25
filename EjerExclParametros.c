#include <stdio.h>
#include <unistd.h>

void main(int argc, char** argv){

	
	printf("Programa que hace una llamada al sistema para ejecutar otro programa. Pidiendo al usuario los parámetros de búsqueda \n");
	
	printf("He recibido %d argumentos \n",argc);
	
	//EL argumento 0 es el nombre de nuestro programa
	
	printf("%s%s \n","El argumento 0 es", argv[0]);
	printf("%s%s \n","El argumento 0 es", argv[1]);

	execl("/bin/ls","ls",argv[1],(char*)NULL);
}
