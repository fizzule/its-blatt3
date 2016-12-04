#include<stdio.h> //For standard things
#include<stdlib.h>    //malloc
#include<string.h>    //für strings
#include<sys/socket.h>
#include<netinet/in.h>

char server_port[65536];
int debug = 1;
int listen = 1;

int sock_raw; // erstelle unseren socket den Wir brauchen
char buffer[65536];

/**
* Letzer aufruf um alles wichtige zu schließen
*/
void last_wish(int s){
           printf("Manuel beendet\n");
           if(sock_raw > 0) //nur falls ein socket offen ist
           {
               close(sock_raw); //schließe diesen
               printf("Socket geschlossen\n");
           }
           exit(1); //schließe
}

int main(int argc, char **argv){
   //Handlet aktivierung für STRG+C
   //http://stackoverflow.com/questions/1641182/how-can-i-catch-a-ctrl-c-event-c
   struct sigaction sigIntHandler;

   sigIntHandler.sa_handler = last_wish;
   sigemptyset(&sigIntHandler.sa_mask);
   sigIntHandler.sa_flags = 0; //setze sa flags 0

   sigaction(SIGINT, &sigIntHandler, NULL);
   // Ende für STRG+C
    
    
    int needed_arguments = 1; //programm self
    needed_arguments++; //Server Port
 
    if(argc==needed_arguments){
        strncpy(server_port, argv[1], sizeof server_port);
        
        
        
       struct sockaddr_in si_me, si_other;
       int s, i, slen=sizeof(si_other);
       char buf[BUFLEN];
       if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1){
            return 1;
       }
 
       memset((char *) &si_me, 0, sizeof(si_me));
       si_me.sin_family = AF_INET;
       si_me.sin_port = htons(PORT);
       si_me.sin_addr.s_addr = htonl(INADDR_ANY);
       if (bind(s, &si_me, sizeof(si_me))==-1){
           return 1;
       }
        
        while(listen){
           if (recvfrom(s, buf, BUFLEN, 0, &si_other, &slen)==-1){
                return 1;
           }
            printf("Received packet from %s:%d\nData: %s\n\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
        }   
        
        if(debug){
            printf("Starting on Port: %s\n", server_port);
        }
                
    }
    else{
        printf('usage: ./pa3_server SERVER_PORT \n');
    }
  
    return 0;
}
