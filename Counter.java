// Description of the Program
/*
The following Java code is a sample of a multi-threaded program that uses a ReentrantLock to synchronize the use of a bounded resource, like for example a counter variable. The program uses two threads, thread1 and thread2, that add to the modifiable shared counter variable. The counter is guarded by a ReentrantLock to make only a single thread change its value at a time and thus eliminate the race conditions. Moreover, although thread1 typically updates the counter by 1, it occasionally increments it by 100 which is ensured by the respective lock. In addition, the program maintains that how frequently thread1 is titled the bonus increment is counted by incrementing the separate bonusCount variable.
*/

public class Counter {
    private static int value = 0;
    private static final java.util.concurrent.locks.ReentrantLock mutex = new java.util.concurrent.locks.ReentrantLock();
    private static int bonusCount = 0;

    public static void main(String[] args) throws InterruptedException {
    // Entry section
    Thread thread1 = new Thread(() -> {
        for (int i = 0; i < 2000000; i++) {
            mutex.lock(); // Critical section entry
            try {
                if (value % 100 == 0) {
                    value += 100;
                    bonusCount++; // Increment bonus count
                } else {
                    value++;
                }
            } finally {
                mutex.unlock(); // Critical section exit
            }
        }
    });

    Thread thread2 = new Thread(() -> {
        for (int i = 0; i < 2000000; i++) {
            mutex.lock(); // Critical section entry
            try {
                value++;
            } finally {
                mutex.unlock(); // Critical section exit
            }
        }
    });

    thread1.start();
    thread2.start();

    thread1.join(); // Wait for Thread1 to finish
    thread2.join(); // Wait for Thread2 to finish

    // Remainder section
    System.out.printf("Final counter value: %d\n", value);
    System.out.printf("Thread1 bonus count: %d\n", bonusCount);
    System.out.printf("Thread2 did %d updates, counter = %d\n", 2000000, value);
}

}
