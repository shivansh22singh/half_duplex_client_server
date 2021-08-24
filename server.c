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
    int severfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    struct sockaddr_in server,client;
    server.sin_family=AF_INET;
    server.sin_port=htons(5000);
    server.sin_addr.s_addr=INADDR_ANY;
    int b=bind(serverfd,(struct sockaddr*)&server,sizeof(server) );
    
    listen(serverfd,5);
    int size=sizeof(client);
    int clientfd=accept(serevrfd,(struct sockaddr*)&client,&size);
    printf("incoming request from %s\n",inet_ntoa(client.sin_addr)); 
        char snd[20],rcv[20];
    while(1)
    {  
        printf("Enter msg to client: ");
        scanf("%s",snd);
       
        send(clientfd,snd,strlen(snd),0);
         if(strcmp(snd,"exit")==0)
        break;
         int r=recv(clientfd,rcv,sizeof(rcv),0);
            rcv[r]='\0';
            
            printf("Msg from client is: %s\n",rcv);
        if(strcmp(rcv,"exit")==0)
        break;
    }
}
