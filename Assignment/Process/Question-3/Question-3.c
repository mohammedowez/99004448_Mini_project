#include<stdio.h>
#include<unistd.h>
int main(){
int n1 = fork();
int n2 = fork();

if(n1>0 && n2>0)
{
int k1 = execl("test1.exe","test1.exe", NULL);
if(k1<0)
{
perror("execl");
}
}else if(n1==0 && n2>0)
{
int k2 = execl("test2.exe", "test2.exe", NULL);
if(k2<0)
{
perror("ecexl");
}
}else if(n1>0 && n2==0)
{
int k3 = execl("test3.exe", "test3.exe", NULL );
if(k3<0)
{
perror("execl");
}
}else{
int k4 = execl("test4.exe", "test4.exe", NULL);
if(k4<0)
{
perror("execl");
}
}
return 0;
} 
