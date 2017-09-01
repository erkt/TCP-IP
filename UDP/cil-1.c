#include"header.h"
main(int argc,char **argv){
int len,sfd;
char s[1000];
struct sockaddr_in v;
sfd=socket(AF_INET,SOCK_DGRAM,0);
if(sfd<0){
perror("socket");
return;
}
v.sin_family=AF_INET;
v.sin_port=htons(atoi(argv[1]));
v.sin_addr.s_addr=inet_addr(argv[2]);
len =sizeof(v);
printf("DATA:");
scanf("%s",s);
sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&v,len);
recvfrom(sfd,s,sizeof(s),0,(struct sockaddr*)&v,&len);
printf("CONVERTED DATA :: %s\n",s);
}

