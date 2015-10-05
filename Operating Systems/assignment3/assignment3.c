#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 //struct to hold global info
typedef struct {
	int count;
	pthread_mutex_t mutex; 
	int num_iterations;
} global_circle;


//thread function to generate a random coordinate and update count if it is in the circle
void *coord_gen(void* c)
{
	global_circle* circle = c;
	int x, y, i;
  

    
    for(i =0; i <= circle->num_iterations; ++i){
    x = rand() % 20001+ (-10000);
    y = rand() % 20001+ (-10000);

    //if (x,y) is in the cirlce
    //*Note: I couldn't find the best precision to use for the number of possible points in the circle, but after some experimenting, this is pretty close
    if(((a*a) + (b*b)) <= 1){
    	//increment global count, protected per thread by mutex
    	//there is actually no need for a mutex here because each thread can have its own count and avoid the race condition entirely
    	circle->count ++; 

    }
}

	pthread_exit(NULL);
}

int main(int argc, char **argv)
{	
	 srand(time(NULL));
	
	if(argc < 3){
        printf("improper argument! Refer to the ReadMe.");
        return 1;
    }

    int i, num_threads, num_iterations;
    float pi_estimation; 
	num_threads = atoi(argv[1]);
	num_iterations = atoi(argv[2]);
	global_circle circle[num_threads];

	pthread_t threads[num_threads]; 
	

	for(i = 0; i < num_threads; ++i){
		circle[i].count = 0; 
		circle[i].num_iterations = num_iterations;
	}

	for(i = 0; i < num_threads; ++i){

	//create threads
	if(pthread_create(&threads[i], NULL, coord_gen, &circle[i])){
		fprintf(stderr, "Error creating thread\n");
		return 1;
		}
}


	for(i = 0; i < num_threads; ++i){

		//wait for threads to finish
		if(pthread_join(threads[i], NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;
		}
}


//get sum of points on circle
for(i = 0; i < num_threads; ++i){
	pi_estimation += circle[i].count; 
	}
//calculate pi estimation
pi_estimation = 4 * (pi_estimation)/(num_iterations*num_threads);
printf("estimation of pi is %f\n", pi_estimation);
  
return 0;

}