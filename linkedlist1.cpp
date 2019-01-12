//load the library
#include<iostream>
//using namespace
using namespace std;
class Node{
	public:
	// Data
	int data;
	// Pointer to the next Node
	Node *next;
	//Constructor that makes the ptr to NULL
	Node()
	{
    next = NULL;
    }
};
class LinkedList{
	//Head + circles inside links with each other
	public:
    //Head -> Node is the type of ptr
	Node *head;
	Node *tail;
    //Constructor to make head to NULL
	LinkedList()
	{
    head = NULL;
    tail = NULL;
	}
	//Circles arelinked with each other
	//Insert
    // defining a function that inserts node at the last
    void insert(int value)
	{
    //may the 1st node be added
    Node *temp = new Node;  //Node object created in heap whose address is stored in temp pointer
		                        //Basically creates a circle of linked list
		                        //temp stores memory address of new node inserted

		temp->data = value;    //inserts value to the created circle

		//Now this has to be included into the linked list so that the  head has to be made as first element of linked list)
		//1st node only
		if(head == NULL)          //inserting 1st node
		{
        head = temp;
		}
        //Any other node
		else
		{
        tail->next = temp;      //linking the  last node to the new node
		}
        tail = temp;                       //points tail pointer to the new node(since it is now the last node of the LL)
		cout<<endl;
    }
    //Deletion
    //deletes the last element
    void deletion()
	{//store the tail in temp
		Node *temp = tail;
		//node before tail has to point to NULL
		//using head
		Node *current = head;
		while(current->next != tail) // stop current upto node just before tail
		{
         current = current->next;
		}
         current->next = NULL; //this is last node and the next node can be deleted
        // tail
		tail = current; //tail now points to the last node and the next node is inaccessible
		//delete temp
		delete temp; //the next node gets deleted from the heap
		cout<<endl;
	}
     //inserts node at a specific place and not in the last necessarily
	void insertAt(int pos,int value)
	{//To add node at the position of the header
		if(pos == 1)
		{//create a new node
			Node *temp = new Node;
			//assign the entered value as data to the new node
			temp->data = value;
			//link the new node to head
			temp->next = head;
			// head
			head = temp;
		}
         else
		{//get into before the position
			Node *current = head;
			int i = 1;
			while(i<pos-1)
			{i++;
            current = current->next;
			}  //here  current points to the node  before the position
            //counter variable to count no. of entries
			int count = 0;
			//declare present pointer to initially point to head
			Node *present = head;
			//increment count upto the last element and simultaneously increment present pointer
			while(present!=NULL)
			{count++;
            present = present->next;
			}
            if(pos>count)
			{cout<<"The linked list doesn't have that many elements\n";}
			else
			{//Creating the node
				Node *temp = new Node;
			    temp->data = value; //value inserted as data to the new node
             //Moving pointers like magic
				temp->next = current->next;//link between new node and the next node
				current->next = temp;//current should be linked to the new node
			}
		}
		cout<<endl;
	}//Deletes element of linked list
	void deletionAt(int pos)
	{if(pos == 1)
		{//set node to be deleted as temp
			Node *temp = new Node;
			temp = head;
			head = head->next;
			//delete temp
			delete temp;
		}
        else
		{
			//get into the position just before the node to be deleted
			Node *current = head;
			int i = 1;
			while(i<pos-1)
			{i++;
            current = current->next;
			}
			//Create the node temp and set it as the node to be deleted
			Node *temp = new Node;
			temp = current->next;
			//link previous to the next node
			current->next = temp->next;
			//delete temp
			delete temp;
	    }
		cout<<endl;
	}
	//Display
	void display()
	{Node *current = head;
		while(current != NULL) //prints
		{cout<<current->data<<"->";
        current = current->next;
		}
		cout<<"NULL";
	}
     //Counts number of items
	int countItems()
	{//set variable
    int count = 0;
    //move pointer from 1st element till the last and increment it everytime
    Node *current = head;
    while(current !=NULL)
		{count++;
        current = current->next;
		}
		//return
		return count;
	}
};
int main()
{LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.display();
	l1.deletion();
	l1.display();
	l1.insertAt(1,15);
	l1.display();
	l1.insertAt(4,19);
	l1.display();
	l1.deletionAt(1);
	l1.display();
	l1.deletionAt(3);
	l1.display();
	cout<<endl;
	l1.insertAt(8,11);
	l1.display();
	cout<<endl;
	cout<<"The number of elements is "<<l1.countItems()<<endl;
	//closing
	return 0;
}
