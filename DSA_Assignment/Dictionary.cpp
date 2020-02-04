#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include<cmath>
//#include <bits/stdc++.h>
using namespace std;
#include "Dictionary.h"

DictionaryCode::DictionaryCode() { size = 0; }

DictionaryCode::~DictionaryCode() {}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int) 'A';
		else
			return (int)c - (int) 'a' + 26;
	}
	else
		return -1;
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
	cout << total;
	return total;
}