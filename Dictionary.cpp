#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include <cctype>
#include<string>
#include <limits>
#include <iomanip>
#include <vector>

//constructor
//const int size_table = 466546;
Dictionary::Dictionary(){

	hashable=new hashtable*[size];
	top=new hashtable*[size];
	bucketsize=new int[size];
	for (int i = 0; i <size; i++)
	{
		hashable[i]=NULL;
		top[i]=NULL;
		bucketsize[i]=0;
	}
	total=0;
}

bool ::Dictionary:: isfull(){
	//implement code
}

bool Dictionary::isempty(int k){
	if(k>=0&&k<size){
		return hashable[k]==NULL;
	}

	else
		return true;

}

int Dictionary:: hash_table(string word){
int seed=131;
long total=0;
for (int i = 0; i < word.length(); i++)
{
	total=(total*seed) + word[i];
}
total=total % size;

return abs(total); //absolute value function c++ lib func
}

void Dictionary::insert(string nancy){
int k=hash_table(nancy);
hashtable *val = new hashtable;
val->word=nancy;
val->next = hashable[k];
hashable[k]=val;
if(val->next){
	val->next->prev=val;
}
bucketsize[k]++;
total++;
}

int Dictionary::buckets(int key){

return bucketsize[key];
}

int Dictionary :: table_size(){
return size;

}

int Dictionary:: totalval(){

	return total;
}


void Dictionary :: print(){
	int largestbucket=-9999999;
	int largestindex=0;
	int smallestbucket=9999999;
	int smallestindex=0;
	double usedbuckets=0;
	for (int i = 0; i <table_size(); i++)
	{
		if (!isempty(i))
		{
			if(smallestbucket>buckets(i)){
				smallestbucket=buckets(i);
				smallestindex=i;
			}
			if (largestbucket<buckets(i)){
				largestbucket=buckets(i);
				largestindex=i;
			}
			usedbuckets++;

		}
	}
	cout<<"Stats:"<<endl;
	cout<<"Total words in Dictionary "<<totalval()<<endl;
	cout<<"Size of hash table = "<<table_size()<<endl;
	cout<<"Largest bucket size : "<<largestbucket<<endl;
	cout<<"smallest bucket size : "<<smallestbucket<<endl;
	cout <<"total bucket used ="<<usedbuckets<<endl;
	cout<<"average number of nodes in each bucket "<<totalval()/usedbuckets<<endl;

}
void Dictionary:: spellcheck(){
	string input;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"spellcheck program "<<endl;
	cout<<"Please enter a sentence"<<endl;
	getline(cin,input);
	istringstream ss(input);
	vector<string> v;

    // Traverse through all words
    do {
        // Read a word
        string word;
        ss >> word;
				int size=word.length();
				char c;
				for (int i = 0; i < size; i++) {
						c=word[i];
						if(c==','||c=='.'||c=='/'||c==';'||c==':'||c==' '){
							word.erase(i,1);
						}
    }
			v.push_back(word);
	}while (ss);
	//search function
	cout<<"-----------------------"<<endl;
	for (int k = 0; k < v.size()-1; k++) {
		string hvals=v[k];
		if(!search(hvals)){
			cout<<hvals<<" is misspelled"<<endl;
		}
	}
}
bool Dictionary::search(string word){
	int tmp=hash_table(word);
	hashtable *curr=hashable[tmp];
	while(curr){
	if(curr->word==word){
		return true;
	}
	else{
		curr=curr->next;
	}
}
	return false;
}
Dictionary::~Dictionary(){
total=0;
int check=0;
while(!isempty(check)){
	while(!isempty(check)){
		hashtable *tmpval=hashable[check];
		hashable[check]=hashable[check]->next;
		delete tmpval;
	}
	bucketsize=0;
}
}
