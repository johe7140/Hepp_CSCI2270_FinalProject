#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>

using namespace std;

struct HashElem {
	std::string title;
	int year;
	HashElem *next;
	HashElem *previous;

	HashElem() {};
	HashElem(std::string in_title, int in_year)
	{
		title = in_title;
		year = in_year;
		next = NULL;
		previous = NULL;
	}

};

class HashTable
{
public:
	HashTable();
	~HashTable();
	void printTableContents();
	void insertMovie(std::string name, int year);
	void insertMovie2(std::string name, int year);
	void insertMovie3(std::string name, int year);
	void insertMovie4(std::string name, int year, int index);
	void deleteMovie(std::string name);
	void deleteMovie2(std::string name);
	void deleteMovie3(std::string name);
	void findMovie(std::string name, int table);
	void clearHashTable(int table);
	void compareTables(int index);
	void compareMovie(std::string name);
	void mergeTables();
	void printMergeTable();
private:
	int hashSum(std::string x, int s);
	int hashSumEven(std::string x, int s);
	int hashSumOdd(std::string x, int s);
	int tableSize = 10;
	HashElem* hashTable[10];
	HashElem* hashTableEven[10];
	HashElem* hashTableOdd[10];
	HashElem* hashTableMerge[10];

};

#endif // HASHTABLE_H


