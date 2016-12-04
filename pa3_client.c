#include<stdio.h> //For standard things
#include<stdlib.h>    //malloc
#include<string.h>    //für strings

server_adress[1024];
server_port[1024];
username[1024];
char message[65536];
 
int main(int argc, char **argv){
    int needed_arguments = 1; //programm self
    needed_arguments++; //Server Adress
    needed_arguments++; //Server Port
    needed_arguments++; //UserName
    needed_arguments++; //From Here up the Message
 
    if(argc>=5){
     printf("usage: ./pa3_client SERVER_ADRESS SERVER_PORT USERNAME 'Message to encypt' \n");
    }
    else{
       printf("usage: ./pa3_client SERVER_ADRESS SERVER_PORT USERNAME 'Message to encypt' \n");
    }
 
    return 0;
}
