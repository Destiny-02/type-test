#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>

// creates a delay in programme
// source: https://www.geeksforgeeks.org/time-delay-c/
void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

int main(void) 
{
	// list of words from https://www.espressoenglish.net/the-100-most-common-words-in-english/
	char words[][20] = {"the", "at", "there", "some", "my", "of", "be", "use", "her", "than", "and", "this", "an", "would", "first", "a", "have", "each", "make", "water", "to", "from", "which", "like", "been", "in", "or", "she", "him", "call", "is", "one", "do", "into", "who", "you", "had", "how", "time", "oil", "that", "by", "their", "has", "its", "it", "word", "if", "look", "now", "he", "but", "will", "two", "find", "was", "not", "up", "more", "long", "for", "what", "other", "write", "down", "on", "all", "about", "go", "day", "are", "were", "out", "see", "did", "as", "we", "many", "number", "get", "with", "when", "then", "no", "come", "his", "your", "them", "way", "made", "they", "can", "these", "could", "may", "I", "said", "so", "people", "part"};
	int num_words = 25;
	srand((unsigned int)time(NULL));
	printf("\n");
	printf("***** INSTRUCTIONS ***** \n");
	printf("This programme provides an indication of your speed typing ability\n");
	printf("Note that your WPM (word per minute) from this test may be lower than your actual or \nnatural WPM due to the word by word nature of this test\n");
	printf("You will be prompted with %d words \n", num_words);
	printf("Type out these words as quickly and as accurately as you can\n");
	printf("Then press the enter key\n");
	printf("A word is only counted as 'correct' when all punctuation, capitalisation and letters are matching\n");
	printf("Please do not add a space after the word \n");
	printf("\n");
	
	// wait for user to be ready
	char startPlay[100];
	
	while (strcmp(startPlay, "yes") != 0) {
		printf("type 'yes' to continue \n");
		scanf("%s", startPlay);
	}
	// countdown
	printf("Starting in ... \n");
	
	for (int i = 5; i>=1; i--) {
		delay(1);
		printf("%d \n", i);
	}
	delay(1);
	printf("***** time starts now ***** \n");
	time_t start = time(NULL);
	
	// questions + responses
	char response[100];
	int response_count = 0;
	
	for (int i=0; i<num_words; i++) {
		int n = rand()%100;
		while (strcmp(response, words[n])) { // ie. answers don't match
			printf("%s\n", words[n]);
			scanf("%s", response);
			response_count++;
		}
	}
	
	// calculate and display results
	double total_time = difftime(time(NULL), start);
	printf("\n***** Results *****\n");
	printf("WPM (word per minute) score: %.0f wpm\n", (num_words/total_time*60));
	printf("Accuracy score: %.2f%%\n", (100.00*num_words/response_count));
	
	return 0;
}