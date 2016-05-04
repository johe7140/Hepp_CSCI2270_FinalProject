#include "HashTables.h"



HashTable::HashTable() {		//Initializes hashTable contents
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = new HashElem;
		hashTable[i]->next = NULL;
		hashTable[i]->previous = NULL;
		hashTableEven[i] = new HashElem;
		hashTableEven[i]->next = NULL;
		hashTableEven[i]->previous = NULL;
		hashTableOdd[i] = new HashElem;
		hashTableOdd[i]->next = NULL;
		hashTableOdd[i]->previous = NULL;
		hashTableMerge[i] = new HashElem;
		hashTableMerge[i]->next = NULL;
		hashTableMerge[i]->previous = NULL;
	}
}

HashTable::~HashTable()
{
}

void HashTable::insertMovie(std::string name, int year) {
	int elemsum = hashSum(name, tableSize);		//finds hashtable index for new movie
	HashElem *insert = new HashElem(name, year);
	HashElem *tmp = hashTable[elemsum];
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = insert;
	insert->previous = tmp;
}

void HashTable::insertMovie2(std::string name, int year) {
	int elemsum = hashSumEven(name, tableSize);		//finds hashtable index for new movie
	HashElem *insert = new HashElem(name, year);
	HashElem *tmp = hashTableEven[elemsum];
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = insert;
	insert->previous = tmp;
}

void HashTable::insertMovie3(std::string name, int year) {
	int elemsum = hashSumOdd(name, tableSize);		//finds hashtable index for new movie
	HashElem *insert = new HashElem(name, year);
	HashElem *tmp = hashTableOdd[elemsum];
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = insert;
	insert->previous = tmp;
}

void HashTable::insertMovie4(std::string name, int year, int index) {
	HashElem *insert = new HashElem(name, year);
	HashElem *tmp = hashTableMerge[index];
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = insert;
	insert->previous = tmp;
}

void HashTable::findMovie(std::string name, int table) {
	if (table == 1) {
		int elemsum = hashSum(name, tableSize);
		HashElem *find = hashTable[elemsum];
		while (find != NULL) {
			if (find->title == name) {
				break;
			}
			find = find->next;
		}
		if (find != NULL) {
			cout << elemsum << ":" << find->title << ":" << find->year << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	else if (table == 2) {
		int elemsum = hashSumEven(name, tableSize);
		HashElem *find = hashTableEven[elemsum];
		while (find != NULL) {
			if (find->title == name) {
				break;
			}
			find = find->next;
		}
		if (find != NULL) {
			cout << elemsum << ":" << find->title << ":" << find->year << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	else if (table == 3) {
		int elemsum = hashSumOdd(name, tableSize);
		HashElem *find = hashTableOdd[elemsum];
		while (find != NULL) {
			if (find->title == name) {
				break;
			}
			find = find->next;
		}
		if (find != NULL) {
			cout << elemsum << ":" << find->title << ":" << find->year << endl;
		}
		else {
			cout << "not found" << endl;
		}
	}
	else {
		cout << "Data not found" << endl;
	}
}

void HashTable::deleteMovie(std::string name) {
	int elemsum = hashSum(name, tableSize);
	HashElem *del = hashTable[elemsum];
	HashElem *tmp = del;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->title == name) {
			del = tmp;
			break;
		}
	}
	if (del->title == name) {
		if (del->next != NULL) {
			if (del->previous != NULL) {
				del->previous->next = del->next;
				del->next->previous = del->previous;
				delete del;
			}
		}
		else if (del->previous != NULL) {
			del->previous->next = NULL;
			delete del;
		}
		else {
			delete del;
		}
	}
}

void HashTable::deleteMovie2(std::string name) {
	int elemsum = hashSumEven(name, tableSize);
	HashElem *del = hashTableEven[elemsum];
	HashElem *tmp = del;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->title == name) {
			del = tmp;
			break;
		}
	}
	if (del->title == name) {
		if (del->next != NULL) {
			if (del->previous != NULL) {
				del->previous->next = del->next;
				del->next->previous = del->previous;
				delete del;
			}
		}
		else if (del->previous != NULL) {
			del->previous->next = NULL;
			delete del;
		}
		else {
			delete del;
		}
	}
}

void HashTable::deleteMovie3(std::string name) {
	int elemsum = hashSumOdd(name, tableSize);
	HashElem *del = hashTableOdd[elemsum];
	HashElem *tmp = del;
	while (tmp->next != NULL) {
		tmp = tmp->next;
		if (tmp->title == name) {
			del = tmp;
			break;
		}
	}
	if (del->title == name) {
		if (del->next != NULL) {
			if (del->previous != NULL) {
				del->previous->next = del->next;
				del->next->previous = del->previous;
				delete del;
			}
		}
		else if (del->previous != NULL) {
			del->previous->next = NULL;
			delete del;
		}
		else {
			delete del;
		}
	}
}
void HashTable::printOneAtTime(string choice)
{
    bool empty = true;
    bool empty2 = true;
    bool empty3 = true;
    for(int i = 0; i< tableSize; i++)
    {
        HashElem *temp = hashTable[i];
        HashElem *tmp = hashTable[i];
		HashElem *tmp2 = hashTableEven[i];
		HashElem *tmp3 = hashTableOdd[i];
		tmp = tmp->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;

		if(choice == "Table 1")
        {

            while (tmp != NULL)
            {			//Prints table contents if filled at index
			cout << "Table 1 " << i << ":" << tmp->title << ", " << tmp->year << endl;
			empty = false;
			tmp = tmp->next;
            }

        }


        if(choice == "Table 2")
        {
            while (tmp2 != NULL)
            {
			cout << "Table 2 " << i << ":" << tmp2->title << ", " << tmp2->year << endl;
			empty2 = false;
			tmp2 = tmp2->next;
            }
        }

        if(choice == "Table 3")
        {
            while (tmp3 != NULL) {
			cout << "Table 3 " << i << ":" << tmp3->title << ", " << tmp3->year << endl;
			empty3 = false;
			tmp3 = tmp3->next;
            }
        }


    }
	if ((empty) && (choice == "Table 1")) {						//Prints empty if table is empty at index
		cout << "Table 1 empty" << endl;
	}
	if ((empty2)&& (choice == "Table 2")) {
		cout << "Table 2 empty" << endl;
	}
	if ((empty3) && (choice == "Table 3")) {
		cout << "Table 3 empty" << endl;
	}
}

void HashTable::printTableContents() {
	bool empty = true;
	bool empty2 = true;
	bool empty3 = true;
	for (int i = 0; i < tableSize; i++) {
		HashElem *tmp = hashTable[i];
		HashElem *tmp2 = hashTableEven[i];
		HashElem *tmp3 = hashTableOdd[i];
		tmp = tmp->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
		while (tmp != NULL) {			//Prints table contents if filled at index
			cout << "Table 1 " << i << ":" << tmp->title << ", " << tmp->year << endl;
			empty = false;
			tmp = tmp->next;
		}
		while (tmp2 != NULL) {
			cout << "Table 2 " << i << ":" << tmp2->title << ", " << tmp2->year << endl;
			empty2 = false;
			tmp2 = tmp2->next;
		}
		while (tmp3 != NULL) {
			cout << "Table 3 " << i << ":" << tmp3->title << ", " << tmp3->year << endl;
			empty3 = false;
			tmp3 = tmp3->next;
		}
	}
	if (empty) {						//Prints empty if table is empty at index
		cout << "Table 1 empty" << endl;
	}
	if (empty2) {
		cout << "Table 2 empty" << endl;
	}
	if (empty3) {
		cout << "Table 3 empty" << endl;
	}
}

void HashTable::compareMovie(std::string name) {		//Prints movie index information for each table
	int elemsum1 = hashSum(name, tableSize);
	int elemsum2 = hashSumEven(name, tableSize);
	int elemsum3 = hashSumOdd(name, tableSize);
	HashElem *compare1 = hashTable[elemsum1];
	HashElem *compare2 = hashTableEven[elemsum2];
	HashElem *compare3 = hashTableOdd[elemsum3];
	while (compare1 != NULL) {
		if (compare1->title == name) {
			break;
		}
		compare1 = compare1->next;
	}
	while (compare2 != NULL) {
		if (compare2->title == name) {
			break;
		}
		compare2 = compare2->next;
	}
	while (compare3 != NULL) {
		if (compare3->title == name) {
			break;
		}
		compare3 = compare3->next;
	}
	if (compare1 != NULL) {
		cout << "Table 1 " << elemsum1 << ": " << compare1->title << ", " << compare1->year << endl;
	}
	else {
		cout << "Table 1 - Movie not found" << endl;
	}
	if (compare2 != NULL) {
		cout << "Table 2 " << elemsum2 << ": " << compare2->title << ", " << compare2->year << endl;
	}
	else {
		cout << "Table 2 - Movie not found" << endl;
	}
	if (compare1 != NULL) {
		cout << "Table 3 " << elemsum3 << ": " << compare3->title << ", " << compare3->year << endl;
	}
	else {
		cout << "Table 3 - Movie not found" << endl;
	}

}

void HashTable::compareTables(int index) {			//Prints table information at index
    bool empty = true;
    bool empty2 = true;
    bool empty3 = true;
    if(index<10&&index>-1)
    {
        HashElem *tmp = hashTable[index];
        HashElem *tmp2 = hashTableEven[index];
        HashElem *tmp3 = hashTableOdd[index];
        tmp = tmp->next;
        if (tmp != NULL) {
            cout << "Table 1 - Index " << index << ":" << endl;
        }
        while (tmp != NULL) {
            empty = false;
            cout << tmp->title << ", " << tmp->year;
            tmp = tmp->next;
            if (tmp != NULL) {
                cout << " -> ";
            }
            else {
                cout << endl;
            }
        }

        tmp2 = tmp2->next;
        if (tmp2 != NULL) {
            cout << "Table 2 - Index " << index << ":" << endl;
        }
        while (tmp2 != NULL) {
            empty2 = false;
            cout << tmp2->title << ", " << tmp2->year;
            tmp2 = tmp2->next;
            if (tmp2 != NULL) {
                cout << " -> ";
            }
            else {
                cout << endl;
            }
        }

        tmp3 = tmp3->next;
        if (tmp3 != NULL) {
            cout << "Table 3 - Index " << index << ":" << endl;
        }
        while (tmp3 != NULL) {
            empty3 = false;
            cout << tmp3->title << ", " << tmp3->year;
            tmp3 = tmp3->next;
            if (tmp3 != NULL) {
                cout << " -> ";
            }
            else {
                cout << endl;
            }
        }
    }

	if (empty) {				//Prints empty if table empty at index
		cout << "Table 1 - Index " << index << ": is empty" << endl;
	}
	if (empty2) {
		cout << "Table 2 - Index " << index << ": is empty" << endl;
	}
	if (empty3) {
		cout << "Table 3 - Index " << index << ": is empty" << endl;
	}
}

void HashTable::clearHashTable(int index) {			//Deletes movie information and resets table to newly initialized state
	if (index == 1) {
		for (int i = 0; i < tableSize; i++) {
			HashElem *tmp = hashTable[i];
			while(tmp != NULL){
				HashElem *del = tmp;
				tmp = tmp->next;
				del->next = NULL;
				del->previous = NULL;
				delete del;
			}
			hashTable[i] = new HashElem;
			hashTable[i]->next = NULL;
			hashTable[i]->previous = NULL;
		}
	}
	if (index == 2) {
		for (int i = 0; i < tableSize; i++) {
			HashElem *tmp = hashTableEven[i];
			while (tmp != NULL) {
				HashElem *del = tmp;
				tmp = tmp->next;
				del->next = NULL;
				del->previous = NULL;
				delete del;
			}
			hashTableEven[i] = new HashElem;
			hashTableEven[i]->next = NULL;
			hashTableEven[i]->previous = NULL;
		}
	}
	if (index == 3) {
		for (int i = 0; i < tableSize; i++) {
			HashElem *tmp = hashTableOdd[i];
			while (tmp != NULL) {
				HashElem *del = tmp;
				tmp = tmp->next;
				del->next = NULL;
				del->previous = NULL;
				delete del;
			}
			hashTableOdd[i] = new HashElem;
			hashTableOdd[i]->next = NULL;
			hashTableOdd[i]->previous = NULL;
		}
	}
	if (index == 4) {
		for (int i = 0; i < tableSize; i++) {
			HashElem *tmp = hashTableMerge[i];
			while (tmp != NULL) {
				HashElem *del = tmp;
				tmp = tmp->next;
				del->next = NULL;
				del->previous = NULL;
				delete del;
			}
			hashTableMerge[i] = new HashElem;
			hashTableMerge[i]->next = NULL;
			hashTableMerge[i]->previous = NULL;
		}
	}
}

void HashTable::mergeTables() {			//Copies table data to a single combined table
	clearHashTable(4);
	string name;
	int year;
	for (int i = 0; i < tableSize; i++) {
		HashElem *tmp = hashTable[i]->next;
		HashElem *tmp2 = hashTableEven[i]->next;
		HashElem *tmp3 = hashTableOdd[i]->next;
		while (tmp != NULL) {
			name = tmp->title;
			year = tmp->year;
			insertMovie4(name, year, i);
			tmp = tmp->next;
		}
		while (tmp2 != NULL) {
			name = tmp2->title;
			year = tmp2->year;
			insertMovie4(name, year, i);
			tmp2 = tmp2->next;
		}
		while (tmp3 != NULL) {
			name = tmp3->title;
			year = tmp3->year;
			insertMovie4(name, year, i);
			tmp3 = tmp3->next;
		}
	}
}

void HashTable::printMergeTable() {
	for (int i = 0; i < tableSize; i++) {
		HashElem *tmp = hashTableMerge[i]->next;
		while (tmp != NULL) {
			cout << i << ": " << tmp->title << ", " << tmp->year;
			tmp = tmp->next;
			if (tmp != NULL) {
				cout << " -> ";
			}
			else {
				cout << endl;
			}
		}
	}
}

int HashTable::hashSum(std::string x, int s) {			//Calculates base hash function for table index
	int sum = 0;
	for (unsigned int i = 0; i < x.size(); i++) {
		sum = sum + x[i];
	}
	sum = sum % tableSize;
	return sum;
}

int HashTable::hashSumEven(std::string x, int s) {		//Calculates hash function using even string members
	int sum = 0;
	for (unsigned int i = 0; i < x.size(); i++) {
		if (i % 2 == 0) {
			sum = sum + x[i];
		}
	}
	sum = sum % tableSize;
	return sum;
}

int HashTable::hashSumOdd(std::string x, int s) {		//Calculates hash function using odd string members
	int sum = 0;
	for (unsigned int i = 0; i < x.size(); i++) {
		if (i % 2 != 0) {
			sum = sum + x[i];
		}
	}
	sum = sum % tableSize;
	return sum;
}
