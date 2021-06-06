#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>

#define stack_size 10

sem_t s1;
sem_t s2;
int index_p=0;
int index_c=0;
int arr[stack_size];

void *producer(void *pn)
{
if(index_p<stack_size-1)
{
for(int i=0;i<stack_size;i++)
{
int num = rand();
sem_wait(&s1);
arr[index_p] = num;
index_p = (index_p+1)%stack_size;
printf("number %d inserted in stack\n",num);
sem_post(&s2);
}
}else{
printf("Stack is full\n");
}
}

void *consumer(void *pn)
{
if(index_c<stack_size-1)
{
for(int i=0;i<stack_size;i++)
{
sem_wait(&s2);
int num =0;
num = arr[index_c];
index_c = (index_c+1)%stack_size;
printf("Number %d removed\n",num);
sem_post(&s1);
}
}else{
printf("Stack  is empty\n");
}

}

int main(){
pthread_t p_arr[stack_size], c_arr[stack_size];
sem_init(&s1,0,stack_size);
sem_init(&s2,0,0);
int a[10] = {1,2,3,4,5,6,7,8,9,10};
for(int i=0;i<stack_size;i++)
{
pthread_create(&p_arr[i], NULL, (void *)producer,(void *)&a[i]);
}

for(int i=0;i<stack_size;i++)
{
pthread_create(&c_arr[i], NULL, (void *)consumer,(void *)&a[i]);
}

for(int i=0;i<stack_size;i++)
{
pthread_join(p_arr[i],NULL);
}

for(int i=0;i<stack_size;i++)
{
pthread_join(c_arr[i], NULL);
}
sem_destroy(&s1);
sem_destroy(&s2);
return 0;
}
