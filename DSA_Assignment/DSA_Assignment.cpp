// DSA_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //reads the fare file and saving the data into an array
	ifstream ip("Fares.csv");
	if (!ip.is_open())
		cout << "Error: File Open" << "\n";
	string fare;
	string fare_distance;
	
	while (ip.good())
	{
		getline(ip, fare, ',');
		getline(ip, fare_distance, '\n');
	}

	//read the station file and save the data somewhere
	ifstream ip("Stations.csv");
	if (!ip.is_open())
	{
		cout << "Error: File Open" << "\n";
	}
	string station_code;
	string station_name;
	while (ip.good())
	{
		getline 
	}
}