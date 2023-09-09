#include<iostream>
using namespace std;

class Queue
{
private:
	int* data;
	int noOfElements;
	int front;
	int rear;
	int size;
public: 
	Queue()
	{
		size = 10;
		data = new int[size];
		noOfElements = 0;
		front = 0;
		rear = 0;
	}
	bool isEmpty()
	{
		return(noOfElements == 0);
	}
	bool isFull()
	{
		return(noOfElements == size);
	}
	void enqueue(int data)
	{
		if (isEmpty())
		{
			this->data[front] = data;
			noOfElements++;
		}
		else if(!isFull())
		{
			rear = (rear + 1) % size;
			this->data[rear] = data;
			noOfElements++;

		}
		else
		{
			cout << "\nCannnot enqueue as Queue is Full." << endl;
		}
	}
	int dequeue()
	{
		if (!isEmpty())
		{
			front = (front + 1) % size;
			int temp = data[front];
			data[front] = NULL;
			noOfElements--;
			return temp;
		}
		else
		{
			cout << "\nCannot dequeue as Queue is Empty." << endl;
		}
	}
	int getFront()
	{
		return data[front];
	}
	int getRear()
	{
		return data[rear];
	}
	void display()
	{
		if (!isEmpty())
		{
			int temp = front;
			cout << "\nQueue : | ";
			for (int i = 0; i < noOfElements; i++)
			{

				cout << data[temp] << " | ";
				temp = (temp + 1) % size;
			}
			cout << "\n";
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
	cout << "\t- W E L C O M E    T O    M Y    Q U E U E    U S I N G    A R R A Y -" << endl;
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