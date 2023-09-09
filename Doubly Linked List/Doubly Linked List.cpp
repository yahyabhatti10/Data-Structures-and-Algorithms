#include<iostream>
using namespace std;
//															-----------------------------------			
// **********************************************	               C L A S S    N O D E 			      **********************************************
//															-----------------------------------
class Node
{
private: 
	Node* prev;
	int data;
	Node* next;
public:
	Node() // Default Constructor
	{
		prev = NULL;
		data = NULL;
		next = NULL;
	}
	void setPrev(Node* prev)
	{
		this->prev = prev;
	}
	void setData(int data)
	{
		this->data = data;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	Node* getPrev()
	{
		return prev;
	}
	Node* getNext()
	{
		return next;
	}
	int getData()
	{
		return data;
	}
};
//											      --------------------------------------------------------			
// **********************************************	 C L A S S    D O U B L Y    L I N K E D    L I S T    **********************************************
//												  --------------------------------------------------------
class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	Node* current;
	int size;
public:
	DoublyLinkedList() // Default Constructor
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		size = NULL;
	}
	// ************* ADDING THE NODE *************
	void addNode(int data,int position)
	{
		Node* newNode = new Node;
		if (head == NULL && tail == NULL) // If List is empty and Insertion of First Element of the List
		{
			head = newNode;
			newNode->setPrev(NULL);
			newNode->setNext(NULL);
			newNode->setData(data);
			tail = newNode;
		}
		else if (head == tail) // If there is only one Node in the List; Head and tail are same.
		{
			head->setNext(newNode);
			newNode->setNext(NULL);
			newNode->setPrev(head);
			newNode->setData(data);
			tail = newNode;
		}
		else
		{
			if (position == 1) // If Inserion is at Start of the List
			{
				head->setPrev(newNode);
				newNode->setNext(head);
				newNode->setPrev(NULL);
				newNode->setData(data);
				head = newNode;
			}
			else if (position == 2) // If Insertion is at Current Location of the List
			{
				if (current == head)
				{
					head = newNode;
					newNode->setNext(current);
					current->setPrev(newNode);
					newNode->setPrev(NULL);
					newNode->setData(data);
				}
				else if (current == tail)
				{
					tail = newNode;
					newNode->setNext(NULL);
					current->setNext(newNode);
					newNode->setPrev(current);
					newNode->setData(data);
				}
				else
				{
					newNode->setPrev(current->getPrev());
					current->getPrev()->setNext(newNode);
					current->setPrev(newNode);
					newNode->setNext(current);
					newNode->setData(data);
				}
			}
			else if (position == 3) // If Insertion is at the End of the List
			{
				tail->setNext(newNode);
				newNode->setPrev(tail);
				newNode->setNext(NULL);
				newNode->setData(data);
				tail = newNode;
			}
		}
		current = newNode;
		size++;
	}
	// ************* REMOVING THE NODE *************
	void removeNode(int position)
	{
		Node* temp = NULL;
		if (head == NULL && tail == NULL && current == NULL) // If List is empty
		{
			cout << "\nList is already empty.\n";
		}
		else if (head == tail) // If there is only one node in the list
		{
			delete head;
			head = NULL;
			current = NULL;
			tail = NULL;
		}
		else
		{
			if (position == 1) // If deletion is at Start of the List
			{
				temp = head;
				head = head->getNext();
				head->setPrev(NULL);
				delete temp;
			}
			else if (position == 2) // If deletion is at Current Location of the List
			{
				if (current == head) 
				{
					temp = head;
					head = head->getNext();
					current = head;
					head->setPrev(NULL);
					delete temp;
				}
				else if (current == tail)
				{
					temp = tail;
					tail = tail->getPrev();
					tail->setNext(NULL);
					current = tail;
					delete temp;
				}
				else
				{
					temp = current;
					current = current->getPrev();
					current->setNext(temp->getNext());
					temp->getNext()->setPrev(current);
					delete temp;
				}
			}
			else if (position == 3) // If deletion is at End of the List
			{
				temp = tail;
				tail = tail->getPrev();
				tail->setNext(NULL);
				delete temp;
			}
		}
		size--;
	}
	// ************* MOVE TO NEXT *************
	void traverseForward()
	{
		current = current->getNext();
		if (current == NULL)
		{
			current = head;
		}
		cout << "\nCurrent Node : " << current->getData() << endl;
	}
	// ************* MOVE TO PREVIOUS *************
	void traverseBackward()
	{
		current = current->getPrev();
		if (current == NULL)
		{
			current = tail;
		}
		cout << "\nCurrent Node : " << current->getData() << endl;
	}
	// ************* PRINTING THE LIST *************
	void printList()
	{
		Node* temp = head;
		cout << "\nDoubly Linked List : [ ";
		while (temp!=NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		cout << "]\n";
	}

};
//														---------------------------------------			
// **********************************************			  M A I N     F U N C T I O N 		 	**********************************************
//														---------------------------------------	
int main()
{
	DoublyLinkedList l1;
	int choice, position, data;
	choice = position = data = NULL;
	cout << "\t- W E L C O M E    T O    M Y    D O U B L Y    L I N K E D    L I S T -" << endl;
	while (true)
	{
		cout << "\n\t\t       - O P E R A T I O N S -\n\n1.Add Node\n2.Remove Node\n3.Print List\n4.Move to Next\n5.Move to Previous\n6.Exit";
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
			l1.printList();
			cout << endl;
		}
		// ************* MOVE TO NEXT *************
		else if (choice == 4)
		{
			l1.traverseForward();
		}
		// ************* MOVE TO PREVIOUS *************
		else if (choice == 5)
		{
			l1.traverseBackward();
		}
		// ************* EXITING *************
		else if (choice == 6)
		{
			break;
		}
		// ****************************** INVALID INPUT **************************
		else
		{
			cout << "\nInvalid Input! Please Input the Valid Number.\n";
		}
	}
	return 0;
}