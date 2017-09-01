#include"header.h"
main(){
char s[100];
int sfd,len;
struct sockaddr_in v;
if((sfd=socket(AF_INET,SOCK_STREAM,0))<0){
perror("soket");
return;
}
perror("socket");
v.sin_family=AF_INET;
v.sin_port=htons(9876);
v.sin_addr.s_addr=inet_addr("127.0.0.1");
len =sizeof(v);
connect(sfd,(struct sockaddr*)&v,len);
perror("connect");
printf("Enter:");
scanf("%s",s);
write(sfd,s,strlen(s)+1);

read(sfd,s,sizeof(s));
printf("RX:%s\n",s);
}


