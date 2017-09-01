#include"header.h"
struct ca{
int a ,b,ans;
}q;
main(){
int len,sfd;
struct sockaddr_in v,v1;
sfd=socket(AF_INET,SOCK_DGRAM,0);
if(sfd<0){
perror("Socket");
return;
}
perror("socket");
len =sizeof(v);
v.sin_family=AF_INET;
v.sin_port=htons(9000);
v.sin_addr.s_addr=inet_addr("192.168.1.115");
printf("enter the data a & b");
scanf("%d %d",&q.a,&q.b);
sendto(sfd,&q,sizeof(q),0,(struct sockaddr*)&v,len);
recvfrom(sfd,&q,sizeof(q),0,(struct sockaddr*)&v1,&len);
printf("ANS:%d\n",q.ans);
}
