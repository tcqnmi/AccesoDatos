#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (int arg, char ** argv){

	printf("%s",argv[1]);
	printf("%s",argv[2]);

	execl("/usr/bin/ls","ls", argv[2], (char*)NULL);


}
