#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
using namespace std;


class Dictionary
{
private:
	const int size=16384; // sets the hash table size to the total words in english.txt +1
	int total;
	int *bucketsize;
	struct hashtable
	{
		string word;
		int key;
		hashtable *prev;
		hashtable* next;
	};

	hashtable** hashable;
	hashtable** top;

public:

	Dictionary();//constructor
	~Dictionary(); //Destructor
	void insert(string);
	void search();
	bool isempty(int key); // returns true if the table is empty
	bool isfull(); //returns true if the table is full
	int hash_table(string); //
	int table_size(); // returns the table size
	int totalval(); // returns the total number of words that are in the table
	int buckets(int); //bucketsize
	void print(); //print table stats
	void userinput();//user input function
	void spellcheck(); //spellchecker
	void lowercase(string);
	bool search(string); // string to check hash


};
#endif
