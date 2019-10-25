/* C/C++ program to flip a binary tree */
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node structure */
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

/* Utility function to create a new Binary 
Tree Node */
struct Node* newNode(int data) 
{ 
	struct Node *temp = new struct Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// method to flip the binary tree 
Node* flipBinaryTree(Node* root) 
{ 
	// Base cases 
	if (root == NULL) 
		return root; 
	if (root->left == NULL && root->right == NULL) 
		return root; 

	// recursively call the same method 
	Node* flippedRoot = flipBinaryTree(root->left); 

	// rearranging main root Node after returning 
	// from recursive call 
	root->left->left = root->right; 
	root->left->right = root; 
	root->left = root->right = NULL; 

	return flippedRoot; 
} 

// Iterative method to do level order traversal 
// line by line 
void printLevelOrder(Node *root) 
{ 
	// Base Case 
	if (root == NULL) return; 

	// Create an empty queue for level order traversal 
	queue<Node *> q; 

	// Enqueue Root and initialize height 
	q.push(root); 

	while (1) 
	{ 
		// nodeCount (queue size) indicates number 
		// of nodes at current lelvel. 
		int nodeCount = q.size(); 
		if (nodeCount == 0) 
			break; 

		// Dequeue all nodes of current level and 
		// Enqueue all nodes of next level 
		while (nodeCount > 0) 
		{ 
			Node *node = q.front(); 
			cout << node->data << " "; 
			q.pop(); 
			if (node->left != NULL) 
				q.push(node->left); 
			if (node->right != NULL) 
				q.push(node->right); 
			nodeCount--; 
		} 
		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->right->left = newNode(4); 
	root->right->right = newNode(5); 

	cout << "Level order traversal of given tree\n"; 
	printLevelOrder(root); 

	root = flipBinaryTree(root); 

	cout << "\nLevel order traversal of the flipped"
			" tree\n"; 
	printLevelOrder(root); 
	return 0; 
} 
