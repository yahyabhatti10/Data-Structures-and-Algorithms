#include<iostream>
using namespace std;

#define size 10 // Defined the Max Size for Stack

class Stack
{
private: 
	int topOfStack;
	int noOfElements;
	int stack[size];
public:
	Stack() // Default Constructor
	{
		topOfStack = -1;
		noOfElements = NULL;
		stack[size-1] = NULL;
	}
	bool isEmpty() // Checks if Stack is Empty or not.
	{
		return (topOfStack == -1);
	}
	bool isFull() // Checks if Stack is full or not 
	{
		return (topOfStack == size - 1);
	}
	void push(int data) // Add new Element in Stack that is on topOfStack of the Stack
	{
		if (isFull())
		{
			cout << "\n~ Stack Overflow.\n";
		}
		else
		{
			++topOfStack;
			stack[topOfStack] = data;
			cout << "\n~ Element "<<data<<" added successfully in Stack.\n";
		}
	}
	void pop() // Removes the Element from Stack that is from top of the Stack
	{
		if (isEmpty())
		{
			cout << "\n~ Stack Underflow.\n";
		}
		else
		{
			cout << "\n~ Element " << top() << " removed successfully from the Stack\n";
			stack[topOfStack] = NULL;
			topOfStack--;
		}
	}
	int top() // Returns the Top most element present in the Stack
	{
		return stack[topOfStack];
	}
	void display() // Displays the whole Stack
	{
		if (topOfStack == -1)
		{
			cout << "\n~ Stack is Empty.\n";
		}
		else
		{
			int current = topOfStack;
			cout << "\n     ~( Stack )~";
			cout << "\n\n\t-----\n";
			while (current >= 0)
			{
				cout << "\t| " << stack[current] << " |\n";
				cout << "\t-----\n";
				current--;
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