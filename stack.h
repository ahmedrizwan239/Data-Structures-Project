#include <bits/stdc++.h>
using namespace std;

class bucket // Linked List class for bucket as to implement Stack Properties
{
public:
	int data;
	bucket *next;
};

bucket *top; // treating our baskets as stack. hence variable for maintaining stack properties

void push(int data) // for pushing baskets when program starts
{
	bucket *temp = new bucket();

	if (!temp) // overflow condition for stack
	{
		cout << "\nStack Overflow ! No more baskets can be stacked.\n";
		exit(1);
	}
	else // allocating basket number and maintaining stack of baskets in this body
	{
		temp->data = data;
		temp->next = top;
		top = temp;
	}
}

bool isempty() // function to check avalability of baskets.
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int topElement() // function to check 1st reachable basket
{
	if (isempty() == true)
	{
		cout << "Stack is empty ! Please add baskets to start shoppping.\n";
		exit(1);
	}
	return top->data;
}

void customerProceed() // function for customer operations
{
	bucket *temp = new bucket(); // basket for customer

	if (isempty() == true) // checking underflow
	{
		cout << "Stack is empty ! Please add baskets to start shoppping.\n";
		exit(1);
	}
	else // taking basket and making it free from meomry in this body.
	{
		temp = top;
		top = top->next;
		temp->next = NULL;

		free(temp);
	}

	cout << "Your basket No is :" << top->data << endl; // labeling basket index

	// basket design
	cout << "Welcome To Our Pharmacy !\n\n" << endl;
	cout << "       '" << endl;
	cout << "      ' '       " << endl;
	cout << "     '   '   	" << endl;
	cout << "    '     ' 	" << endl;
	cout << "   '       '	" << endl;
	cout << " ||	    ||" << endl;
	cout << " ||	    ||" << endl;
	cout << " ||	    ||" << endl;
	cout << " ||---------||" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

void display()
{
	bucket *temp = new bucket(); // making new basket object

	if (isempty() == true) // underflow check
	{
		cout << "\nStack Underflow ! There are no baskets available.\n";
		exit(1);
	}
	else // printing baskets labels in this body
	{
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}
