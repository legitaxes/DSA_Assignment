#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include<cmath>
//#include <bits/stdc++.h>
using namespace std;
#include "Dictionary.h"

/*================================COMPUTE HASH================================*/

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int) 'A';
		else
		{
			return (int)c - (int) 'a' + 26;
		}
	}
	else
	{
		return -1;
	}
}

int DictionaryStation::hash(KeyType key)
{
	int total = 0;
	int value = 0;
	string number = "";
	for (int i = 0; i < key.length(); i++)
	{
		//if this is a digit, then store the numbers as a string to be converted into a int later
		if (isdigit(key[i]))
		{
			number += key[i];
		}
		else
		{
			value = charvalue(key[i]);
			total = (total * 52) + (value*99) ;
			/*total = value * pow(52, key.length() - (i + 1)) + total;*/
			total = abs(total % MAX_SIZE);
		}
	}
	if (number != "")
	{
		// this converts string to integer
		int num = stoi(number);
		total = num + total;
	}
	return total;
}

int DictionaryCode::hash(KeyType key)
{
	int total = 0;
	int value = 0;
	for (int i = 0; i < key.length(); i++)
	{
		value = charvalue(key[i]);
		total = (total * 52) + value;
		//total = value*pow(52, key.length() - (i+1)) + total;
		total = total % MAX_SIZE;
	}
	//cout << total;
	return total;
}
/*================================DICTIONARYCODE PART================================*/
DictionaryCode::DictionaryCode() 
{ 
	for (int i = 0; i < MAX_SIZE; i++)
	{
		items[i] = NULL;
	}
	DictionaryStation station; 
}

DictionaryCode::~DictionaryCode() {}

bool DictionaryCode::Addlines(KeyType newkey)
{
	int index = hash(newkey);
	if (items[index] == NULL)
	{
		// Create a new Node
		Node *NewNode = new Node;
		NewNode->key = newkey;
		items[index] = NewNode;
		size++;
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void DictionaryCode::DisplayAllLines()
{
	cout << "\n===================Choose a Train Station Line===================" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node *tempNode = items[i];
		if (tempNode != NULL)
		{
			cout << "\n\t\t\t || || " << tempNode->key << " || || \n";
		}
	}
}

bool DictionaryCode::FindRoute(string source, string destination)
{
	return false;
}


bool DictionaryCode::AddNewLine(string stationcode, string stationname, string stationname1)
{
	return false;
}

//displays all the possible routes that a user can go given the source and destination
bool DictionaryCode::DisplayPossibleRoutes(string source, string destination)
{
	return false;
}

//this function checks whether the line exists 
bool DictionaryCode::Linebool(string line)
{
	for (int i = 0; i < size; i++)
	{
		if (items[i]->key == line)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*================================END OF DICTIONARYCODE PART================================*/

/*================================DICTIONARYSTATION PART================================*/


DictionaryStation::DictionaryStation()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		items[i] = NULL;
	}
}

DictionaryStation::~DictionaryStation()
{
}

bool DictionaryStation::AddNewStation(KeyType hashedkey,ItemType stationName, bool interchange)
{
	// stationcode = hashed key
	string linecode;
	for (int i = 0; i < hashedkey.length(); i++)
	{
		if (!isdigit(hashedkey[i]))
		{
			linecode += hashedkey[i];
		}
	}
	int index = hash(hashedkey);
	if (items[index] == NULL)
	{
		// Create a new Node
		Node *NewNode = new Node;
		NewNode->key = hashedkey;
		NewNode->stationname = stationName;
		NewNode->linecode = linecode;
		NewNode->interchange = interchange;
		items[index] = NewNode;
		size++;
		return true;
	}
	else //checks if the station added is using the same existing station code
	{
		return false;
	}
}

void DictionaryStation::DisplayAllStations(string line)
{
	cout << "\n===============================LISTING ALL THE STATIONS FROM - " << line << "=====================================\n" << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node *tempNode = items[i];
		if (tempNode != NULL)
		{
			if (tempNode->linecode == line)
			{
				cout << "============================================================================" << endl;
				if (tempNode->interchange == true)
				{
					cout << "Station Code: " << tempNode->key << " || " << "Station Name: " << tempNode->stationname << " || " << "Interchange: " << "Yes" << endl;
				}
				else
				{
					cout << "Station Code: " << tempNode->key << " || " << "Station Name: " << tempNode->stationname << " || " << "Interchange: " << "No" << endl;
				}
				cout << "============================================================================" << endl;
			}
		}
	}
}

void DictionaryStation::DisplayStationInfo(string name)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node *tempNode = items[i];
		if (tempNode != NULL && tempNode->stationname == name)
		{
			cout << "============================================================================" << endl;
			if (tempNode->interchange == true)
			{
				cout << "Station Code: " << tempNode->key << " || " << "Station Name: " << tempNode->stationname << " || " << "Interchange: " << "Yes" << endl;
			}
			else
			{
				cout << "Station Code: " << tempNode->key << " || " << "Station Name: " << tempNode->stationname << " || " << "Interchange: " << "No" << endl;
			}
			cout << "============================================================================" << endl;

		}
	}
}

/*================================END OF DICTIONARYSTATION PART================================*/

