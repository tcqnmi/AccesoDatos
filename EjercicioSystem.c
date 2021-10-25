#include <stdio.h>
#include <stdlib.h>
void main(){
	printf("Programa que hace una llamada al sistema para ejecutar otro programa. \n");

	system("ls > ficheroSalida.txt");
	system("gedit ficheroSalida.txt");
}
