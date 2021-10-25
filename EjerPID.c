#include <stdio.h>
#include <unistd.h>

void main(){

	pid_t padre;
	pid_t hijo;
	
	padre = getppid();
	hijo = getpid();
	
	printf("PID del padre %d \n",padre);
	printf("PID del hijo %d \n",hijo);

}
