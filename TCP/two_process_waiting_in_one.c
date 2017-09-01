#include"header.h"
main(){
int ret,fd;
fd_set v;
struct timeval t;
char s[20];
fd=open("f1",O_RDWR);
while(1){
FD_ZERO(&v);
FD_SET(0,&v);
FD_SET(fd,&v);
t.tv_sec=10;
t.tv_usec=0;
ret = select(9,&v,0,0,&t);
if(ret==0){
printf("Time out..\n");
return;
}
else if(ret<0){
perror("select");
return;
}
else if(FD_ISSET(0,&v)){
scanf("%s",s);
printf("%s\n",s);
FD_CLR(0,&v);
}
else if(FD_ISSET(fd,&v)){
read(fd,s,sizeof(s));
printf("Fifo:%s\n",s);
FD_CLR(fd,&v);
}
}
}
