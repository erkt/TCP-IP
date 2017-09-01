#include"header.h"
struct cl{
	int a,b,ans;
}q;
main(){
	int len;
	struct sockaddr_in v,v1;
	int sfd;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0){
		perror("Socket");
		return;
	}
	perror("Socket");
	printf("sfd=%d\n",sfd);
	len=sizeof(v);
	v.sin_family=AF_INET;
	v.sin_port=htons(9000);
	v.sin_addr.s_addr=inet_addr("192.168.1.115");
	bind(sfd,(struct sockaddr*)&v,sizeof(v));
	perror("BIND:");
	recvfrom(sfd,&q,sizeof(q),0,(struct sockaddr*)&v1,&len);
	q.ans=q.a+q.b;
	printf("D:%d\n",q.ans);
	sendto(sfd,&q,sizeof(q),0,(struct sockaddr*)&v1,len);
}
