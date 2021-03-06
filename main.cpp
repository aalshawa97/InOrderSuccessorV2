//Abdullah Mutaz Alshawa
// Binary search tree inorder successor
//12/3/2021
#include <iostream>
using namespace std;

/*
* A binary tree node has data,
* the pointer to left child and a 
* pointer to right child
*/
struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
};
struct node* newNode(int data);

void inOrderTraversal(struct node* root, struct node* n, struct node* succ)
{
	if (root == nullptr)
	{
		return;
	}
	inOrderTraversal(root->left, n, succ);
	if (root->data > n->data && !succ->left)
	{
		succ->left = root;
		return;
	}
	inOrderTraversal(root->right, n, succ);
}

struct node* inOrderSuccessor(struct node* root, struct node* n)
{
	struct node* succ = newNode(0);
	inOrderTraversal(root, n, succ);
	return succ->left;
}

/*
* Helper function that allocates a new node with 
* the given data and NULL left and right pointers.
*/
struct node* newNode(int data)
{
	struct node* node = (struct node*)
	malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return (node);
}

/*
* Give a binary search tree and a number, inserts
* a new node with the given number in the correct
* place in the tree. Returns the new root pointer
* which the caller should then use (the standard trick to avoid using reference parameters). 
*/
struct node* insert(struct node* node, int data)
{
	//If the tree is empty, return a new, single node
	if (node == NULL)
	{
		return (newNode(data));
	}
	else
	{
		struct node* temp;

		//Otherwise, recurse down the tree
		if (data <= node->data)
		{
			temp = insert(node->left, data);
			node->left = temp;
			temp->parent = node;
		}
		else
		{
			temp = insert(node->right, data);
			node->right = temp;
			temp->parent = node;
		}
		//Return the (unchanged) node pointer
		return node;
	}
}

	// Driver code
	int main()
	{
		struct node* root = NULL, * temp, * succ, * min;

		// Creating the tree given in the above diagram
		root = insert(root, 20);
		root = insert(root, 8);
		root = insert(root, 22);
		root = insert(root, 4);
		root = insert(root, 12);
		root = insert(root, 10);
		root = insert(root, 14);
		temp = root->left->right->right;

		// Function Call
		succ = inOrderSuccessor(root, temp);
		if (succ != NULL)
			cout << "\n Inorder Successor of "
			<< temp->data << " is " << succ->data;
		else
			cout << "\n Inorder Successor doesn't exist";

		//getchar();
		return 0;
	}
