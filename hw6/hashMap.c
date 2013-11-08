#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
   struct hashLink * next; /*notice how these are like linked list nodes*/
};

typedef struct hashLink hashLink;

struct hashMap {
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/	

	for(int index = 0; index < ht->tableSize; index++){
		if(ht->table[index] != NULL){
			free(ht->table[index]);
		}
	}
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/			
	struct hashLink **oldTable = ht->table;
	struct hashLink *tmp;
	int oldTableSize = capacity(ht);
	printf("========Resizing========\n");
	_initMap(ht, newTableSize);
	assert(ht != 0);
	for(int i = 0; i < oldTableSize; ++i){
		tmp = oldTable[i];
		while(tmp != NULL){
			insertMap(ht, tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	free(oldTable);
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	/*write this*/	
	/* 3 cases:
	 * empty element
	 * pre-existing key-value pair
	 * other hash values 
	 */
	int index = 0;
	struct hashLink *newLink = malloc(sizeof(struct hashLink));
	if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
		_setTableSize(ht, 2 * capacity(ht));
	if(HASHING_FUNCTION == 1)
		index = (stringHash1(k) % capacity(ht));
	if(HASHING_FUNCTION == 2)
		index = (stringHash2(k) % capacity(ht));
	if(ht->table[index] == 0){
		//if bucket empty, create new node/link
		ht->table[index] = newLink;
		newLink->key = k;
		newLink->value = v;
		newLink->next = NULL;
		++(ht->count);
		return;
	}else{
		//if there is a key-value at that key value
		//replace the value at the key
		struct hashLink *tmp = ht->table[index];
		while(tmp != NULL){
			//if it exists in the LL
			if(strcmp(tmp->key, k) == 0){
				free(tmp->value);
				tmp->value = v;
				return;
			}else{
				tmp = tmp->next;
			}
		}
		//no key value in the linked list
		//add key to beginning of linked list
		newLink->key = k;
		newLink->value = v;
		newLink->next = ht->table[index];
		ht->table[index] = newLink;
		++(ht->count);
	}
		
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType atMap (struct hashMap * ht, KeyType k)
{ 
	/*write this*/
	int index = 0;
	//assert(k != NULL);
	if(HASHING_FUNCTION == 1)
			index = (stringHash1(k) % ht->tableSize);
	if(HASHING_FUNCTION == 2)
			index = (stringHash2(k) % ht->tableSize);
	struct hashLink *tmp = ht->table[index];
	while(tmp != NULL){
		if(strcmp(tmp->key, k) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return NULL;
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	/*
	int index = 0;
	if(HASHING_FUNCTION == 1)
			index = (stringHash1(k) % ht->tableSize);
	if(HASHING_FUNCTION == 2)
			index = (stringHash2(k) % ht->tableSize);
	if(ht->table[index]->key == k)	
		return 1;
	return 0;
	*/
	if(atMap(ht, k) != NULL)
		return 1;
	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/	
	int index = 0;
	if(HASHING_FUNCTION == 1)
		index = (stringHash1(k) % ht->tableSize);
	if(HASHING_FUNCTION == 2)
		index = (stringHash2(k) % ht->tableSize);
	struct hashLink *firstLink = ht->table[index];
	if(firstLink == NULL)
		return;
	for(struct hashLink *tmpLink = firstLink; tmpLink->next != NULL; 
						tmpLink = tmpLink->next){
		if(strcmp(tmpLink->key, k) == 0){
			struct hashLink *cpyLink = tmpLink; 
			while(cpyLink->next != NULL){
				cpyLink->key = cpyLink->next->key;
				cpyLink->value = cpyLink->next->value;
				cpyLink = cpyLink->next;
			}
			free(cpyLink);
		}

	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	/*write this*/
	return (ht->count);
	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	/*write this*/
	return (ht->tableSize);
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	/*write this*/
	int count = 0;
	for(int index = 0; index < ht->tableSize; ++index){
		if(ht->table[index] == NULL)
			++count;
	}
	return count;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	/*write this*/
	return (float)(ht->count) / (float)(ht->tableSize);
}

/* print the hashMap */
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}
