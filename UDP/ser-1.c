#include"header.h"
main(int argc,char**argv){
	int len,sfd,i;
	struct sockaddr_in v;
	char s[1000];
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0){
		perror("SOCKET");
		return;
	}
	perror("SOCKET");
	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len=sizeof(v);
	bind(sfd,(struct sockaddr*)&v,len);
	perror("BIND");
	recvfrom(sfd,s,sizeof(s),0,(struct sockaddr*)&v,&len);
	printf("%s\n",s);
	for(i=0;s[i];i++)
		if(s[i]>='a'&&s[i]<='z')
			s[i]^=32;
	sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&v,len);
}

