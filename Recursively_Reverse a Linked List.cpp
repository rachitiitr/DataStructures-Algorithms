#include<bits/stdc++.h>
using namespace std;

node* recReverse(node*head) {
	// Time Complexity O(N2)
	// Space Complexity O(N) for recursion stack




	// smallest linked list
	if (head->next == NULL or head == NULL) {
		return head;
	}

	// recursive case
	node* shead = recReverse(head->next);

	node* temp = shead;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	head->next = NULL;
	temp->next = head;
	// retuning the head of the reversed linked list
	return shead;

}

node* recReverse_optimised(node*head) {
	// Time Complexity O(N)
	// Space Complexity O(N) for recursion stack




	// smallest linked list
	if (head->next == NULL or head == NULL) {
		return head;
	}

	// recursive case
	node* shead = recReverse(head->next);

	node* temp = head->next;
	head->next->next = head;
	head->next = NULL;

	// retuning the head of the reversed linked list
	return shead;

}
