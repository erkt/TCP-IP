#include"header.h"
main(){
char s[20];
int len;
struct sockaddr_in v,v1;
int sfd;

sfd=socket(AF_INET,SOCK_DGRAM,0);
if(sfd<0){
perror("socket");
return;
}
perror("socket");
printf("SFD=%d\n",sfd);
v.sin_family=AF_INET;
v.sin_port=htons(9999);
v.sin_addr.s_addr=inet_addr("127.0.0.1");
len =sizeof(v);
printf("Enter the Data:");
scanf("%s",s);
sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&v,len);

}
