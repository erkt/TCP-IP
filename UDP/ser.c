#include"header.h"
main(){
	char s[20];
	int len;
	struct sockaddr_in v,v1;
	int sfd;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0){
		perror("Socket:");
		return;
	}
	perror("soket");
	printf("SFD=%d\n",sfd);
	v.sin_family=AF_INET;
	v.sin_port=htons(9999);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);
	bind(sfd,(struct sockaddr*)&v,len);
	perror("BIND");
	recvfrom(sfd,s,sizeof(s),0,(struct sockaddr*)&v1,&len);
	printf("DATA:%s\n",s);
}
