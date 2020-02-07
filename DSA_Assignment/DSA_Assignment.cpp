// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//if a station has > 2 station code == interchange

#include "Dictionary.h"
#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main()
{
	DictionaryCode line;
	string l;
	DictionaryStation stations;
	//line.Addlines("EW");
	//line.Addlines("NS");
	////line.DisplayAllLines();
	//stations.AddNewStation("EW1", "EW" ,"Pasir Ris", false);
	//stations.AddNewStation("EW2", "EW", "Tampines", true);
	//stations.AddNewStation("EW3", "EW", "asdas", true);
	//stations.AddNewStation("EW12", "EW", "edwin", true);
	//stations.AddNewStation("EW21", "EW", "Ben", true);
	//stations.AddNewStation("CG", "CG", "kl", true);
	//stations.AddNewStation("CG1", "CG", "jacky", true);
	//stations.AddNewStation("CG2", "CG", "ryan", true);
	////stations.AddNewStation("NS1", "NS" ,"CCK", true);
	//stations.DisplayAllStations("CG");
	//stations.DisplayAllStations("EW");

	////==================Read all the files first===============================
	////reads the fare file and saving the data into an array
	//ifstream ip("Fares.csv");
	//if (!ip.is_open())
	//	cout << "Error: File Open" << "\n";
	//string fare;
	//string fare_distance;
	//float fareArray[20][2];
	//int i = 0;
	////initialise an array and store the fare and fare_distance
	//while (ip.good())
	//{
	//	getline(ip, fare_distance, ',');
	//	getline(ip, fare, '\n');
	//	float distance = stof(fare_distance);
	//	float fares = stof(fare);
	//	fareArray[i][i] = distance;
	//	fareArray[i][i + 1] = fares;
	//	cout << fareArray[i][i] << " " << fareArray[i][i + 1] << "\n";
	//	i++;
	//	//cout << "The fare distance is " << distance << "KM based on the price " << fares << "cents" << "\n";
	//}
	//ip.close();
	//-----------------------------------------------------------------------

	//read the station interchange data and save the data somewhere [not done: save it somewhere, should be stored as array]
	ifstream lp("Interchanges.csv");
	if (!lp.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string station_code1;
	string station_code2;
	string interchangeArray[35][2];
	int i = 0;
	while (lp.good())
	{
		getline(lp, station_code1, ',');
		getline(lp, station_code2, '\n');
		interchangeArray[i][i] = station_code1;
		interchangeArray[i][i+1] = station_code2;
		i++;
	}
	lp.close();

	//-----------------------------------------------------------------------
	//read the station information data and save the data somewhere [not done: save the station somewhere]
	ifstream op("Stations.csv");
	if (!op.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string station_code;
	string station_name;
	string stationcodeArray[20]; //use this array to check whether it is a duplicate line
	int a = 0;
	while (op.good())
	{
		getline(op, station_code, ',');
		string linecode;
		bool interchange = false;
		//splits the station code from eg. "EW2" to "EW" and add to stationcodeArray which is used to check the station
		for (int i = 0; i < station_code.length(); i++)
		{
			if (!isdigit(station_code[i]))
			{
				linecode += station_code[i];
			}
			//after reaching the last character of the stationcode 
			if (i == station_code.length()-1)
			{
				//check through the list of stationcodeArray
				for (int i = 0; i < sizeof(stationcodeArray); i++)
				{
					if (stationcodeArray[i] == linecode)
					{
						break;
					}
					else
					{
						line.Addlines(linecode);
						stationcodeArray[a] = linecode;
						break;
					}
				}

			}
		}
		getline(op, station_name, '\n');
		for (int i = 0; i < sizeof(interchangeArray); i++)
		{
			if (interchangeArray[i][i] == station_code || interchangeArray[i][i + 1] == station_code)
			{
				interchange = true;
			}
		}
		stations.AddNewStation(station_code, linecode, station_name, interchange);
		a++; //increment the a value 
	}
	op.close();
	//-----------------------------------------------------------------------


	////read the station interchange data and save the data somewhere [not done: save it somewhere, how to read the file using while loop]
	//ifstream xp("Routes.csv");
	//if (!xp.is_open())
	//{
	//	cout << "Error: File Open" << "\n";
	//}
	//string input;
	//string station_route;
	//string distance;
	//while (getline(xp, input, ','))
	//{

	//	if (!getline(xp, input, '\n'))
	//	{
	//		station_route = input;
	//		cout << station_route << "\n";
	//	}
	//	cout << "Station Code: " << station_code << "\n";
	//}
	//xp.close();
	////-----------------------------------------------------------------------

	////==================Display menu functions===============================
	int option = -1;
	while (option != 0)
	{
		displayMenu();
		cin >> option;

		if (option == 1)	// display all mrt station based on the given mrt line
		{
			line.DisplayAllLines();
			cout << "Enter a station line to list out all the station name: ";
			cin >> l;
			string lineinput;
			for (int i = 0; i < l.length(); i++)
			{
				lineinput += toupper(l[i]);;
			}
			stations.DisplayAllStations(lineinput);
		}
		else
		{
			if (option == 2)	// display station information based on the station name given
			{
				line.DisplayAllLines();
				cout << "Enter a station line to list out all the station name:";
				cin >> l;
				string lineinput;
				for (int i = 0; i < l.length(); i++)
				{
					lineinput += toupper(l[i]);;
				}
				stations.DisplayAllStations(lineinput);
				string target;
				cout << "Enter a station name to display its information:";
				getline(cin, target);
				stations.DisplayStationInfo(target);
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