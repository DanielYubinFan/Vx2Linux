#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

/* Simple error handling functions */
#define handle_error_en(en, msg) \
		do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void * sig_thread(void *arg)
{
	sigset_t *set = (sigset_t *) arg;
    int s, sig;

    //for (;;) {
    	s = sigwait(set, &sig);
    	if (s != 0)
    		handle_error_en(s, "sigwait");
    	printf("Signal handling thread got signal %d\n", sig);

    int i = 0;
    for (; i < 100; i++)
    	;
    printf("i is %d\n", i);
    return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread;
	sigset_t set;
	int s;

	/*
	Block SIGINT; other threads created by main() will inherit
	a copy of the signal mask.
	 */
	sigemptyset(&set);
	sigaddset(&set, SIGQUIT);
    s = pthread_sigmask(SIG_BLOCK, &set, NULL);
    if (s != 0)
    	handle_error_en(s, "pthread_sigmask");
    s = pthread_create(&thread, NULL, &sig_thread, (void *) &set);
    if (s != 0)
    	handle_error_en(s, "pthread_create");
    /*
	Main thread carries on to create other threads and/or do other work
    */
    pause();
//    sleep(2); /* Dummy pause so we can test program */
//    printf("main func exit\n");
//    return 0;
    }
