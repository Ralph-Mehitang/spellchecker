#include <iostream>
#include "Dictionary.h"
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>

using namespace std;
Dictionary* dictionary;
string letters[]={ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main(){
Dictionary hashtable;
int result=0;
string input;
string curr;
ifstream infile;
cout<<"Welcome to Spell Checker!"<<endl;
cout<<"---------------------------------"<<endl;
cout<<"Loading the database"<<endl;
cout<<"---------------------------------"<<endl;
auto start = std::chrono::system_clock::now();
//cout<<"what text do you want?"<<endl;
//cin>>input;
infile.open("english.txt");
while(infile>>curr){
hashtable.insert(curr);
}
infile.close();
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
hashtable.print();
cout<<endl;
hashtable.spellcheck();
char vb;	
	return 0;
}
