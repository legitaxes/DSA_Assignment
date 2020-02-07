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
	if (isalnum(c))
	{
		if (isupper(c))
			return (int)c - (int) 'A';
		else if (islower(c))
		{
			return (int)c - (int) 'a' + 26;
		}
		else
		{
			return (int)c - (int) 'a' + 26 + c;
		}
	}
	else
	{

	}
	return -1;
}

int DictionaryStation::hash(KeyType key)
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

bool DictionaryCode::Addlines(KeyType newkey, ItemType newitem)
{
	int index = hash(newkey);
	if (items[index] == NULL)
	{
		// Create a new Node
		Node *NewNode = new Node;
		NewNode->linename = newitem;
		NewNode->key = newkey;
		NewNode->next = NULL;
		items[index] = NewNode;
	}
	else
	{
		Node *currentNode = items[index];
		if (currentNode->key == newkey)
		{
			return false;
		}
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
			if (currentNode->key == newkey)
			{
				return false;
			}
		}
		// Create a new Node
		Node *NewNode = new Node;
		NewNode->linename = newitem;
		NewNode->key = newkey;
		NewNode->next = NULL;
		currentNode = items[index];
	}
	size++;
	return true;
}

void DictionaryCode::DisplayAllLines()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node *tempNode = items[i];
		if (tempNode != NULL)
		{

			cout << "Index = " << i << endl;
			cout << "Key: " << tempNode->key << endl;
			cout << "Item: " << tempNode->linename << endl;
			cout << "-------------------------" << endl;
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

bool DictionaryCode::DisplayPossibleRoutes(string source, string destination)
{
	return false;
}


bool DictionaryCode::Linebool(string line)
{
	for (int i = 0; i < size; i++)
	{
		if (items[i]->linename == line)
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

bool DictionaryStation::AddNewStation(KeyType hashedkey,  string linecode,ItemType stationName, bool interchange)
{
	DictionaryCode code;
	// stationcode = hashed key
	bool line = code.Linebool(hashedkey);
	if (line == true)
	{
		int index = hash(hashedkey);
		if (items[index] == NULL)
		{
			// Create a new Node
			Node *NewNode = new Node;
			NewNode->key = hashedkey;
			NewNode->stationname = stationName;
			NewNode->linecode = linecode;
			NewNode->interchange = interchange;
			NewNode->next = NULL;
			items[index] = NewNode;
		}
		else
		{
			Node *currentNode = items[index];
			if (currentNode->key == hashedkey)
			{
				return false;
			}
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
				if (currentNode->key == hashedkey)
				{
					return false;
				}
			}
			// Create a new Node
			Node *NewNode = new Node;
			NewNode->key = hashedkey;
			NewNode->stationname = stationName;
			NewNode->linecode = linecode;
			NewNode->interchange = interchange;
			NewNode->next = NULL;
			currentNode = items[index];
		}
	}
	size++;
	return true;
}

void DictionaryStation::DisplayAllStations(string line)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node *tempNode = items[i];
		if (tempNode != NULL)
		{
			if (tempNode->linecode == line)
			{
				cout << "Index = " << i << endl;
				cout << "Key: " << tempNode->key << endl;
				cout << "stationname: " << tempNode->stationname << endl;
				cout << "Interchange? " << tempNode->interchange << endl;
				cout << "-------------------------" << endl;
			}
		}
	}
}

void DictionaryStation::DisplayStationInfo(string name)
{

}
/*================================END OF DICTIONARYSTATION PART================================*/

