#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 10 // Total Number of Threads

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; // Setting Up MUTEX

struct thread_info{
	int thread_num;
};

void *Bridge(void *arg){ // Read File Function
   struct thread_info *tinfo = arg; // Extracting Parameters
   printf("%d \n", tinfo -> thread_num);
   
   pthread_exit(0); // Exit Thread.
}


int main(){
	pthread_t North[THREADS];
	pthread_t South[THREADS];
	pthread_mutex_init(&mutex1,NULL); // Initializing Mutex

	for(int i = 0; i < THREADS; i++){ // Joining of The Threads
    	int CreateFirst =  pthread_create(&North[i], NULL, Bridge, &i); // Thread For North
    	int CreateSecond = pthread_create(&South[i], NULL, Bridge, &i); // Thread For South
   		if(CreateFirst != 0 || CreateSecond != 0){ // In Case Thread Create Fails
      		fprintf(stderr, "Thread Create Failed");
      		return 1;
   		}
   	}

   	for(int i = 0; i < THREADS; i++){ // Joining of The Threads
      	int JoinFirst = pthread_join(North[i],NULL); // Joining North
    	int JoinSecond = pthread_join(South[i],NULL); // Joining South
     	 if(JoinFirst != 0 || JoinSecond != 0){ // In Case Thread Join Fails
        	fprintf(stderr, "Join Failed");
        	return 1;
      	}
   	}
   	pthread_mutex_destroy(&mutex1); // Destroying Mutex
}