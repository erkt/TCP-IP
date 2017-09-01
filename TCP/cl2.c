#include"header.h"
main(int argc, char **argv)
{
	int sfd,len;
	char s[100],s1[100];
	struct sockaddr_in v;
	
	sfd=socket(AF_INET,SOCK_STREAM,0);
	perror("SOCKET");
	
	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr(argv[2]);
	len=sizeof(v);

	connect(sfd,(struct sockaddr *)&v,len);
	perror("CONNECT");
			printf("Enter");
	while(1){
		if(fork()){	
			read(sfd,s1,sizeof(s1));
			printf("DATA: %s\n",s1);
		}
		else{
			scanf("%s",s);
			write(sfd,s,strlen(s)+1);
		}
	}
}
