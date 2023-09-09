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

class CircularLinkedList
{
private:
	Node* head;
	Node* current;
	int size;
public:
	CircularLinkedList()
	{
		head = NULL;
		current = NULL;
		size = NULL;
	}
	void insert(int data)
	{
		Node* newNode = new Node;
		if (head == NULL) // If List is empty
		{
			head = newNode;
			newNode->setData(data);
			newNode->setNext(head);
		}
		else // If list is not empty
		{
			newNode->setNext(current->getNext());
			current->setNext(newNode);
			newNode->setData(data);
		}
		current = newNode;
		size++;
	}
	void remove()
	{
		Node* temp = head;
		while (temp->getNext() != current)
		{
			temp = temp->getNext();
		}
		temp->setNext(current->getNext());
		delete current;
		current = temp;
		temp = NULL;
		size--;
	}
	void sortAscend()
	{
		Node* temp1 = NULL;
		Node* temp2 = NULL;
		for (int i = 0; i < size; i++)
		{
			temp1 = head;
			temp2 = head->getNext();
			do
			{
				if (temp1->getData() > temp2->getData())
				{
					int temp = temp1->getData();
					temp1->setData(temp2->getData());
					temp2->setData(temp);
				}
				temp1 = temp1->getNext();
				temp2 = temp2->getNext();
			} while (temp2 != head);
		}
	}
	void sortDescend()
	{
		Node* temp1 = NULL;
		Node* temp2 = NULL;
		for (int i = 0; i < size; i++)
		{
			temp1 = head;
			temp2 = head->getNext();
			do
			{
				if (temp1->getData() < temp2->getData())
				{
					int temp = temp1->getData();
					temp1->setData(temp2->getData());
					temp2->setData(temp);
				}
				temp1 = temp1->getNext();
				temp2 = temp2->getNext();
			} while (temp2 != head);
		}
	}
	void printList()
	{
		Node* temp = head;
		cout << "\nCircular Linked List : [ ";
		do
		{
			cout << temp->getData() << " ";
			temp = temp->getNext();
		}while (temp != head);
		cout << "]";
	}
};
int main()
{
	CircularLinkedList c;
	c.insert(4);
	c.insert(6);
	c.insert(9);
	c.insert(3);
	c.insert(8);
	c.printList();
	c.sortAscend();
	c.printList();
	c.sortDescend();
	c.printList();
	return 0;
}