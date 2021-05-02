#include "dictionary.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct nlist {
	struct nlist * next;
	char * key;
	char * value;
};



static struct nlist * hashtab[HASHSIZE];


uint32_t hash(char * str){
	uint32_t hashval;
	for(hashval=0; *str != '\0'; str++){
		hashval = *str + 31 * hashval;
	}
	return hashval % HASHSIZE;	
}

struct nlist * lookup(char * str){
	struct nlist * new; 
	for(new  = hashtab[hash(str)]; new != NULL; new=new->next){
		if(strcmp(str, new->key) == 0){
			return new;
		}
	}

	return NULL; 
}

struct nlist * install(char * key, char * val){
	uint32_t hashval;
	struct nlist * new = lookup(key);

	if ( new == NULL){
		new = (struct nlist *) malloc(sizeof( *new ) );
		if (new == NULL){
			return NULL;
		}
		hashval = hash(key);
		new->next = hashtab[hashval];
		hashtab[hashval] = new;
		char * keydup;
		keydup = strdup(key);
		new->key = keydup;
	} else {
		free( (void*)new->value );
	}
	char * valdup;
	valdup = strdup(val);
	new->value = valdup;
	return new; 
}


void testHash(){
	char str[] = {'a','b', 'c','\0'};
	int a = hash(str);
	printf("hash of str[]: %d\n", a);
}


void printTable(){
	struct nlist * ptr;
	for(int i = 0; i < HASHSIZE; i++){
		if(hashtab[i] != NULL){
			ptr = hashtab[i];
			while(ptr != NULL){
				printf("hastab[%d]: ", i);
				printf("%s, %s\n", ptr->key, ptr->value);
				ptr = ptr->next;
			}
		} 
	}
	return;
}



void startInstall(){
	char * b;
	size_t bufsize = MAXSIZE;														
	FILE *fp = fopen("capitols.txt", "r");
	while(getline(&b, &bufsize, fp) != -1){           
		char * token2 = strtok(b, ",");
		char * token1 = strtok(NULL, "\n");	 
		removeFirstWhiteSpace(token1);
		removeFirstWhiteSpace(token2);           
		install(token1, token2);
	}
}

void testLookup()
{

}

void removeFirstWhiteSpace(char str[]){
	if( str[0] == ' ' ) {

		for(int i = 0; str[i] != '\0'; i++){
			str[i] = str[i+1];
		}
	} return;
}





