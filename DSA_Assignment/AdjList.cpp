#include "pch.h"
#include "AdjList.h"

void display_AdjList(adjNode* ptr, int i)
{
	while (ptr != nullptr) {
		cout << "(" << i << ", " << ptr->val
			<< ", " << ptr->cost << ") ";
		ptr = ptr->next;
	}
	cout << endl;
}