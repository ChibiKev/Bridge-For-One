#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define THREADS 10 // Total Number of Threads

void Bridge(char arr[], int value);

int NorthValue = 0; // Global Variable For North Number 
int SouthValue = 0; // Global Variable For South Number
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; // Setting Up MUTEX

void *NorthFarmer(void* arg){ // North Farmer Thread
	pthread_mutex_lock(&mutex1); // Critical Section
	char arr[5] = "North"; // North
	printf("%s Tunbridge #%d farmer can cross the bridge\n", arr, NorthValue);
	Bridge(arr,NorthValue); // Enters Bridge
	printf("%s Tunbridge #%d farmer has left the bridge\n", arr, NorthValue);
	NorthValue++; // Increase North Number
	pthread_mutex_unlock(&mutex1); // End of Critical Section
	pthread_exit(0); // Exit Thread.
}

void *SouthFarmer(void* arg){
	pthread_mutex_lock(&mutex1); // Critical Section
	char arr[5] = "South"; // South
	printf("%s Tunbridge #%d farmer can cross the bridge\n", arr, SouthValue);
	Bridge(arr,SouthValue); // Enters Bridge
	printf("%s Tunbridge #%d farmer has left the bridge\n", arr, SouthValue);
	SouthValue++; // Increase South Number
	pthread_mutex_unlock(&mutex1); // End of Critical Section
	pthread_exit(0); // Exit Thread.
}

void Bridge(char arr[], int value){ // Read File Function
	srand(time(NULL)); // Different Seed For Random Number Generator
   	printf("%s Tunbridge #%d is traveling on the bridge...\n", arr, value);
   	int randomnumber = rand() % 4; // Gets Random Number From 0 to 3
   	sleep(randomnumber); // Sleep For up to 3 Seconds
   	//printf("Random %d \n", randomnumber);
}


int main(){
	pthread_t North[THREADS]; // North Thread
	pthread_t South[THREADS]; // South Thread
	pthread_mutex_init(&mutex1,NULL); // Initializing Mutex

	for(int i = 0; i < THREADS; i++){ // Joining of The Threads
    	int CreateFirst =  pthread_create(&North[i], NULL, NorthFarmer, NULL); // Thread For North
    	int CreateSecond = pthread_create(&South[i], NULL, SouthFarmer, NULL); // Thread For South
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
   	return 0;
}