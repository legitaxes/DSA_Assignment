// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//if a station has > 2 station code == interchange

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main()
{
	//==================Read all the files first===============================
	//reads the fare file and saving the data into an array
	ifstream ip("Fares.csv");
	if (!ip.is_open())
		cout << "Error: File Open" << "\n";
	string fare;
	string fare_distance;
	float fareArray[20][2];
	int i = 0;
	//initialise an array and store the fare and fare_distance
	while (ip.good())
	{
		getline(ip, fare_distance, ',');
		getline(ip, fare, '\n');
		float distance = stof(fare_distance);
		float fares = stof(fare);
		fareArray[i][i] = distance;
		fareArray[i][i + 1] = fares;
		cout << fareArray[i][i] << " " << fareArray[i][i + 1] << "\n";
		i++;
		//cout << "The fare distance is " << distance << "KM based on the price " << fares << "cents" << "\n";
	}
	ip.close();

	//-----------------------------------------------------------------------
	//read the station information data and save the data somewhere [not done: save the station somewhere]
	ifstream op("Stations.csv");
	if (!op.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string station_code;
	string station_name;
	while (op.good())
	{
		getline(op, station_code, ',');
		getline(op, station_name, '\n');
		cout << "Station Code: " << station_code << " Station Name: " << station_name << "\n";
	}
	op.close();
	//-----------------------------------------------------------------------

	//read the station interchange data and save the data somewhere [not done: save it somewhere, should be stored as array]
	ifstream lp("Interchanges.csv");
	if (!lp.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string station_code1;
	string station_code2;
	while (lp.good())
	{
		getline(lp, station_code1, ',');
		getline(lp, station_code2, '\n');
		cout << "Station Code: " << station_code1 << " " << station_code2 << "\n";
	}
	lp.close();
	//-----------------------------------------------------------------------

	//read the station interchange data and save the data somewhere [not done: save it somewhere, how to read the file using while loop]
	ifstream xp("Routes.csv");
	if (!xp.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string input;
	string station_route;
	string distance;
	while (getline(xp, input, ','))
	{

		if (!getline(xp, input, '\n'))
		{
			station_route = input;
			cout << station_route << "\n";
		}
		cout << "Station Code: " << station_code << "\n";
	}
	xp.close();
	//-----------------------------------------------------------------------

	//==================Display menu functions===============================
	int option = -1;
	while (option != 0)
	{
		displayMenu();
		cin >> option;

		if (option == 1)	// display items
		{
			//bst.inorder();
		}
		else
		{
			if (option == 2)	// search item
			{
				//cout << "Enter a number to search : ";
				//cin >> target;
				//BinaryNode* p = bst.search(target);
				//if (p != NULL)
				//	cout << "Found" << endl;
				//else
				//	cout << "Not found" << endl;
			}
			else
				if (option == 3)	// add item
				{
					//int n;
					//cout << "Enter a number to add : ";
					//cin >> n;
					//bst.insert(n);
				}
				else
					if (option == 4)	// delete item
					{
						//int n;
						//cout << "Enter a number to delete : ";
						//cin >> n;
						//bst.remove(n);
					}
					else
						if (option == 5)
						{
							//	int n = bst.countNodes();
							//	cout << "The number of nodes there are is " << n;
						}
			// display number of items

						else
							if (option == 6)	// display height
							{
								//	int n = bst.getHeight();
								//	cout << "The height of the nodes is " << n;
							}
							else
								if (option == 7)	// check if tree is balanced
								{
									//		bool b = bst.isBalanced();
									//		if (b == true)
									//		{
									//			cout << "The tree is balanced!";
									//		}
									//		else
									//		{
									//			cout << "The tree is not balanced! :(";
									//		}
								}
								else
									if (option == 0)
										cout << "Bye! \n";
									else
										cout << "Sorry. You have entered an invalid option. \n";
		}
	}
}

void displayMenu()
{
	cout << endl;
	cout << "MRT Station \n";
	cout << "--------------------------------\n";
	cout << "[1] Display all the stations in a given line\n";
	cout << "[2] Display station information for a given name \n";
	cout << "[3] Add and Save a new station on a given MRT line \n";
	cout << "[4] Find and display a route and price based on source and destination stations\n";
	cout << "[5] Add a new line [ADV] \n";
	cout << "[6] Search for Shortest Route and its Price [ADV] \n";
	cout << "[7] Display 3 possible routes with price and distance [ADV] \n";
	cout << "[0] Exit \n";
	cout << "--------------------------------\n";
	cout << "Enter option : ";
}
