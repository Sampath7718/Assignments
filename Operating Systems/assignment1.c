#include <stdio.h>
#include <stdlib.h>
int main(){

	int start_num, pid, status;
	printf("\nInput an integer ");
    scanf("%d", &start_num);
	printf("\nStart number is: %d\n", start_num);
	if(start_num < 0){
		printf("Rerun program with argument above or equal to 0\n");
		exit(0);
	}

	pid = fork();

	if(pid < 0){
		printf("fork unsuccessful. Exiting now.\n");
		exit(0);
	}

	else if(pid == 0)
	{
		do{
			if(start_num%2 ==0){
				start_num = start_num/2;
			}

			else if(start_num%2 != 0){
				start_num = ((start_num*3)+1);
			}

		printf("%d\n", start_num);
		}
		while(start_num!=1);


	}

	else{
	
		wait(&status);
		}

	return 0;
}