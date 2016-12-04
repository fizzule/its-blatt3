#include<stdio.h> //For standard things
#include<stdlib.h>    //malloc
#include<string.h>    //für strings

char server_port[65536];
int debug = 1;


int main(int argc, char **argv){
    int needed_arguments = 1; //programm self
    needed_arguments++; //Server Port
 
    if(argc==needed_arguments){
        strncpy(server_port, argv[1], sizeof server_port);
     
        if(debug){
            printf("Starting on Port: %s\n", server_port);
        }
                
    }
    else{
        printf('usage: ./pa3_server SERVER_PORT \n');
    }
  
    return 0;
}
