#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

void* time_count(void* pv){
	int i=0;
	time_t Time;
	Time = time(NULL);
	struct time* time_current;
	printf("%02d : %02d : %02d \n",time_current->tm_hour, time_current->tm_min, time_current->tm_sec);	
}

int main(){
	int i, k=4;
    pthread_t arr[k];
     for(i=0; i<k; ++i)
    {
        pthread_create(&arr[i], NULL, time_count, (void *)(__intptr_t)i);
        sleep(1);
    }
    
    for(i=0; i<k; i++)
    {
        pthread_join(arr[i], NULL);
    }
    return 0;
}
