# Hepp_CSCI2270_FinalProject
Final Project Spring 2016

This project takes 3 variations of a simple hash function and compares the resulting indices. The project takes movie titles and the year released and stores them in a hash table of linked lists. Each movie is assigned an index via these three functions and then added to each table at its respective index. Movie placement and table arrangement can then be reviewed and compared to see the differences the three hash functions have on orginization. 

Running the program is fairly straight forward. There are three necessary files: "HashTables.h", "HashTables.cpp", and "FinalProject.cpp". Upon starting the program a user menu is printed with nine options and quit. Movies are added and searched for as strings given by the user with the associated year an integer. 

I would like to add catches for garbage data from the user. Right now this is limited. Another addition I would like is printing for various data checks. It currently prints by indices in ascending order but perhaps printing table by table might be more useful sometimes.
