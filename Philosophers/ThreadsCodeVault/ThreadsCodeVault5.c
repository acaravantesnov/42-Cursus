#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 *	*HOW TO CREATE THREADS IN A LOOP (PTHREAD_CREATE)*
 *
 *	This program shows how we can instanciate an array of
 *	threads and use 2 for loops in order to create, and
 *	wait for each thread.
 *
 *	IMPORTANT: Do not create and wait for each process in the
 *	same for loop as it will not run the threads in parallel.
*/

int	mails = 0;
pthread_mutex_t	mutex;

void*	routine()
{
	for(int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main()
{
	pthread_t th[4]; //Array of threads
	pthread_mutex_init(&mutex, NULL); //Start mutex
	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
		{
			perror("Failed to create thread.");
			return (1);
		}
		printf("Thread %d has started\n", i);
	}
	for (int j = 0; j < 4; j++)
	{
		if (pthread_join(th[j], NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", j);
	}
	pthread_mutex_destroy(&mutex); //End mutex
	printf("Number of emails: %d\n", mails);
	return (0);
}
