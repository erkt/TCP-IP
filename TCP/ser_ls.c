#include"header.h"
main(int argc,char**argv){
	int len,sfd,nsfd,fd;
	char s[100];
	struct sockaddr_in v,v1;
	if((sfd=socket(AF_INET,SOCK_STREAM,0))<0){
		perror("SOCKET");
		return;
	}
	perror("SOCKET");

	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len = sizeof(v);

	bind(sfd,(struct sockaddr*)&v,len);
	perror("BIND");

	listen(sfd,5);
	perror("LISTEN");

	nsfd=accept(sfd,(struct sockaddr*)&v,&len);
	perror("ACCEPT");

	read(nsfd,s,sizeof(s));

	close(1);

	fd=open("f1",O_RDWR);

	perror("FIFO:");

		system(s);
	
	printf("D::%s\n",s);
	
}
