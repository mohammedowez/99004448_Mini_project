#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
char str[10];
while(1){
scanf("%s",str);
char location[] = "/usr/bin/";
strcat(location,str);
int l = execl(location,str,NULL);
if(l<0)
{
perror("exexl");
exit(1);
}
}
return 0;
}
