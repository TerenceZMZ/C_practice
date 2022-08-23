#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc == 2){
		printf("The argument supplied is %s\n",argv[1]);
	}else{
		printf("One argument expected.\n");
	}
	int sum = 0;
	char *token = NULL;
	token = strtok(argv[1], ",");
	while(token != NULL){
		sum += atoi(token);
		token = strtok(NULL, ",");
	}
	printf("%d",sum);
	return 0;
	
}
