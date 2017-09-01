#include"header.h"
main(int argv,char**argc){
int fd;
fd=open("f1",O_WRONLY);
write(fd,argc[1],strlen(argc[1])+1);
return;
}
