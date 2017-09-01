#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<netinet/ip.h>
struct st{
	int op[10];
}v2;
main(int argc,char**argv){
	int len,sfd,nsfd,i,j;
	struct sockaddr_in v,v1;
	sfd=socket(AF_INET,SOCK_STREAM,0);
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
	perror("BIND:");
	listen(sfd,5);
	perror("listen");
	nsfd=accept(sfd,(struct sockaddr*)&v1,&len);
	perror("ACCEPT");
	read(nsfd,&v2,sizeof(v2));




	for(i=0;i<10-1;i++)
		for(j=0;j<10-i-1;j++){
			if(v2.op[j]>v2.op[j+1]){
				v2.op[j+1]=v2.op[j]+v2.op[j+1]-(v2.op[j]=v2.op[j+1]);
			}
		}
	for(i=0;i<10;i++)
		printf("%d  ",v2.op[i]);
}
