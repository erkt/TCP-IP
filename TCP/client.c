#include"header.h"
main(){

	char s[20];
	int len;
	struct sockaddr_in v,v1;
	int sfd,nsfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0){
		perror("SOCKET");
		return;
	}
	perror("socket");
	printf("SFD:%d\n",sfd);
	v.sin_family=AF_INET;
	v.sin_port=htons(2003);
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(v);
	connect(sfd,(struct sockaddr*)&v,len);
	perror("connect");
	printf("Enter The DATA:");
	scanf("%s",s);
	write(sfd,s,strlen(s)+1);
}
