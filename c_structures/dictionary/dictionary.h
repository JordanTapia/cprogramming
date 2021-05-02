#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdint.h>

#define HASHSIZE 100


// Hashing function
// @return uint for array index
// @param char * is a string input
uint32_t hash(char * str);


// Lookup
// @return true if string found
// @param char * string to match
struct nlist * lookup(char * str);


// Install
// @param char * string to add to dictionary
// @return true if str successfully added
// Should call lookup() for checking
struct nlist * install(char * key, char * val);


void testHash();

void testLookup();

void startInstall();

void printTable();

void removeFirstWhiteSpace(char str[]);

#endif