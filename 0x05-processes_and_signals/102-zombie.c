#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - Function that creates an infinite loop
 * to make the program hang.
 * Return: always 0
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Main function that creates five zombie processes
 * Return: always 0
 */

int main(void)
{
	char cnt = 0;
	pid_t zombie;

	while (cnt < 5)
	{
		zombie = fork();
		if (zombie > 0)
		{
			printf("Zombie process created, PID: %d\n", zombie);
			sleep(1);
			cnt++;
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
