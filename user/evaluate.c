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

    //Create the specified number of children
    for(int i = 0; i < CHILDREN; ++i)
        if (fork() == 0) { myNum = i; break; }

    //Do some work, different per process (just to have something to do)
    int fib_i = 0, fib_i1 = 1, temp;
    for(int i = 0; i < myNum*myNum; i++)
    {
        temp = fib_i;
        fib_i = fib_i + fib_i1;
        fib_i1 = temp;
    }

    //TODO: Evaluate your metrics here, after the processes have completed their work
    
    printf("Hello \n");

}
