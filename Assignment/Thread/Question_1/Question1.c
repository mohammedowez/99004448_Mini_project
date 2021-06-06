#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX 100;

int arr[100] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
int sum[10] ={0,0,0,0,0,0,0,0,0,0}; 
int part = 0;
void* sum(void* arg){
	int thread_part = part++;
	for(int i=thread_part*(MAX/10);i<(thread_part+1)*(MAX/10;i++))
	{
		sum[thread_part]+=a[i];
	}
}

int main(){
	pthread_t thread[10];
	for(int i=0;i<10;i++)
	{
		pthread_creat(&thread[i],NULL,sum,(void*)NULL);
	}
	
	for(int i=0;i<10;i++)
	{
		pthread_join(thread[i], NULL);
	}
	int final_sum = 0;
	for(int i=0;i<10;i++)
	{
		final_sum = final_sum+sum[i];
	}
	printf("sum is: %d:, final_sum);
	return 0;
}
