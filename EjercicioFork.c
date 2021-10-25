#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	pid_t padre;
	pid_t hijo;
	pid_t pidDelFork;
	pid_t nieto;

	pidDelFork = fork();
	
	if(pidDelFork ==-1){
		printf("Error");
	
	}
	else if(pidDelFork == 0){
	
		padre = getppid();
		hijo = getpid();
		
		nieto = fork();
		if(nieto == -1){
			printf("Error");
		}else if (nieto == 0){
			nieto = getpid();
			printf("Soy el proceso nieto \n Mi PID es: %d \n El PID de mi padre es: %d \n El PID de mi abuelo es: %d ",nieto, hijo, padre);
		}else{
			printf("Soy el proceso hijo \n Mi PID es: %d \n El PID de mi padre es: %d \n El PID de mi hijo es: %d", hijo, padre, nieto);
		}
		
	}else{
	
		padre = getppid();
		hijo = getpid();
		printf("Soy el proceso padre \n Mi PID es: %d \n",hijo);  
		printf(" El PID de mi padre es: %d \n El PID de mi hijo es:%d", padre, pidDelFork);
	
	
	}
	
	wait(NULL);

}
