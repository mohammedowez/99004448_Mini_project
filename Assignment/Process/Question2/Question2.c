#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
int k = execl("test.exe","test.exe", NULL);
if(k<0)
{
perror("execv");
exit(1);
}
return 0;
}
