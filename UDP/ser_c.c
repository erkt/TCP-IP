#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<sys/types.h>
#include<sys/socket.h>
main(){
int len,sfd,nsfd;
struct sockaddr_in v,v1;
char c[100];
sfd=socket(AF_INET,SOCK_DGRAM,0);
v.sin_family=AF_INET;
v.sin_port=htons(9000);
v.sin_addr.s_addr=inet_addr("0.0.0.0");
len=sizeof(v);
bind(sfd,(struct sockaddr*)&v,len);
recvfrom(sfd,c,sizeof(c),0,(struct sockaddr*)&v1,&len);
puts(c);
}
