#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 *	*WHAT IS A MUTEX IN C? (PTHREAD_MUTEX)*
 *
 *	This program shows how by using a mutex (kind of a lock),
 *	we can safely modify variable values without having issues
 *	with race conditions.
*/

int	mails = 0;
pthread_mutex_t	mutex;

void*	routine()
{
	for(int i = 0; i < 1000000; i++)
	{
		//	We check if the lock is 1 (locked) and if so, it waits
		//	until it is 0 (unlocked).
		//	It also sets the lock to 1 (locks it).
		pthread_mutex_lock(&mutex);
		mails++;
		//	Then, we set the lock to 0 (unlock it).
		pthread_mutex_unlock(&mutex);
	}
}

int	main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL); //Start mutex
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);	
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	pthread_mutex_destroy(&mutex); //End mutex
	printf("Number of emails: %d\n", mails);
	return (0);
}
