#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>
struct st{
int op[10];
}v2;
main(int  argc,char**argv){
int len ,sfd,i;
struct sockaddr_in v;
sfd=socket(AF_INET,SOCK_STREAM,0);
perror("SOCKET");
v.sin_family=AF_INET;
v.sin_port=htons(atoi(argv[1]));
v.sin_addr.s_addr=inet_addr(argv[2]);
len = sizeof(v);
connect(sfd,(struct sockaddr*)&v,len);
perror("connet");
for(i=0;i<10;i++)
scanf("%d",&v2.op[i]);

write(sfd,&v2,sizeof(v2));
}

