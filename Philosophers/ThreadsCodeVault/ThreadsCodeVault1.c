#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //Compile with flag -pthread

/*
 *	*SHORT INTRO TO THREADS (PTHREADS)*
 *
 *	This program shows how 2 threads actually execute in
 *	parrallel.
*/

void*	routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
}

int	main()
{
	pthread_t	t1, t2;	//Thread variables
	pthread_create(&t1, NULL, &routine, NULL); //(thread var, atributes, function, function args)
	pthread_create(&t2, NULL, &routine, NULL); //(thread var, atributes, function, function args)
	pthread_join(t1, NULL); //Similar to waitpid
	pthread_join(t2, NULL); //Similar to waitpid
	return (0);
}

/*
 *	Note that we should create both threads as:
 *	
 *	if (pthread_create(&t, NULL, &funct, NULL) != 0)
 *		return (1);
 *
 *	And wait for both threads as:
 *	
 *	if (pthread_join(t, NULL) != 0)
 *		return (1);
*/
