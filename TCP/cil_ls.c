#include"header.h"
main(int argc,char**argv){
	int len,sfd,fd,i;
	struct sockaddr_in v;
	char s[100],s1[1000];
	if((sfd= socket(AF_INET,SOCK_STREAM,0))<0){
		perror("SOCKET");
		return;
	}
	perror("SOCKET");
 
	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr(argv[2]);
	len =sizeof(v);

	connect(sfd,(struct sockaddr*)&v,len);
	perror("Connect");

//	printf("Enter:");
//	scanf("%s",s);
	write(sfd,argv[3],strlen(argv[3])+1);

	fd=open("f1",O_RDONLY);
	bzero(s1,1000);
	read(fd,s1,sizeof(s1));
	len=strlen(s1);
	for(i=0;i<len;i++)
		printf("%c",s1[i]);
}

