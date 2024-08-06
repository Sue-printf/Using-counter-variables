// Description of the Program

/*The given C code presents a straightforward multi-threaded program that lets mutexes (an internal locking mechanism of an operating system) synchronize access to a shared resource that in this case is a counter variable. The program makes use of two scripts, namely thread1 and thread2, each one of which increases the value stored in a shared counter variable. The mutex operation is used to protect the counter from the multiple thread access by allowing only one thread to modify the counter at a time and implying a race conditions prevention. Also, mutex1 should be used. Interestingly, the conditional statement in thread1 changes the counter by plus 100 while mutex2 protects the operation. The program makes the previous feature possible by storing the information on how many times thread1 gets the bonus increment (100) through a separate variable called bonusCount.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_COUNT 2000000

int counter = 0;
int bonusCount = 0;
pthread_mutex_t mutex;

void *thread1_func(void *arg) {
    // Entry section
    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex); // Critical section entry
        if (counter % 100 == 0) {
            counter += 100;
            bonusCount++; // Increment bonus count
        } else {
            counter++;
        }
        pthread_mutex_unlock(&mutex); // Critical section exit
    }
    return NULL;
}

void *thread2_func(void *arg) {
    // Entry section
    for (int i = 0; i < MAX_COUNT; i++) {
        pthread_mutex_lock(&mutex); // Critical section entry
        counter++;
        pthread_mutex_unlock(&mutex); // Critical section exit
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Remainder section
    printf("Final counter value: %d\n", counter);
    printf("Thread1 bonus count: %d\n", bonusCount);
    printf("Thread2 did %d updates, counter = %d\n", MAX_COUNT, counter);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
