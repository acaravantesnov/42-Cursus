#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

/*
 * 	*GET RETURN VALUE FORM A THREAD (PTHREAD_JOIN)*
 *
 *	This program shows how to resturn a value from a thread
 *	using the second parameter of pthread_join
*/

void*	roll_dice()
{
	int	value = (rand() % 6) + 1; //Generates random number between 1 and 6
	int* result = malloc(sizeof(int)); //Allocates dynamic memoryfor that value.
	*result = value;
	return	(void*) result; //Returns the casted int* to void*
}

int	main()
{
	int	*res;
	srand(time(NULL));
	pthread_t	th;
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(th, (void**) &res) != 0)
		return (2);
	printf("Result: %d", *res);
	free(res);
	return (0);
}
