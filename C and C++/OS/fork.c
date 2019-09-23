#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
    printf("I am: %d\n",(int)getpid());
    pid_t pid = fork();
    printf("Returned fork: %d\n",(int)pid);
    if (pid<0)
    {
        printf("Failed\n");
    }
    else if (pid == 0)
    {
        printf("I am child with id: %d\n",(int)getpid());
        sleep(5);
        printf("Child Exiting\n");
    }
    else
    {
        printf("I am parent with pid: %d\n",(int)getppid());
        wait();
        printf("Parent Exiting\n");
    }
    
    
    
}