#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void main(void){
	pid_t pid[6];
	int i;

	pid[0] = fork();

	if (pid[0] == 0){
		pid[1] = fork();
		if (pid[1] == 0){
			pid[3] = fork();
			if (pid[3] == 0){
				printf("I'm forth proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
				exit(EXIT_SUCCESS);
			} 
			printf("I'm second proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
			wait();
			exit(EXIT_SUCCESS);

		} else{
			pid[2] = fork();
			if (pid[2] == 0){
				pid[4] = fork();
				if (pid[4] == 0){
					printf("I'm fifth proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
					exit(EXIT_SUCCESS);
				} else{
					pid[5] = fork();
					if (pid[5] == 0){
						printf("I'm sixth proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
						exit(EXIT_SUCCESS);
					}
					printf("I'm third proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
					wait();
					exit(EXIT_SUCCESS);
				}
			}
			printf("I'm first proc my pid is %ld, ppid is %ld\n", (long)getpid(), (long)getppid());
			wait();
			exit(EXIT_SUCCESS);
		}
	} else{
		printf("I'm parent proc my pid is %ld\n", (long)getpid());
	}

	wait();
	exit(EXIT_SUCCESS);
}
