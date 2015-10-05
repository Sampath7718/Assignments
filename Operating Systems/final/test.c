#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUMBER_OF_WORDS 300000
#define _FILE_OFFSET_BITS 64


FILE *file;

 //struct to hold global info
typedef struct {
	int size, lines_per_thread, current_location; 
	char *words[300000];
	int *count; 
	pthread_mutex_t mutex; 
} word_counter;


//thread function to go through a portion of the text file and store the words in the word counter
void *count_words(void* c)
{
 
	word_counter* counter = c;  
		
	int count, i,j, found; 
	char * word_tokens;
	char ** words;
	char * word; 
	const char delim[] = " \n\r\t/1234567890[]@!?()#$%^&*-+:,.-_="; 
    //char* str = (char*)malloc(1000 * sizeof(char));//for copy of buf
	//char ** buf;
	char* buf = (char*)malloc(1000 * sizeof(char));//give line max size of 1000 chars
	//get one line at a time and count words
	pthread_mutex_lock(&counter->mutex);
	 //counter->count[0] = 0;
	for(i = 0; i < counter->lines_per_thread; ++i){ 
	fgets(buf, 1000, file);
	word_tokens = strtok(buf, delim); 
	//word_tokens = strsep(&buf, delim);
	 
	while(word_tokens !=NULL){
		found = 1; 
    //printf("%s\n", word_tokens);
		for(j = 0; word_tokens[j]; j++){
			word_tokens[j] = tolower(word_tokens[j]);
		} 
		
		//printf("%s", word_tokens); 
		for(j = 0; j < counter->current_location; ++j){
		
			if(word_tokens && counter->words[j] && counter->words[j] == word_tokens){
			puts("match"); 
			printf("%s = %s\n", counter->words[j], word_tokens); 
			counter->count[j] ++; 
			j = MAX_NUMBER_OF_WORDS; 
			found = 0; 
			}
		}
		char * tmp = word_tokens;
		if(found!=0){
				//puts("here"); 
				counter->words[counter->current_location] = word_tokens; 
				counter->count[counter->current_location]++; 
				counter->current_location ++;
				
				//printf("%s\n", counter->words[counter->current_location -1]);  
		}
		//printf("%s\n", word_tokens); 
		word_tokens = strtok (NULL, delim);
		//word_tokens = strsep(&buf, delim); 
	}
	
	
	
	//puts(buf); 

    } pthread_mutex_unlock(&counter->mutex);

   		return 0;
	pthread_exit(NULL);
}



int main(int argc, char **argv)
{	
	
	int size, j; 
	if(argc < 1){
        printf("improper argument! Refer to the ReadMe.");
        return 1;
    }
    int i, num_threads, buffer_size; 
	num_threads = atoi(argv[1]);
	word_counter counter;
	
	
	file = fopen("test.txt", "r"); 
	int ch, number_of_lines = 0;

	do 
	{
		ch = fgetc(file);
		if(ch == '\n')
			number_of_lines++;
	} while (ch != EOF);
	
	
	// last line doesn't end with a new line!
	// but there has to be a line at least before the last line
	if(ch != '\n' && number_of_lines != 0) 
		number_of_lines++;

	fclose(file);
	
	//divide work for threads
	counter.lines_per_thread = number_of_lines / num_threads; 
	//allocate memory for word count and initialize to 0
	counter.count = (int*)calloc(MAX_NUMBER_OF_WORDS, sizeof(int)); 
	
	file = fopen("test.txt", "r"); 
	counter.current_location = 0; 
	pthread_t threads[num_threads]; 
	
	//initialize mutex
	 if (pthread_mutex_init(&counter.mutex, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
	for(i = 0; i < num_threads; ++i){
	//create threads
	if(pthread_create(&threads[i], NULL, count_words, &counter)){
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

//sort words in counter array
char* temp; 
for (i = 0; i < 2 ; i++) {
      for (j = 0; j < counter.current_location - 1; j++) {
         if (temp && counter.words[j] && counter.words[j+1] && strcmp(counter.words[j], counter.words[j + 1]) > 0) {
            strcpy(temp, counter.words[j]);
            strcpy(counter.words[j], counter.words[j + 1]);
            strcpy(counter.words[j + 1], temp);
         }
      }
   }
 
fclose(file); 

//print words and their occurrences 
for(i = 0; i < counter.current_location; ++i){
	printf("%s %i\n", counter.words[i], counter.count[i]);  
	
	}
	fflush(stdout);
  
   pthread_mutex_destroy(&counter.mutex);
return 0;

}