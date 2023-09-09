#include<iostream>
#include <algorithm>
using namespace std;
class Node
{
private:
	int data;
	Node* left;
	Node* right;
public:
	Node() // Default Constructor
	{
		data = NULL;
		left = NULL;
		right = NULL;
	}
	void setData(int data)
	{
		this->data = data;
	}
	void setLeft(Node* left)
	{
		this->left = left;
	}
	void setRight(Node* right)
	{
		this->right = right;
	}
	int getData()
	{
		return data;
	}
	Node* getLeft()
	{
		return left;
	}
	Node* getRight()
	{
		return right;
	}
};
class BinarySearchTree
{
private:
	Node* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	Node* insert(Node* root, int data)
	{
		if (this->root == NULL)
		{
			Node* newNode = new Node;
			newNode->setData(data);
			newNode->setLeft(NULL);
			newNode->setRight(NULL);
			this->root = newNode;
		}
		else if (root == NULL)
		{
			root = new Node;
			root->setData(data);
			root->setLeft(NULL);
			root->setRight(NULL);
		}
		else
		{
			if (root->getData() > data)
			{
				root->setLeft(insert(root->getLeft(), data));
			}
			else if (root->getData() < data)
			{
				root->setRight(insert(root->getRight(), data));
			}
		}
		return root;
	}
	Node* minValueNode(Node* root)
	{
		Node* current = root;
		while (current->getLeft() != NULL)
			current = current->getLeft();
		return current;
	}
	Node* maxValueNode(Node* root)
	{
		Node* current = root;
		while (current->getRight() != NULL)
			current = current->getRight();
		return current;
	}
	Node* remove(Node* root, int data)
	{
		if (root == NULL)
			return root;
		else if (data < root->getData())
			root->setLeft(remove(root->getLeft(), data));
		else if (data > root->getData())
			root->setRight(remove(root->getRight(), data));
		else
		{
			if (root->getLeft() == NULL)
			{
				Node* temp = root->getRight();
				delete root;
				return temp;
			}
			else if (root->getRight() == NULL)
			{
				Node* temp = root->getLeft();
				delete root;
				return temp;
			}
			else
			{
				Node* temp = minValueNode(root->getRight());
				root->setData(temp->getData());
				root->setRight(remove(root->getRight(), temp->getData()));
			}
			return root;
		}

	}
	int height(Node* root)
	{
		if (root == NULL)
			return -1;
		int left = height(root->getLeft());
		int right = height(root->getRight());
		return max(left, right) + 1;
	}
	int depth(Node* root)
	{
		if (root == NULL)
			return 0;
		int left = depth(root->getLeft());
		int right = depth(root->getRight());
		return max(left, right) + 1;
	}
	void displayPreorder(Node* root)
	{
		if (root != NULL)
		{
			cout << root->getData() << " ";
			displayPreorder(root->getLeft());
			displayPreorder(root->getRight());
		}
	}
	void displayInorder(Node* root)
	{
		if (root != NULL)
		{
			displayInorder(root->getLeft());
			cout << root->getData() << " ";
			displayInorder(root->getRight());
		}
	}
	void displayPostorder(Node* root)
	{
		if (root != NULL)
		{
			displayPostorder(root->getLeft());
			displayPostorder(root->getRight());
			cout << root->getData() << " ";
		}
	}
	Node* getRoot()
	{
		return root;
	}
};
int main()
{
	BinarySearchTree t1;
	int userCommand, data;
	cout << "\t- B I N A R Y    S E A R C H    T R E E  -" << endl;
	while (true)
	{
		cout << "\n1.Insert Node\n2.Remove Node\n3.Depth\n4.Height\n5.Preorder Display\n6.Inorder Display\n7.Postorder Display\n8.Exit\n";
		while (cout << "\nEnter the Desired Option : " && !(cin >> userCommand))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
		}
		// ****************************** INSERT **************************
		if (userCommand == 1)
		{
			while (cout << "\nEnter the Data : " && !(cin >> data))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
			}
			t1.insert(t1.getRoot(), data);

		}
		// ****************************** REMOVE **************************
		else if (userCommand == 2)
		{
			while (cout << "\nEnter the Data : " && !(cin >> data))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
			}
			t1.remove(t1.getRoot(), data);

		}
		// ****************************** DEPTH **************************
		else if (userCommand == 3)
		{
			cout << "\nDepth : " << t1.depth(t1.getRoot()) << endl;
		}
		// ****************************** HEIGHT **************************
		else if (userCommand == 4)
		{
			cout << "\nHeight : " << t1.height(t1.getRoot()) << endl;
		}
		// ****************************** PREORDER **************************
		else if (userCommand == 5)
		{
			t1.displayPreorder(t1.getRoot());
		}
		// ****************************** INORDER **************************
		else if (userCommand == 6)
		{
			t1.displayInorder(t1.getRoot());
		}
		// ****************************** POSTORDER **************************
		else if (userCommand == 7)
		{
			t1.displayPostorder(t1.getRoot());
		}
		// ****************************** EXIT **************************
		else if (userCommand == 8)
		{
			cout << "\n~ Exiting.\n";
			break;
		}
		// ****************************** INVALID INPUT **************************
		else
		{
			cout << "\n~ Invalid Input! Please Input Again...\n";
		}
	}
	return 0;
}