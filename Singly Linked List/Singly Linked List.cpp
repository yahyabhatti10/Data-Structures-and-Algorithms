#include<iostream>
using namespace std;
//															-----------------------------------			
// **********************************************	               C L A S S    N O D E 			      **********************************************
//															-----------------------------------
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
//													   ---------------------------------------------			
// **********************************************	        C L A S S    L I N K E D    L I S T 	      **********************************************
//													   ---------------------------------------------
class LinkedList
{
private:
	Node* head;
	Node* tail;
	Node* currentNode;
	int size;

public:
	LinkedList() // Default Constructor
	{
		head = NULL;
		tail = NULL;
		currentNode = NULL;
		size = 0;
	}
	// ************* ADDING THE NODE *************
	void addNode(int data, int position)
	{
		Node* newNode = new Node;
		if (head == NULL && tail == NULL) // If List is empty, Insertion is at the Start of the list
		{
			head = newNode;
			newNode->setData(data);
			newNode->setNext(NULL);
			tail = newNode;
		}
		else if (head == tail) // If there is one node in the list
		{
			tail = newNode;
			head->setNext(newNode);
			newNode->setNext(NULL);
			newNode->setData(data);
		}
		else if (head != NULL && tail != NULL)
		{
			if (position == 1) // If List is not empty but insertion of node is at Start of the list
			{
				newNode->setNext(head);
				newNode->setData(data);
				head = newNode;
			}
			else if (position == 2)  // If List is not empty but insertion of node is at Mid of the list
			{
				
				if (currentNode == head)
				{
					head = newNode;
					newNode->setNext(currentNode);
					currentNode->setNext(newNode);
					newNode->setData(data);
				}
				else if (currentNode == tail) 
				{
					tail = newNode;
					newNode->setNext(currentNode->getNext());
					currentNode->setNext(newNode);
					newNode->setData(data);
				}
				else
				{
					newNode->setNext(currentNode->getNext());
					currentNode->setNext(newNode);
					newNode->setData(data);
				}
				
			}
			else if (position == 3) // If List is not empty but insertion of node is at End of the list
			{
				tail->setNext(newNode);
				tail = newNode;
				newNode->setData(data);
				newNode->setNext(NULL);
			}
		}
		currentNode = newNode;
		size++;
	}

	// ************* REMOVING THE NODE *************
	void removeNode(int position)
	{
		if (head == NULL && tail == NULL)
		{
			cout << "\nList is already empty." << endl;
		}
		else if (head==tail)
		{
			delete currentNode;
			head = NULL;
			tail = NULL;
			currentNode = NULL;
		}
		else
		{
			if (position == 1) // Removing the Starting Node of List
			{
				currentNode = head;
				head = head->getNext();
				delete currentNode;
				currentNode = head;

			}
			else if (position == 2) // Removing the Current Node of List
			{
				Node* previous =  head;
				if (currentNode == head)
				{
					currentNode = previous->getNext();
					head = previous->getNext();
					delete previous;
				}
				else if (currentNode == tail)
				{
					previous = head;
					while (previous->getNext()->getNext() != NULL)
					{
						previous = previous->getNext();
					}
					delete previous->getNext();
					tail = previous;
					currentNode = previous;
					previous->setNext(NULL);
				}
				else
				{
					while (previous->getNext() != currentNode)
					{
						previous = previous->getNext();
					}
					previous->setNext(currentNode->getNext()); 
					delete currentNode;
					currentNode = previous->getNext();
				}
				
			}
			else if (position == 3) // Removing the Last Node of List
			{
				Node* secondLast = head;
				while (secondLast->getNext()->getNext() != NULL)
				{
					secondLast = secondLast->getNext();
				}
				delete secondLast->getNext();
				tail = secondLast;
				secondLast->setNext(NULL);
				currentNode = secondLast;

			}
			size--;
		}

	}
	// ************* PRINTING THE LIST *************
	void printLinkedList()
	{
		Node* temp = NULL;
		temp = head;
		cout << "\nSize of Linked List : " << size;
		cout << "\nLinked List : [ ";
		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << "]";
	}
	// ************* MOVE TO NEXT *************
	void traverse()
	{
		currentNode = currentNode->getNext();
		if (currentNode == NULL)
		{
			currentNode = head;
		}
		cout << "\nCurrent Node : " << currentNode->getData() << endl;
	}
};
//														---------------------------------------			
// **********************************************			  M A I N     F U N C T I O N 		 	**********************************************
//														---------------------------------------		
int main()
{
	LinkedList l1;
	int choice, position, data;
	choice = position = data = NULL;
	cout << "\t- W E L C O M E    T O    M Y    L I N K E D    L I S T -" << endl;
	while (true)
	{
		cout << "\n\t\t       - O P E R A T I O N S -\n\n1.Add Node\n2.Remove Node\n3.Print List\n4.Move to Next\n5.Exit";
		while (cout << "\n\nEnter the Operation you want to perform : " && !(cin >> choice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Input! Please Enter the Valid Integer Input\n";
		}
		// ************* ADDING THE NODE *************
		if (choice == 1)
		{
		positionAdd:
			cout << "\n\t\t- P O S I T I O N S    O F    N O D E -\n\n1.Start of the List\n2.Current Node of the List\n3.End of the List\n";
			while (cout << "\nEnter the Position of Node : " && !(cin >> position)) // Position of Node
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input! Please Enter the Valid Integer Input\n";
			}
			if (position < 1 || position > 3)
			{
				cout << "\nInvalid Input! Plaese Enter the valid number\n";
				goto positionAdd;
			}
			while (cout << "Enter the Number you want to add : " && !(cin >> data)) // Data inside the Node 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input! Please Enter the Valid Integer Input\n";
			}
			l1.addNode(data, position);

		}
		// ************* REMOVING THE NODE *************
		else if (choice == 2)
		{
		positionRemove:
			cout << "\n\t\t- P O S I T I O N S    O F    N O D E -\n\n1.Start of the List\n2.Current Node of the List\n3.End of the List\n";
			while (cout << "\nEnter the Position of Node : " && !(cin >> position)) // Position of Node
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nInvalid Input! Please Enter the Valid Integer Input.\n";
			}
			if (position < 1 || position>3)
			{
				cout << "\nInvalid Input! Plaese Enter the valid Number.\n";
				goto positionRemove;
			}
			l1.removeNode(position);
		}
		// ************* PRINTING THE LIST *************
		else if (choice == 3)
		{
			l1.printLinkedList();
			cout << endl;
		}
		// ************* MOVE TO NEXT *************
		else if (choice == 4)
		{
			l1.traverse();
		}
		// ************* EXITING *************
		else if (choice == 5)
		{
			break;
		}
		// ****************************** INVALID INPUT **************************
		else
		{
			cout << "\nInvalid Input! Please Input the valid Number.\n";
		}
	}
	return 0;
}