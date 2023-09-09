#include<iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
public:
	Node()
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

class Queue
{
private:
	Node* front;
	Node* rear;
	int noOfElements;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		noOfElements = 0;
	}
	bool isEmpty()
	{
		return(noOfElements == 0);
	}
	void enqueue(int data)
	{
		Node* newNode = new Node;
		newNode->setData(data);
		newNode->setNext(NULL);
		if (isEmpty())
		{
			rear = newNode;
			front = newNode;
		}
		else
			rear->setNext(newNode);
		rear = newNode;
		noOfElements++;
	}
	void dequeue()
	{
		if (!isEmpty())
		{
			Node* temp = front;
			front = front->getNext();
			delete temp;
			temp = NULL;
			noOfElements--;
		}
		else
		{
			cout << "\nCannot dequeue as Queue is Empty." << endl;
		}
		
	}
	int getFront()
	{
		return front->getData();
	}
	int getRear()
	{
		return rear->getData();
	}
	void display()
	{
		if (!isEmpty())
		{
			Node* temp = front;
			cout << "\nQueue : | ";
			while (temp != NULL)
			{
				cout << temp->getData() << " | ";
				temp = temp->getNext();
			}
		}
		else
		{
			cout << "\nCannot display as Queue is empty\n";
		}
	}
};
int main()
{
	Queue q1;
	int userCommand, data;
	cout << "\t- W E L C O M E    T O    M Y    Q U E U E    U S I N G    L I N K E D    L I S T -" << endl;
	while (true)
	{
		cout << "\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Exit\n";
		while (cout << "\nEnter the Desired Option : " && !(cin >> userCommand))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
		}
		// ****************************** ENQUEUE **************************
		if (userCommand == 1)
		{
			while (cout << "\nEnter the Data : " && !(cin >> data))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n~ Invalid Input! Please Enter the Integer Input.\n";
			}
			q1.enqueue(data);

		}
		// ****************************** DEQUEUE **************************
		else if (userCommand == 2)
		{
			q1.dequeue();
		}
		// ****************************** DISPLAY QUEUE **************************
		else if (userCommand == 3)
		{
			q1.display();
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
		}
	}
	return 0;
}