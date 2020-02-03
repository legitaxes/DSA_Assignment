#pragma once
#include<string>
#include<iostream>
using namespace std;

class PriorityQueue
{
private:
	struct pq
	{
		pq_object **heap;
		int capacity;
		int count;
	} pq;
}