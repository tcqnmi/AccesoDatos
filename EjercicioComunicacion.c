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
			
			char sendBC [35];			
			close(fd1[1]);
			read(fd1[0],sendBC, sizeof(sendBC));
			printf("\n %s \n",sendBC);
			
			char sendCB [35] = "Soy C enviando un mensaje a B";
			close(fd2[0]);
			write(fd2[1],sendCB, sizeof(sendCB));

			
		
		
		}else{
			printf("\n Estamos en B");
			
			close(fd2[1]);
			
			char sendAB [35];
			read(fd2[0], sendAB, sizeof(sendAB));
			printf("\n %s \n",sendAB);
			
			close(fd1[0]);
			
			char sendBC [35] = "Soy B enviando un mensaje a C";
			write(fd1[1],sendBC, sizeof(sendBC));
			
			char sendCB [35];
			read(fd2[0],sendCB, sizeof(sendCB));
			printf("\n %s \n",sendCB);
			
			char sendBA [35] = "Soy B enviando un mensaje a A";
			write(fd1[1],sendBA, sizeof(sendBA));
			
			
			
			
				
		}
		
	}else{
		
		
		char sendAB [35] = "Soy A enviando un mensaje a B";
		printf("\n Estamos en A");
		close(fd2[0]);
		write(fd2[1],sendAB,sizeof(sendAB));
		
		wait(NULL);
		
		char sendBA [35] ;
		close(fd1[1]);
		read(fd1[0],sendBA,sizeof(sendBA));
		printf("\n %s \n",sendBA);
			
	}
	
	
	
	
}

