#include<iostream>
using namespace std;
class Node
{
private:
	int data;
	Node* next;
public:
	Node() // Default Constructor
	{
		data = NULL;
		next = NULL;
	}
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	int getData()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
};

class Stack
{
private:
	Node* head;
	int size;
public:
	Stack() // Default Constructor
	{
		head = NULL;
		size = 0;
	}
	bool isEmpty()
	{
		return (head == NULL && size == 0);

	}
	void push(int data)
	{
		Node* newNode = new Node;
		if (head == NULL)
		{
			head = newNode;
			newNode->setNext(NULL);
			newNode->setData(data);
		}
		else
		{
			newNode->setNext(head);
			head = newNode;
			newNode->setData(data);
		}
		++size;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "\nStack underflow\n";
		}
		else
		{
			cout << "\n~Element " << head->getData() << " removed from Stack successfully.\n";
			Node* temp = head;
			head = head->getNext();
			delete temp;
			temp = NULL;
			size--;
		}
	}
	int top()
	{
		return head->getData();
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "\nStack is already empty.\n";
		}
		else
		{
			Node* temp = head;
			cout << "\n     ~( Stack )~";
			cout << "\n\n\t-----\n";
			while (temp != NULL)
			{
				cout << "\t| " << temp->getData() << " |\n";
				cout << "\t-----\n";
				temp = temp->getNext();
			}
		}
		
	}

};
int main()
{
	Stack s1;
	int userCommand; int data;
	cout << "\t-Welcome to My Stack-" << endl;
	while (true)
	{
		cout << "\n1.Add Element\n2.Remove Element\n3.Display Stack\n4.Exit\n";
		while (cout << "\nEnter the Desired Option : " && !(cin >> userCommand))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
		}
		// ****************************** ADD ELEMENT **************************
		if (userCommand == 1)
		{
			while (cout << "\nEnter the Element : " && !(cin >> data))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
			}
			s1.push(data);

		}
		// ****************************** REMOVE ELEMENT **************************
		else if (userCommand == 2)
		{
			s1.pop();
		}
		// ****************************** DISPLAY STACK **************************
		else if (userCommand == 3)
		{
			s1.display();
		}
		// ****************************** EXIT **************************
		else if (userCommand == 4)
		{
			cout << "\n~ Exiting.\n";
			break;
		}
		// ****************************** INVALID INPUT **************************
		else
		{
			cout << "\n~ Invalid Input! Please Input Again...\n";
			continue;
		}
	}
	return 0;
}