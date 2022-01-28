#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*
 * 	*HOW TO PASS ARGUMENTS TO THREADS IN C*
 *
 *	This program shows how we can pass an argument to a thread
 *	using the last argument of pthread_create.
 *	We need to dynamically allocate memory for that argument in
 *	order to pass it correctly to threads as an argument.
 *	We then free that argument memory allocation inside each
 *	thread.
 *
*/

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void*	routine(void* arg)
{
	int index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int	main()
{
	pthread_t th[10];
	for (int i = 0; i < 10; i++)
	{
		int* a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
	}
	for (int j = 0; j < 10; j++)
	{
		if (pthread_join(th[j], NULL) != 0)
			perror("Failed to create thread");
	}
	return (0);
}
