#include"header.h"
main(){
int ret;
fd_set v;
struct timeval t;
char s[20];
printf("Enter data..\n");
FD_ZERO(&v);
FD_SET(0,&v);
t.tv_sec=10;
t.tv_usec=0;
printf("Before.\n");
ret=select(1,&v,0,0,&t);
if(ret<0){
perror("sel");
return;
}
else if(ret==0){
printf("time out\n");
return;
}
else{
scanf("%s",s);
printf("%s\n",s);
}

}
