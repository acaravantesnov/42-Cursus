#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 *	*WHAT ARE DETACHED THREADS?*
 *
 *	Detached threads are use in long time running processes.
 *	It would "substitute" the pthread_join fctn and a
 *	pthread_exit function at the end instead of return(0)
 *	is necessary.
 *
*/

#define THREAD_NUM 2

void*	routine(void* arg)
{
	sleep(1);
	printf("Finished execution\n");
}

int	main()
{
	pthread_t	th[THREAD_NUM];
	
	for (int i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
		pthread_detach(th[i]);
	}
	//for (int j = 0; j < THREAD_NUM; j++)
	//{
	//	if (pthread_join(th[j], NULL) != 0)
	//		perror("Failed to join thread");
	//}
	pthread_exit(0);
}
