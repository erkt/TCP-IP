#include"header.h"
main(int argc ,char **argv)
{
	int sfd,nsfd,len;
	char s[100];
	struct sockaddr_in v,v1;

	sfd=socket(AF_INET,SOCK_STREAM,0);
	
	perror("SOCKET");

	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);

	bind(sfd,(struct sockaddr*)&v,len);
	perror("BIND");

	listen(sfd,5);
	perror("LISTEN");

	printf("BEFORE ACCPET\n");
	nsfd=accept (sfd,(struct sockaddr*)&v1,&len);
	printf("After");

	read(nsfd,s,sizeof(s));
	printf("%s\n",s);
}

