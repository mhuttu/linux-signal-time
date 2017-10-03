#include <stdio.h> // perror, printf
#include <sys/types.h> // pid_t
#include <unistd.h> // sleep
// use the extended signal handler instead of void (*X)(int)
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void printTime()
{
    time_t t=0;
    t = time(NULL);
    printf("Time in seconds since 1.1.1970 is %ld", t);
}

void myH(int signum) {
    char ret[2];
    printf("SIG: signal number %d\n", signum);
    scanf("Do you want to continue (y/n)? %c", &ret);
    if (ret[0] =='n')
        exit(EXIT_SUCCESS);
    }


int main(int argc, char** argv)
{

struct sigaction sa;
int waittime=2;

printf("pid = %d\n", getpid());
printf("Check 0");

// prepare the parameter for sigaction
// the pointer to the handler routine


if (argc == 1)
{

    sscanf(argv[1], "%d", &waittime);

}

sa.sa_handler = myH;
// don't block additional signals while handling this one
sigemptyset(&sa.sa_mask);
// set single action and extended signal handler
sa.sa_flags = 0; // SA_ONESHOT | SA_SIGINFO;

printf("Check 1");
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Problem installing SIGINT-handler");
        exit(EXIT_FAILURE);}

printf("Check 2");

        while(1)
        {
        printf("Sleeping for %d seconds\n", waittime);
        printTime();
        sleep(waittime);
        }

printf("Done sleeping, ending operation\n");

return 0;
}

