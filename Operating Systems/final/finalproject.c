#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUMBER_OF_WORDS 1000000//this can be made bigger with more memory
#define MAX_SIZE_WORD 50
#define _FILE_OFFSET_BITS 64


FILE *file;

 //struct to hold global info
typedef struct {
	int size,chars_per_thread, current_location, current_word, current_char; 
	char **words;
	int *count; 
	pthread_mutex_t mutex; 
} word_counter;


//thread function to go through a portion of the text file and store the words in the word counter
void *count_words(void* a)
{

word_counter* counter = a;  
pthread_mutex_lock(&counter->mutex);
int found_word = 0, c, chars = 0, stop = 1,found_apostrophe = 0, current_char = 0, current_word = 0, i, lines = 0;
char **str = (char**) calloc(MAX_NUMBER_OF_WORDS, sizeof(char*));
for ( i = 0; i < MAX_NUMBER_OF_WORDS; i++ )
{
    str[i] = (char*) calloc(MAX_SIZE_WORD, sizeof(char));
}


  while ((c =fgetc(file)) != EOF){
	chars++; 
		if (!isalpha(c))
		{//printf("%s\n", str[current_word]); 
			if (found_word) {
				if (!found_apostrophe && c=='\'') {
                found_apostrophe = 1;
				}
			
            else {
				
				if(same(str[current_word], counter) ==1){ 
				counter->words[counter->current_word] = str[current_word]; 
				counter->count[counter->current_word]++;
				counter->current_word ++; 
				
				
				}
				current_word ++; 
				current_char = 0; 
			    found_apostrophe = 0;
                found_word = 0;
				if(chars > counter->chars_per_thread)
				stop = 0; 
				
            }
            }
		}
    else {
        if (found_apostrophe) {
			//counter->words[counter->current_word][counter->current_char] = '\'';
			str[current_word][current_char] = '\'';
			current_char++; 
			//counter->current_char ++;
            found_apostrophe == 0;
        }
        found_word = 1;
        c = tolower(c);
		str[current_word][current_char] = c; 
		current_char++;
    }

        }
    free(str); 
	
	
     pthread_mutex_unlock(&counter->mutex);

   		return 0;
	pthread_exit(NULL);

}


int same(char *str, word_counter* counter){
	int i; 
	
	for(i = 0; i < counter->current_word; i++){
		
		if(strcmp(counter->words[i], str) ==0){
	//	printf("str: %s, word[i]: %s\n", str, counter->words[i]); 
		counter->count[i]++; 
		return 0;
		}
	} 
	return 1; 
}

int main(int argc, char **argv)
{	
	
	int size, j; 
	if(argc < 1){
        printf("improper argument! Refer to the ReadMe.");
        return 1;
    }
    int i, num_threads;
	long characters = 0; 
	num_threads = atoi(argv[1]);
	word_counter counter;
	
	//get number of chars in a file and divide it evenly among threads
	file = fopen("test.txt", "r"); 
	int c; 
	while ((c =fgetc(file)) != EOF ){
		
		characters ++; 
}

	counter.chars_per_thread = characters/num_threads; 
	printf("chars: %lu, chars per thread: %d\n", characters, counter.chars_per_thread);
	fclose(file);
	
	counter.current_char = 0; 
	counter.current_word = 0; 
	counter.count = (int*)calloc(MAX_NUMBER_OF_WORDS, sizeof(int)); 
	counter.words = (char**) calloc(MAX_NUMBER_OF_WORDS, sizeof(char*));

for ( i = 0; i < MAX_NUMBER_OF_WORDS; i++ )
{
    counter.words[i] = (char*) calloc(MAX_SIZE_WORD, sizeof(char));
}
	
	file = fopen("test.txt", "r"); 
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
int count_temp; 
for (i = 0; i < counter.current_word ; i++) {
      for (j = 0; j < counter.current_word - 1; j++) {
         if (strcmp(counter.words[j], counter.words[j + 1]) > 0) {
            strcpy(temp, counter.words[j]);
			count_temp = counter.count[j]; 
            strcpy(counter.words[j], counter.words[j + 1]);
			counter.count[j] = counter.count[j+1];
            strcpy(counter.words[j + 1], temp);
			counter.count[j+1] = count_temp; 
         }
      }
   }
 
 
fclose(file); 

//print words and their occurrences  
for(i = 0; i < counter.current_word; ++i){
	printf("%s %i\n", counter.words[i], counter.count[i]);  
	
	}
  
   //pthread_mutex_destroy(&counter.mutex);
return 0;

}