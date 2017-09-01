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
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);
	bind(sfd,(struct sockaddr*)&v,len);
	perror("bind");
	listen(sfd,5);
	perror("LISTEN");
	printf("BEFORE\n");
	nsfd=accept(sfd,(struct sockaddr*)&v1,&len);
	perror("ACCEPT");
	read(nsfd,s,sizeof(s));
	printf("%s\n",s);
}
