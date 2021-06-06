#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
  
int arr[20] = {1,5,7,10,12,14,15,18,20,22,25,26,27,24,37,54,43,76,58,37};
int max[5]={0,0,0,0,0};
int min[5] = {0,0,0,0,0};
int th_number = 0;

void minmax(void* arg)
{
	int num = th_number++;
	int maxs = 0
	int mini = 0;
	
	for(int i = num*5;i<(num+1)*5;i++)
	{
		if(arr[i]>maxs)
		{
			maxs = arr[i];
		}
		if(arr[i]<mini)
		{
			mini = arr[i];
		}
		max[num]  = maxs;
		min[num] = mini;
	}
}

int main(){
	int maxs = 0;
	int mini = 0;
	 pthread_t threads[5];
	
	for(int i=0;i<5;i++)
	{
		pthread_create(&threads[i],NULL,minmax,(void*)NULL);
	}
	
	for (k=0;k<Tmax;k++)
        pthread_join(threads[k],NULL);
        
     for (k=0;k<5;k++)
    {
        if (max[k]>maxs)
            maxsm=max[k];
        if (min[k]<mini)
            mini=min[k];
    }
    printf("max number is %d ",maxs);
    printf("min number is %d ",mini);
    
    return 0;
}
