#include <stdio.h>
#include <unistd.h>

void main(){
	printf("Programa que hace una llamada al sistema para ejecutar otro programa (EXECL). \n");

	execl("/bin/ls","ls",(char*)NULL);
}
