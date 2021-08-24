#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>
int main()
{
    system("clear")
    int clientfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(5000);
    server.sin_addr.s_addr=INADDR_ANY;
    int c=connect(clientfd,(struct sockaddr*)&server,sizeof(server) );
    

    printf("connected to server\n"); 
    char snd[20],rcv[20];
    while(1)
    { int r=recv(clientfd,rcv,sizeof(rcv),0);
      rcv[r]='\0';
      
      printf("Msg from server is: %s\n",rcv);
      
        scanf("%s",snd);
        send(clientfd,snd,strlen(snd),0);
        char snd[20],rcv[20];
        while(1)
        {   
          
            
            int r=recv(clientfd,rcv,sizeof(rcv),0);
            rcv[r]='\0';
            printf("Msg from server is: %s\n",rcv);
            printf("enter msg to server: ")
            scanf("%s",snd);
            send(clientfd,snd,strlen(snd),0);
        }
    }
}
