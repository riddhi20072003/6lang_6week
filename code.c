#include <stdio.h>
#include <stdlib.h>     
#include <unistd.h>  
#include <pthread.h> //included for threading

int i = 0, j;
clock_t t;  //clock for time

void *myThreadFun(void *vargp)
{
    
    while(i>=0){
        t=clock()-t;
        printf("%d 	",i);
        double time_taken = ((double)t)/CLOCKS_PER_SEC; //calculation of time
        if (time_taken>=1){
            break;}
        i=i+1;
    }


    return NULL;
}
    
int main()   //main function
{

	t = clock();
	int NUM_THREAD = 4;  //multiple threading 

	pthread_t thread_id[NUM_THREAD];

	for (j = 0; j < NUM_THREAD; j++) {
	    pthread_create(&thread_id[j], NULL, myThreadFun, NULL);
	    pthread_join(thread_id[j], NULL);

	}

	exit(0);
}
