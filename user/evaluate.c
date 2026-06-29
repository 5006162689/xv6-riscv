#include "kernel/types.h" //Has typedefs for common types in xv6
#include "user/user.h"

#define bool char
#define true 1
#define false 0

const int CHILDREN = 5;

int main(void)
{
    //int forkpid; 
    int myNum = CHILDREN + 1;
    int pids[CHILDREN];
    int start = uptime();
    //Create the specified number of children
    for(int i = 0; i < CHILDREN; ++i) {
        int pid = fork();
        if (pid == 0) {myNum = i; break; }
        pids[i] = pid;
    }

    //Do some work, different per process (just to have something to do)
    int fib_i = 0, fib_i1 = 1, temp;
    for(int i = 0; i < myNum*myNum; i++)
    {
        temp = fib_i;
        fib_i = fib_i + fib_i1;
        fib_i1 = temp;
    }

    //TODO: Evaluate your metrics here, after the processes have completed their work

    // if my num = 1 { do bubble sort  }
    if (myNum == 1) {
        rude(5);

        exit(uptime() - start);
    }
    if (myNum == 2) {
        rude(1);
        exit(uptime() - start);
    }
    if (myNum == 3) {
        rude(1);
        exit(uptime() - start);
    }
    if (myNum == 4) {
        rude (2);
        exit(uptime() - start);
    }
    if (myNum == 5) {
        rude(1000000);
        exit(uptime() - start);
    }

    int turnarounds[CHILDREN];
    for (int i = 0; i < CHILDREN; i++) {
        int status;
        int pid = wait(&status);
        for (int j = 0; j < CHILDREN; j++) {
            if (pids[j] == pid) {
                turnarounds[j] = status; 
                break;
            }
        }
    }
    printf("CHILD 1: %d ticks\n", turnarounds[0]);
    printf("CHILD 2: %d ticks\n", turnarounds[1]);
    printf("CHILD 3: %d ticks\n", turnarounds[2]);
    printf("CHILD 4: %d ticks\n", turnarounds[3]);
    printf("CHILD 5: %d ticks\n", turnarounds[4]);
    exit(0);
    // calc execution time
    // parent prints average execution time.
    

}