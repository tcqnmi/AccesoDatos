#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (int argc, char ** argv){


	
	execl("/bin/rm","rm","mensaje.txt",(char*)NULL);
	
	//execl("/bin/echo","echo","adios799>>","mensaje.txt",(char*)NULL);
	
	//execl(ruta,funcion,comando,envio, (char*)NULL);

}
