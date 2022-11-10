#include <stdio.h>   // For printf
#include <unistd.h>  // For sleep
#include <pthread.h> // For pthread

// Compile with : gcc -pthread -o threads threads.c
// Run with	: ./threads

// Very simple example with a pthread and a mutex
// Using a global counter, use the main process and a thread to iterate the same variable
// One function iterates if the value is odd
// The other function iterates if the value is even

// Our global counter
int shared_counter = 0;

// Locking mechanism
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Iterating mechanism that main() and BlueTask() will share
void iterator(int even_or_odd, char* function) {
	while(shared_counter < 20) {
		pthread_mutex_lock(&mutex);
                if(shared_counter % 2 == even_or_odd) {
                        printf("In %s, shared_counter (pre-iteration) = %d\n", function, shared_counter);
                        ++shared_counter;
                }
		pthread_mutex_unlock(&mutex);
        }
}

void BlueTask(void) {
	iterator(1, "BlueTask");

	// Had previous errors where the below message was displayed
	// *** stack smashing detected ***: ./threads terminated
	// Aborted (core dumped)
	// This call seemed to fix the issue
	pthread_exit(NULL);

	printf("In BlueTask, called pthread_exit(), returning\n");

	// Not sure why this is recommended?
	// Final counter value will be 21 instead of 20
	// return NULL;
}

int main(void) {
	// Variables
	pthread_t blue;
	int exit_status;

	// Create thread
	// Need to catch the exit status of the call to pthread_create()
	// Will return zero on success, one on failure
	exit_status = pthread_create(&blue, NULL, BlueTask, NULL);

	// Check exit status
	if(exit_status) {
		printf("In main, Error creating Blue Thread\n");
		return 1;
	}

	/*
	if(pthread_create(&blue, NULL, BlueTask, NULL)) {
		printf("In main, Error creating Blue Thread\n");
		return 1;
	}
	*/

	iterator(0, "main");

	// Need some kind of a waiting mechanism or else program will terminate before the Blue Thread can complete it's task.
	sleep(4);

	printf("In main, returned from sleep, returning\n");
	// Exit
	return 0;
}
