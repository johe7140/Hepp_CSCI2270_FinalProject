//Joshua Hepp
//Professor Hoenigman
//Final Project

#include<iostream>
#include"HashTables.h"

using namespace std;

HashTable ht;				//Hash table of linked lists of movie nodes

void printMenu();			//User Menu

int subMenu();

int main() {
	bool cont = true;		//Bool for program continue
	int selection, year, index;	//User menu input
	string title;
	string choice;
	while (cont) {			//Runs menu until quit 
		printMenu();
		cin >> selection;
		cin.ignore();
		switch (selection) {
		case 1:				//Insert Movie
			cout << "Enter title:" << endl;
			getline(cin, title);
			cout << "Enter year:" << endl;
			cin >> year;
			cin.ignore();
			ht.insertMovie(title, year);		//Adds movie to hash table of linked lists
			ht.insertMovie2(title, year);
			ht.insertMovie3(title, year);
			break;

		case 2:				//Delete Movie
			cout << "Enter title:" << endl;
			getline(cin, title);
			ht.deleteMovie(title);				//Finds movie by title if present and deletes
			ht.deleteMovie2(title);
			ht.deleteMovie3(title);
			break;

		case 3:				//Find Movie
			cout << "Enter title:" << endl;
			getline(cin, title);
			cout << "Enter Table number (1, 2, or 3):" << endl;
			cin >> index;
			cin.ignore();
			ht.findMovie(title, index);			//Finds movie by title if present and prints movie information
			break;

		case 4:				//Print Table
			cout<<"Which Table? (Table 1/Table 2/Table 3/All)"<<endl;
		    	getline(cin,choice);
		    	ht.printOneAtTime(choice);

		    	if(choice == "All")
        		{
                		ht.printTableContents();
            		}
						//Prints content of first three tables
			break;

		case 5:				//Compare Movie
			cout << "Enter movie to compare:" << endl;
			getline(cin, title);
			ht.compareMovie(title);				//Compares the different indices of movie
			break;

		case 6:				//Compare Table Indices
			cout << "Enter index number to compare:" << endl;
			cin >> index;
			cin.ignore();
			ht.compareTables(index);			//Compares movies stored in specific indices
			break;

		case 7:				//Clear Table
			index = subMenu();					//Menu for table select
			ht.clearHashTable(index);			//Sets selected table to newly initialized state
			cout << "Table " << index << " cleared" << endl;
			break;

		case 8:				//Merge Tables
			ht.mergeTables();					//Copies data from tables to a fourth table
			break;

		case 9:				//Print Merge Table
			ht.printMergeTable();				//Prints combined table
			break;

		case 0:									//Quit
			cont = false;
			cout << "Goodbye!" << endl;
			break;

		default:
			cout << "Invalid selection." << endl;
		}
	}
	return 0;
}

void printMenu() {
	cout << "======Main Menu======" << endl;
	cout << "1. Insert movie" << endl;
	cout << "2. Delete movie" << endl;
	cout << "3. Find movie" << endl;
	cout << "4. Print table contents" << endl;
	cout << "5. Compare Movies" << endl;
	cout << "6. Compare Table Indices" << endl;
	cout << "7. Clear Table" << endl;
	cout << "8. Merge Tables" << endl;
	cout << "9. Print Merged Table" << endl;
	cout << "0. Quit" << endl;
}

int subMenu() {
	int tableclear;
	cout << "1. Clear Table 1 (default hash)" << endl;
	cout << "2. Clear Table 2 (even hash)" << endl;
	cout << "3. Clear Table 3 (odd hash)" << endl;
	cout << "4. Clear Table 4 (merge table)" << endl;
	cin >> tableclear;
	cin.ignore();
	return tableclear;

}
