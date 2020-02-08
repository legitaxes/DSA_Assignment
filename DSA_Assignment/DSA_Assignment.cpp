// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//if a station has > 2 station code == interchange
#include "Dictionary.h"
#include "pch.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <array>


using namespace std;

void displayMenu();

int main()
{
	//initialize the program with the 2 dictionary...
	DictionaryCode line;
	DictionaryStation stations;

	//create the necessary variables for the program...
	ItemType l;
	ItemType target;
	int vertices, edges, weight;
	string v1, v2;


	//==================Read all the files first===============================
	//reads the fare file and saving the data into an array
	ifstream ip("Fares.csv");
	if (!ip.is_open())
		cout << "Error: File Open" << "\n";
	ItemType fare;
	ItemType fare_distance;
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
		//cout << fareArray[i][i] << " " << fareArray[i][i + 1] << "\n";
		i++;
		//cout << "The fare distance is " << distance << "KM based on the price " << fares << "cents" << "\n";
	}
	ip.close();
	//-----------------------------------------------------------------------

	//-----------------------------------------------------------------------
	//read the station information data and save the data somewhere [not done: save the station somewhere]
	ifstream op("Stations.csv");
	if (!op.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	ItemType station_code;
	ItemType station_name;
	int a = 0;
	unordered_map<ItemType, vector<ItemType>> stationsmap;
	while (op.good())
	{
		getline(op, station_code, ',');

		ItemType linecode;
		//splits the station code from eg. "EW2" to "EW" and add to stationcodeArray which is used to check the station
		for (int i = 0; i < station_code.length(); i++)
		{
			if (!isdigit(station_code[i]))
			{
				linecode += station_code[i];
			}
		}
		line.Addlines(linecode);
		getline(op, station_name, '\n');
		auto station_codesearch = stationsmap.find(station_name);

		if (station_codesearch != stationsmap.end())
		{
			stationsmap.at(station_name).push_back(station_code);
		}
		else
		{
			vector<ItemType> station_codeli;
			station_codeli.push_back(station_code);
			stationsmap.insert({ station_name, station_codeli });
		}
	}
	op.close();
	//add the station to the dictionary
	for (auto it : stationsmap)
	{
		for (int i = 0; i < it.second.size(); i++)
		{
			
			if (it.second.size() == 1)
			{
				stations.AddNewStation(it.second[i], it.first, false);
			}
			else
			{
				stations.AddNewStation(it.second[i], it.first, true);
			}
			
		}
	}

	//-----------------------------------------------------------------------


	//read the station interchange data and save the data somewhere [not done: save it somewhere, how to read the file using while loop]
	ifstream xp("Routes.csv");
	if (!xp.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	ItemType input;
	ItemType station_route;
	ItemType distance;
	vector<string> stationroutelist;
	vector<int> distancelist;
	while (xp.good())
	{
		//first iteration will read the first line and the second line of the file
		//gets current line's station routes and store it in one string
		getline(xp, station_route);
		stringstream ss(station_route);
		while(ss.good()) 
		{
			ItemType substation;
			getline(ss, substation, ',');
			while (ss.good())
			{
				stationroutelist.push_back(substation);
			}
			//changes the whole of station code to numbers to store it inside a vector which will be used for vertexes
		}

		//gets the distance for the station routes above
		getline(xp, distance);
		stringstream dd(distance);
		for (int i; dd >> i;) {
			distancelist.push_back(i);
			if (dd.peek() == ',')
				dd.ignore();
		}
	}
	//initialize the number of vertices and edges by counting the size of the list
	vertices = stationroutelist.size();
	edges = distancelist.size();
	//create an unordered map to map all of the above information to the vertices
	// Adjacency List is a map of <string, list>.
	// Where each element in the list is pair<string, int>
	// pair.first -> the edge's destination (string)
	// pair.second -> edge's weight
	unordered_map< string, list< pair<string, int> > > adjacencyList(vertices + 1);
	for (int i = 1; i <= edges; ++i)
	{
		for (int i = 0; i < vertices; i++)
		{
			adjacencyList[stationroutelist[i]].push_back(make_pair(stationroutelist[i+1], distancelist[i]));
		}
	}
	for (auto& value : adjacencyList)
	{
		string vertex = value.first;
		list< pair<string, int> > adjacentVertices = value.second;
		list< pair<string, int> >::iterator itr = adjacentVertices.begin();
		cout << "adjacencyList[" << vertex << "]";
		while (itr != adjacentVertices.end()) {
			cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
			++itr;
		}
	}
	//for (int i = 0; i < stationroutelist.size(); i++)
	//{
	//	cout << stationroutelist[i] << endl;
	//}

	//for (int i = 0; i < distancelist.size(); i++)
	//{
	//	cout << distancelist[i] << endl;
	//}
	xp.close();
	//-----------------------------------------------------------------------

	////==================Display menu functions===============================
	int option = -1;
	while (option != 0)
	{
		displayMenu();
		cin >> option;

		if (option == 1)	// display all mrt station based on the given mrt line by user input
		{
			line.DisplayAllLines();
			cout << "\nEnter a station line to list out all the station name: ";
			cin >> l;
			ItemType lineinput;
			for (int i = 0; i < l.length(); i++)
			{
				lineinput += toupper(l[i]);;
			}
			stations.DisplayAllStations(lineinput);
		}
		else
		{
			if (option == 2)	// display station information based on the station name given by user input
			{
				cout << "Enter a station name to display its information:";
				cin.ignore();
				getline(cin, target);
				
				stations.DisplayStationInfo(target);
			}
			else
				if (option == 3)	// Add and save a new station on a given line;
				{
					string lineinput; // user input of the MRT line to be added
					string stationcode;
					string stationname;
					char interchange;
					line.DisplayAllLines();
					cout << "\nChoose a station line to add a new station to: ";
					cin >> l;
					for (int i = 0; i < l.length(); i++)
					{
						lineinput += toupper(l[i]);;
					}
					stations.DisplayAllStations(lineinput);
					cout << "\nStation Code: ";
					cin >> l;
					for (int i = 0; i < l.length(); i++)
					{
						stationcode += toupper(l[i]);;
					}
					cout << "\nStation Name: ";
					cin.ignore();
					getline(cin, stationname);
					cout << "\nInterchange?(Y/N): ";
					cin >> interchange;
					toupper(interchange);
					if (interchange == 'Y')
					{
						stations.AddNewStation(stationcode, stationname, true);
					}
					else
					{
						stations.AddNewStation(stationcode, stationname, false);
					}
					cout << "The new station has been added to the line.";
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
	cout << "==============================================================================================" << endl;
	cout << "=====================================MRT STATION==============================================" << endl;
	cout << "==============================================================================================" << endl;

	cout << "[1] Display all the stations in a given line\n";
	cout << "[2] Display station information for a given name \n";
	cout << "[3] Add and Save a new station on a given MRT line \n";
	cout << "[4] Find and display a route and price based on source and destination stations\n";
	cout << "==============================================================================================" << endl;
	cout << "[5] Add a new line [ADV] \n";
	cout << "[6] Search for Shortest Route and its Price [ADV] \n";
	//cout << "[7] Display 3 possible routes with price and distance [ADV] \n";
	cout << "[0] Exit \n";
	cout << "==============================================================================================" << endl;
	cout << "Enter option : ";
}