using namespace std;

class Node          // Queue node for dumping customer data
{
	public:
    	string customerName;
    	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty()      // function for checking if queue is empty
{
    if(front == NULL && rear == NULL)
    {
        return true;
	}
    else
    {
        return false;
	}
}

void Enqueue(string name)       // functiong for putting customer in queue w.r.t name 
{
    Node* new_node = new Node();
    new_node->customerName = name;      // assigning data 
    new_node->next = NULL;      
    
    if(front == NULL)       // if the current customer is first in queue 
    {
        front = new_node;
        rear = new_node;
        return;
    }
    else        // tackling links if new customer joins queue
    {
        rear->next = new_node;
        rear = new_node;
    }
}

void Dequeue()      // function for dequeue front cutomer who came first
{
	Node *temp = front;
	if(front == NULL)       // if no customer is present in queue
	{
		cout<<"\nQueue Underflow ! The Queue is Empty.\n"<<endl;
	}
	else if(front == rear)      // if only customer left
	{
		front = rear = NULL;
	}
	else        // tackling links in this body
	{
		front = front->next;        
		
	}
    delete(temp);       // free meomry for previous customer
    
}

void displayFront()     // prints name of customer at front of queue 
{
    if(isEmpty())
    {
        cout<<"The Queue is Empty\n";
        return;
	}
    else
    {
    	 cout<<"The Element at front is: "<<front->customerName<<"\n";
	}    
}

void displayQueue()     // prints all customers names present in queue
{
    if(isEmpty())
    {
    	cout<<"The Queue is Empty\n";
	}   
    else
    {
        Node* temp = front;
        while(temp != NULL)
        {
            cout<<"\t"<<temp->customerName <<"\t  "<<endl;
            temp = temp->next;
        }
    }
}
