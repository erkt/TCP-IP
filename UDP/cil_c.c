#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
main(){
int len,sfd,i;
struct sockaddr_in v;
char c[100];
sfd=socket(AF_INET,SOCK_DGRAM,0);
v.sin_family=AF_INET;
v.sin_port=htons(9000);
v.sin_addr.s_addr=inet_addr("127.0.0.1");
len=sizeof(v);
for(i=0;i<10;i++)
scanf("%c",&c[i]);


sendto(sfd,c,strlen(c)+1,0,(struct sockaddr*)&v,len);
}


