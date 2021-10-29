#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

	pid_t division1;
	pid_t division2;
	
	int fd1[2];
	int fd2[2];
	
	pipe(fd1);
	pipe(fd2);
	
	division1 = fork();
	
	if(division1 == -1){
		printf("Ha habido un error");
		exit(-1);
	}else if(division1 == 0 ){
		
		division2 = fork();
		
		if(division2 == -1){
		
			printf("Ha habido algún error");
		}else if(division2 == 0){
		
			printf("\n Estamos en C");
			char sendCB [35] = "Soy C enviando un mensaje a B";
			close(fd2[0]);
			write(fd2[1],sendCB, sizeof(sendCB));

			char sendBC [35];			
			close(fd1[1]);
			read(fd1[0],sendBC, sizeof(sendBC));
			printf("\n %s",sendBC);
		
		
		}else{
			printf("\n Estamos en B");
			
			char sendBA [35] = "Soy B enviando un mensaje a A";
			close(fd1[0]);
			write(fd1[1],sendBA, sizeof(sendBA));
			
			char sendBC [35] = "Soy B enviando un mensaje a C";
			write(fd1[1],sendBC, sizeof(sendBC));
			
			
			char sendAB [35];
			close(fd2[1]);
			read(fd2[0], sendAB, sizeof(sendAB));
			printf("\n %s",sendAB);
			
			char sendCB [35];
			read(fd2[0],sendCB, sizeof(sendCB));
			printf("\n %s",sendCB);
				
		}
		
	}else{
		char sendAB [35] = "Soy A escribiendo para B";
		char sendBA [35] ;
		printf("Estamos en A");
		close(fd2[0]);
		write(fd2[1],sendAB,sizeof(sendAB));
		close(fd1[1]);
		read(fd1[0],sendBA,sizeof(sendBA));
		printf("\n %s",sendBA);
			
	}
	
	wait(NULL);
	
	
}

