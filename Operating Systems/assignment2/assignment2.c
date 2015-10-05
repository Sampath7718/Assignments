#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


 
typedef struct {
   int * array;
   int  size, min, max;
   double avg;
} array_struct;


//function to determine max of array
void *max(void*nums)
{
	int i;
    array_struct *a = nums; 
	int size = a->size;
	//int * nums = a.array; 
	int m = a->array[0];
	for(i = 0; i < size; i++)
	{
		if(a->array[i] > m)
		m = a->array[i];
	}	
	a->max = m;
	pthread_exit(NULL);
}


//function to determine min of array
void *min(void*nums)
{
	int i;
    array_struct *a = nums; 
	int size = a->size;
	int m = a->array[0];
	for(i = 0; i < size; i++)
	{
		if(a->array[i] < m)
		m = a->array[i];
	}	
	
		a->min = m;
	pthread_exit(NULL);
}

//function to determine avg of array
void *avg(void*nums)
{

	int i, sum=0, temp;
    array_struct *a = nums; 
	int size = a->size;
	for(i = 0; i < size; i++)
	{
		temp =  a->array[i];
		sum += temp;
	}	
		a->avg = ((double)sum/size);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{	
	int size, i;
	array_struct a;
	size = argc-1;
	int *array = malloc(sizeof(int)*argc-1);
	
	if(argc<=1){
        printf("No argument!");
        return 1;
    }
	
	printf("\nYou entered %d numbers", size);
	for(i = 0; i < size; i++)
	{
		array[i] = (int)atof(argv[1+i]);
	}
	printf("\nThe array contains the numbers:");
	for(i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	a.array = array; 
	a.size = size;


pthread_t max_thread;
pthread_t min_thread;
pthread_t avg_thread;

//create thread for max(&x)
if(pthread_create(&max_thread, NULL, max, &a)){
fprintf(stderr, "Error creating thread\n");
return 1;
}

//create thread for min(&x)
if(pthread_create(&min_thread, NULL, min, (void*)&a)){
fprintf(stderr, "Error creating thread\n");
return 1;
}

//create thread for avg(&x)
if(pthread_create(&avg_thread, NULL, avg, (void*)&a)){
fprintf(stderr, "Error creating thread\n");
return 1;
}


//wait for max thread to finish
if(pthread_join(max_thread, NULL)) {

fprintf(stderr, "Error joining thread\n");
return 2;
}

//wait for min thread to finish
if(pthread_join(min_thread, NULL)) {

fprintf(stderr, "Error joining thread\n");
return 2;
}

//wait for avg thread to finish
if(pthread_join(avg_thread, NULL)) {

fprintf(stderr, "Error joining thread\n");
return 2;

}


//print results
printf("\nThe maximum value in the array is %d\n", a.max);
printf("The minimum value in the array is %d\n", a.min);
printf("The average value in the array is %f\n", a.avg);   


return 0;

}