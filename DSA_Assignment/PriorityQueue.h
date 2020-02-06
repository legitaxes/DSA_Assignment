#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
struct n // node declaration 
{
	int priority;
	int info;
	struct n *l;
};
class Priority_Queue {
private:
	//Declare a front pointer f and initialize it to NULL.
	n *f;
public:
	Priority_Queue() //constructor 
	{
		f = NULL;
	}
	void insert(int i, int priority) {
		n *t, *q;
		t = new n;
		t->info = i;
		t->priority = priority;
		if (f == NULL || priority < f->priority) {
			t->l = f;
			f = t;
		}
		else {
			q = f;
			while (q->l != NULL && q->l->priority <= priority)
				q = q->l;
			t->l = q->l;
			q->l = t;
		}
	}
	void del() {
		n *t;
		if (f == NULL) //if queue is null
			cout << "Queue Underflow\n";
		else {
			t = f;
			cout << "Deleted item is: " << t->info << endl;
			f = f->l;
			free(t);
		}
	}
	void show() //print queue
	{
		n *ptr;
		ptr = f;
		if (f == NULL)
			cout << "Queue is empty\n";
		else
		{
			cout << "Queue is :\n";
			cout << "Priority Item\n";
			while (ptr != NULL) {
				cout << ptr->priority << " " << ptr->info << endl;
				ptr = ptr->l;
			}
		}
	}
	bool empty()
	{
		if (f == NULL)
			return true;
		else
			return false;
	}
};