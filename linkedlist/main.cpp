#include<iostream>
using namespace std;
#include "node.cpp"

												//add elements
Node *add(Node *start)
{
	int data;
	cout << "Enter the element: ";
	cin >> data;
	Node *newnode = new Node(data);
	Node *end = start;
	//first node creation
	if(start == NULL)
	{
		start = newnode;
		//end = newnode;
		
	}
	//second onwards
	else
	{
		while(end->next != NULL)
		{
			end = end->next;
		}
		end->next = newnode;
	}	
	return start;
}

											//delete elements
Node *remove(Node *start)
{
	int data;
	cout << "enter the element you want to delete: ";
	cin >> data;
	Node *curr = start;
	Node *prev = NULL;
	
	//remove data from the list
	if(start == NULL)
	{
		cout << "list is empty" << endl;	
		return start;
	}
	// if first element is the data
	else if(start->data == data)
	{
		start = start->next;
		delete curr;
		return start;
	}
	
	//from 2nd element onwards
	while(curr->data != data)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
	
	return start;
	
}

										//display elements
void display(Node *start)
{
	Node *temp = start;
	cout << "---> ";
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	return;
}

										//finding out the length
void length(Node *start)
{
	Node *curr = start;
	int count = 0;
	
	
	while(curr != NULL)
	{
		++count;
		curr = curr->next;
	}
	cout << endl;
	cout << "---> " << "Length of list is " << count << endl;
	cout << endl;
}

									
									
									
int main()
{
	Node *start = NULL;
	//Node *end = NULL;		mistake

	bool run = true;	
	while(run)
	{
		//options
		cout << "1: Add element." << endl;
		cout << "2: delete element" << endl;
		cout << "3: display" << endl;
		cout << "4: Find out the length" << endl;
		cout << "5: sort the list" << endl;
		cout << "6: exit" << endl;
		cout << endl;
		
		//choose
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
	
		switch(choice)
		{
			case 1:
				start = add(start);
				break;
		
			case 2:
				start = remove(start);
				break;
			
			case 3:
				cout << endl;
				display(start);
				break;
				
			case 4:
				length(start);
				break;
				
			case 5:
				int len = length(start);
				sort(start, 1, len);
				break;
			
			case 6:
				run = false;
				break;
		
			default:
				cout << "please enter a valid option." << endl;
				break;
		}
	}
}
























