#pragma once
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 1325;
typedef string KeyType; //station code is the keytype
typedef string ItemType; 

class DictionaryStation //dictionarystation is the 2nd dictionary which stores the stationnumber and a node which stores all information of the station
{
private:
	
	struct Node
	{
		KeyType key;   // search key = this is station number
		string stationcode; // Station code e.g EW1
		int stationnumber;
		ItemType stationname;
		bool interchange;
	};

	Node *items[MAX_SIZE];
public:

	// constructor
	DictionaryStation();

	// destructor
	~DictionaryStation();

	int hash(KeyType key);
	bool add(KeyType hashedkey, int stationnumber, ItemType stationname, ItemType nextdistance, bool interchange, bool visited);
};

class DictionaryCode //dictionarycode is the 1st dictionary which stores the line code which points to the second dictionary
{
private:

	
	struct Node
	{
		KeyType key; //search key = this is station line
		ItemType linename; // line name is the station line e.g. EW
		Node *next;
	};
	Node *items[MAX_SIZE];
	DictionaryStation dict;
	ItemType stationcode;
	//DictionaryCode *stationcode[MAX_SIZE];
	int size;

public: //where all the methods are stored

	// constructor
	DictionaryCode();

	// destructor
	~DictionaryCode();

	int hash(KeyType key);

	// Add stations to the given line
	// Pre: none
	// Post: Added stations to the given line
	void Addlines(KeyType newkey);

	// Displays all the station based on given line
	// pre : checks the station code and determine the line
	// post: print out all station name based on the line
	void DisplayAllStations(KeyType newkey);

	// Displays all the station information (Station Name, Station Code, whether it is an interchange) based on given station name
	// pre : check station name validity, whether it exists
	// post: station information is printed out 
	void DisplayStationInfo(string name);

	// add a new station with the specified station code to the DictionaryStation
	// pre : checks whether the stationcode exists
	// post: new item is added to the Dictionary, 
	// station needs to link to the next station,
	// size of Dictionary is increased by 1
	// Station should be updated and written in the file
	bool AddNewStation(KeyType newKey, ItemType newItem);

	// print out the route and price of the route based on the given source and destination
	// pre : checks whether the station name exists for both source and destination
	// post: a chain of station should be printed out in the program
	bool FindRoute(string source, string destination);

	// Add a new line to the MRT Map
	// pre : checks which existing stationcode to add to, user have to create a station code and at least 2 stationname with their distance 
	// post: a new line is added and linked to another station. This other station will be added as an interchange
	bool AddNewLine(string stationcode, string stationname, string stationname1);

	// Displays 3 possbile route with their price and distance based on the given source and destination of the station
	// pre : checks whether source and destination exists
	// post: Display all 3 possible routes with their price and distance
	bool DisplayPossibleRoutes(string source, string destination);
};
