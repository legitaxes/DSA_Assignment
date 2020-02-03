#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

#include "PriorityQueue.h"

PriorityQueue pq;

void PriorityQueue::create_pq(void)
{
	pq *p;
	pq_object **object;

	p = (pq *)malloc(sizeof(pq));
	if (p == NULL)
	{
		printf("OUT OF MEMORY!\n");
		exit(1);
	}

	object = (pq_object **)malloc(sizeof(pq_object *));
	if (object == NULL)
	{
		printf("OUT OF MEMORY!\n");
		exit(1);
	}

	p->heap = object;
	p->count = 0;
	p->capacity = 1;

	return p;
}

boolean pq_is_empty(pq *p)
{
	return((p->count == 0) ? TRUE : FALSE);
}

pq_object *find_min(pq *p)
{
	if (pq_is_empty(p) == TRUE)
	{
		printf("TRIED TO FIND A MIN-OBJECT IN AN EMPTY PRIORITY QUEUE!\n");
		exit(1);
	}

	return *(p->heap);
}