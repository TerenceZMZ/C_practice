#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc ==2){
        printf("THe argument supplied is %s\n", argv[1]);
    }else{
        printf("One argument expected.\n");
    }
    char *str[5];
    char *token = strtok(argv[1], ",");
    int tmp = 0;
    while(token != NULL){
        str[tmp] = token;
        token = strtok(NULL, ",");
        tmp++;
    }
    int i = 0;
    int j = 0;
    for(; i<tmp; i++){
        for(j = i+1; j < tmp; j++){
            char  *temp;
            if(strcmp(str[j-1], str[j])>0){
                temp = str[j-1];
                str[j-1] = str[j];
                str[j] = temp;
            }
        }
    }
    for (int i = 0; i<tmp; i++){
        printf("%s < ", str[i]);
    }
    printf("\n");
}