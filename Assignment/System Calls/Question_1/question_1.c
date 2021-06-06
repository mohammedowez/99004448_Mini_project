#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define size_buffer 100000
int main(){
char buffer[size_buffer];
int read_no;
int fd_first = open("1.txt",O_RDONLY);
int fd_second = open("2.txt",O_WRONLY|O_CREAT);
if(fd_first<0)
{
perror("First file could not open");
printf("1 error");
}else if(fd_second<0)
{
perror("Second file could not open");
printf("error 2");
}
else{
while(read_no = read(fd_first, &buffer, 10)>0)
{
 write(fd_second, &buffer, read_no);
	printf("Copying content\n");
}
close(fd_first);
close(fd_second);
printf("file coppied\n");
}
}
