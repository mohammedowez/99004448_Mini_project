#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define size_buffer 10000
int  main(){
int lines, words, characters;
char buffer[size_buffer];
int fd = open("1.txt",O_RDONLY);
characters = read(fd, &buffer, size_buffer);
printf("Character count = %d\n", characters);
for(int i=0;i<characters;i++)
{
if(buffer[i]=='\n')
{
lines++;
words++;
}
else if(buffer[i]==' ')
{
words++;
}
}
printf("Lines count = %d\n", lines);
printf("words count = %d\n",words);
return 0;
}
