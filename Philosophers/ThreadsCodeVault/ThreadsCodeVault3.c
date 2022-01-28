#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * 	*WHAT ARE RACE CONDITIONS?*
 *	
 *	This program shows how two parallel threads end up wrongly
 *	modifying a global variable due to Race Conditions
 *
 *	Expected value: 2000000
 *	Real value: less than 2000000
*/

int	mails = 0;

void*	routine()
{
	for(int i = 0; i < 1000000; i++)
		mails++;
	//	read mails
	//	increment
	//	write mails
}

int	main()
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);	
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	printf("Number of emails: %d\n", mails);
	return (0);
}
