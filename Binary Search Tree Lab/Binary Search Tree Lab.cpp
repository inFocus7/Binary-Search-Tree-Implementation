#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class node
{
public:
	string data;
	node* left;
	node* right;
	int count;

	node(string x)
	{
		data = x;
		left = NULL;
		right = NULL;
		count = 1;
	}
};

class binarySearchTree
{
public:
	node* root;

	binarySearchTree()
	{
		root = NULL;
	}

	//insert x into tree rooted
	//at node pointer p.
	void recInsert(node* &p, string x)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else if (p != NULL && x != p->data) //did this to not make duplicates in the tree
		{
			if (x < p->data)
			{
				recInsert(p->left, x);
			}
			else // x >= p->data
			{
				recInsert(p->right, x);
			}
		}
		else if (p != NULL && x == p->data)
			p->count++;
	}

	void insert(string x)
	{
		recInsert(root, x);
	}

	//an in-order tree traversal
	void recDisplay(node* p, ofstream &output)
	{
		if (p == NULL)
		{
			//ha! nothing to do in this 
			//easy easy easy base case!!
			//SAving tons of time not coding
			//because its so simple!!!!
		}
		else
		{
			recDisplay(p->left, output);
			output << p->data << ": " << p->count << endl;
			recDisplay(p->right, output);
		}
	}

	void display(ofstream &output)
	{
		recDisplay(root, output);
	}
};

int main()
{
	binarySearchTree tree;
	//1) Open File
	ifstream theFile;
	theFile.open("tlp.txt");
	string aWord, theWord;
	//2) Read File Words & Put Them Into Tree
	//if (tree.root == NULL)
	//{
	//	theFile >> aWord;
	//	tree.recInsert(tree.root, aWord);
	//}
	while (theFile >> aWord)
		tree.insert(aWord); //inserts word using bst's insert function.
	theFile.close();

	ofstream output;
	output.open("output.txt");
	tree.display(output);
	output.close();

	return 0;
}