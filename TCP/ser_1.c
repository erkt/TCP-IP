#include"header.h"
main(){
	int sfd,len,nsfd,i;
	char s[100];
	struct sockaddr_in  v,v1;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0){
		perror("SOCKET");
		return;
	}
	perror("SOCKET");
	v.sin_family=AF_INET;
	v.sin_port=htons(9876);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");
	len = sizeof(v);
	bind(sfd,(struct sockaddr*)&v,len);
	perror("bind");
	listen(sfd,5);
	perror("LISTEN");
	nsfd=accept(sfd,(struct sockaddr*)&v1,&len);
	perror("ACCEPT");
	read(nsfd,s,sizeof(s));
	for(i=0;s[i];i++)
		if(s[i]>='a'&&s[i]<='z')
			s[i]=s[i]-32;
	write(nsfd,s,strlen(s)+1);
	printf("%s\n",s);
}
