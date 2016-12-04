#include<stdio.h> //For standard things
#include<stdlib.h>    //malloc
#include<string.h>    //für strings

server_adress[65536];
server_port[65536];
username[65536];
char message[65536];

int check_parameters();

 
int main(int argc, char **argv){
    int needed_arguments = 1; //programm self
    needed_arguments++; //Server Adress
    needed_arguments++; //Server Port
    needed_arguments++; //UserName
    needed_arguments++; //From Here up the Message
 
    if(argc>=5){
       strncpy(server_adress, argv[1], sizeof server_adress);
       strncpy(server_port, argv[2], sizeof server_port);
       strncpy(username, argv[2], sizeof username);
     
       printf("Server Adress: %s\n", server_adress);
       printf("Server Port: %s\n", server_port);
       printf("Username: %s\n", username);
       
    }
    else{
       printf("usage: ./pa3_client SERVER_ADRESS SERVER_PORT USERNAME 'Message to encypt' \n");
    }
 
    return 0;
}

