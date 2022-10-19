#include <bits/stdc++.h>
#include <windows.h>
#include "queue.h"
#include "stack.h"
#include "employee.h"
#include "login.h"

using namespace std;

//Global functions and variables declarations
int search(int);
int displayMedicine();
string checkQuantity(int); //   for checking quantity
void Sales(int, int, string);
int countOfSales = 0;
int totalItems[30], totalAmounts[30];
string Customers[30];


////////////////////////////////////////////////////////////////////
//Linked List class
class Pharmacy
{
public:
	int ID;
	string medName;
	double medPrice;
	int quantity;
	struct Pharmacy *next;
};

Pharmacy *Head = NULL;
Pharmacy *Last = NULL;

////////////////////////////////////////////////////////////////////
//Function to append medicines initially hard coded.
void Append(int id, string name, double price, int qty)
{
	// creating new node
	Pharmacy *new_node = new Pharmacy();

	Last = Head; // Initially first node is also the last node

	// put in the data
	new_node->ID = id;
	new_node->medName = name;
	new_node->medPrice = price;
	new_node->quantity = qty;

	// This new node is going to be the last node, so make next of it as NULL
	new_node->next = NULL;

	// If the Linked List is empty, then make the new node as Head
	if (Head == NULL)
	{
		Head = new_node;
		return;
	}

	// Else traverse till the last node
	// Loop to move towards the last node
	while (Last->next != NULL)
	{
		Last = Last->next;
	}

	// Change the next of Last Pharmacy
	Last->next = new_node;
	return;
}

////////////////////////////////////////////////////////////////////
//Function to insert medicine input based
void insertMedicine()
{
	system("cls");
	int id, qty;
	string name;
	double price;
	Pharmacy *temp = new Pharmacy;
	Pharmacy *curr = Head;

	cout << "\t\t\tEnter product ID : ";
	cin >> id;
	temp->ID = id;
	cout << "\t\t\tEnter product Name : ";
	cin >> name;
	temp->medName = name;
	cout << "\t\t\tEnter product price : ";
	cin >> price;
	temp->medPrice = price;
	cout << "\t\t\tEnter product quantity : ";
	cin >> qty;
	temp->quantity = qty;

	if (Head == NULL)
	{
		temp->next = Head;
		Head = temp;
	}
	else
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
		temp->next = NULL;
	}
	
	system("cls");
	cout << "\n\n\t\t\t\tMedicine Inserted Successfully !\n\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function to search medicine by ID
int search(int medID) 
{
	int count = 1;
	Pharmacy *curr = Head;
	for (curr = Head; curr != NULL; curr = curr->next)
	{
		if (curr->ID == medID)
		{
			return count;
		}
		else
		{
			count++;
		}
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////
//Function to delete medicine input based
void deleteMedicine()
{
	system("cls");
	displayMedicine();
	int id;

	Pharmacy *curr = Head;
	Pharmacy *prev = Head;
	cout << "\n\nEnter ID to delete Medicine : ";
	cin >> id;
	if (Head == NULL)
	{
		system("cls");
		cout << "List is empty. There are no Medicines to be deleted !" << endl;
	}
	int searchResult = 0;
	int count = displayMedicine();     //Get no of total existing medicines
	searchResult = search(id);	   //Checking if desired medicine exists or not
	
	if (searchResult != -1)
	{
		if (curr != NULL && curr->ID == id)
		{
			Head = curr->next;
			goto B;
			// delete curr;
			// return;
		}
		else
		{
			// to delete middle medicines
			while (curr->ID != id)
			{ 
				prev = curr;
				curr = curr->next;
			}
		}

		prev->next = curr->next;

	B:
		delete curr;
		system("cls");
		cout << "\n\n\t\t\t\tMedicine Deleted Successfully !\n\n\n";
	}
	else
	{
		cout << "\n\n\t\t\t\tMedicine Not Found. Please enter correct ID !\n\n\n";
	}
}

//////////////////////////////////////////////////////////////////////////////////
//Function to modify medicine input based by id
void modifyMedicine()
{
	int id;
	double newPrice; 
	string newName;
	int newId, newQty; 
	if (Head == NULL)
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	else
	{
		displayMedicine();
		cout << "\n\nEnter ID to modify Medicine's Name and its Price : ";
		cin >> id;
		Pharmacy *curr = Head;
		int searchResult = 0;
		int count = displayMedicine();    //Get no of total existing medicines
		searchResult = search(id);        //Checking if desired medicine exists or not
		
		if (searchResult != -1)
		{
			while (curr->ID != id)
			{
				curr = curr->next;
			}
			cout << "\nOld ID : " << curr->ID << endl;
			cout << "\nOld Name : " << curr->medName << endl;
			cout << "\nOld Price : " << curr->medPrice << endl;
			cout << "\nOld Quantity : " << curr->quantity << endl;

			cout << endl << endl;
			cout << "Enter new ID : ";
			cin >> newId;
			curr->ID = newId;
			cout << "Enter new Name : ";
			cin >> newName;
			curr->medName = newName;
			cout << "Enter new Price : ";
			cin >> newPrice;
			curr->medPrice = newPrice;
			cout << "Enter new Quantity : ";
			cin >> newQty;
			curr->quantity = newQty;
		}
		else
		{
			cout << "\n\n\t\t\t\tMedicine Not Found. Please enter correct ID !\n\n\n";
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//Function to print all existing medicines
int displayMedicine()
{
	system("cls");
	int totalProducts = 0;
	Pharmacy *curr = Head;
	cout << "Existing products are : \n\n";
	cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n\n";
	cout << "=================================================================|\n\n";
	while (curr != NULL)
	{
		cout << curr->ID << "\t\t" << curr->medName << "\t\t\t" << curr->medPrice << "\t\t\t" << checkQuantity(curr->quantity) << "\n"; // call check function and pass quantity
		curr = curr->next;
		totalProducts = totalProducts + 1;
	}
	cout << "\nTotal products in our store is : " << totalProducts << "\n\n\n";
	return totalProducts;
}

////////////////////////////////////////////////////////////////////////////////////////
//Function to check is sufficient quantity is available to buy
string checkQuantity(int qty)
{
	int x = qty;
	stringstream ss;
	ss << x;
	string quantity = ss.str();

	if (qty <= 0)
	{
		return "out of stock ! ";
	}
	else
	{
		return quantity;
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//Function to record each sales transaction into arrays
void recordSales(int Items, int Amounts, string customerName)
{
	totalItems[countOfSales] = Items;
	totalAmounts[countOfSales] = Amounts;
	Customers[countOfSales] = customerName;
	countOfSales++;
}


///////////////////////////////////////////////////////////////////////
//Function to view all sales of the day
void viewSales()
{
	int totalSales = 0;
	system("cls");
	
	//Library function to get date and time
	time_t now = time(0);

	// convert now to string form
	tm *ltm = localtime(&now);

	cout << "\n\n\t\t\t============================== Total Sales ==============================" << endl
		 << endl;
	cout << "\t\t\t Customer Name\t\t Total Items\t\t Bill Amount\t\t Date" << endl << endl;

	for (int i = 0; i < countOfSales; i++)
	{
		totalSales += totalAmounts[i];

		cout << "\t\t\t " << Customers[i] << "\t\t\t" << totalItems[i] << "\t\t\t" << totalAmounts[i] << "\t\t\t" << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl
			 << endl;
	}
	cout << "\n\t Total Sales For The Day : " << totalSales << endl;
}


////////////////////////////////////////////////////////////////////////////////////////
//Function for Printing detailed item wise bill into txt file.
void PrintBill(int numOfItems, int pay, string products[], double pricesOfProducts[], int qtyProducts[], int totalPrice, string customer)
{
	ofstream myfile;
	myfile.open("generatedBill.txt");
	
	myfile << "\n\n\t\t\t============================== Your Bill ==============================" << endl
		   << endl;
	myfile << "\t\t\tProduct Name\t\tPrice\t\tQuantity\t\tCalculated Cost" << endl;
	for (int i = 0; i < numOfItems; i++)
	{
		myfile << "\t\t\t" << products[i] << "\t\t\t" << pricesOfProducts[i] << "\t\t\t" << qtyProducts[i] << "\t\t\t" << pricesOfProducts[i] * qtyProducts[i] << endl;
	}
	myfile << "\t\t\t======================================================================" << endl;

	myfile << "Dear " << customer << ",";
	myfile << "\nOriginal Price = RS:" << pay << endl;
	myfile << "\nTotal bill to be paid after (12% dicount) = RS:" << totalPrice << endl;
	myfile.close();
}

////////////////////////////////////////////////////////////////////////////////////////
//Function to calculate Amount without any discount
int calculateBill(double prices[], int quantities[], int items)
{
	int Amount = 0;
	for (int i = 0; i < items; i++)
	{
		Amount += prices[i] * quantities[i]; //     calculate Bill
	}
	return Amount;
}

////////////////////////////////////////////////////////////////////////////////////////
//Function to print detailed itemwise bill with discount
void generateBill(int numOfItems, int pay, string products[], double pricesOfProducts[], int qtyProducts[])
{
	string customer;
	cout << "\n\t\t Enter Your Name : ";
	cin >> customer;
	Enqueue(customer);
	system("cls");

	cout << "\n\n\n\n\t\t\tYou have bought :     ||      ";
	for (int i = 0; i < numOfItems; i++)
	{ 
		// shows that item you have bought
		cout << products[i] << ", ";
	}
	cout << "      ||" << endl;
	int totalPrice = pay - (pay * 0.12); //    with 12% discount

	cout << "\n\n\t\t\t============================== Your Bill ==============================" << endl << endl;
	cout << "\t\t\tProduct Name\t\tPrice\t\tQuantity\tCalculated Cost" << endl << endl;
	for (int i = 0; i < numOfItems; i++)
	{
		cout << "\t\t\t" << products[i] << "\t\t\t" << pricesOfProducts[i] << "\t\t" << qtyProducts[i] << "\t\t" << pricesOfProducts[i] * qtyProducts[i] << endl;
	}
	cout << "\t\t\t======================================================================" << endl;

	cout << "\nOriginal Price = RS:" << pay << endl << endl;
	cout << "\nTotal bill to be paid after (12% dicount) = RS : " << totalPrice << endl;

	cout << "\n\nCheck you bill in (generatedBill.txt) file." << endl;

	//Functions to print individual bill and record daily sales
	PrintBill(numOfItems, pay, products, pricesOfProducts, qtyProducts, totalPrice, customer);
	recordSales(numOfItems, totalPrice, customer);
}


///////////////////////////////////////////////////////////////////////
//Function to buy Medcine input based by ID
void buyMedicine() 
{
	system("cls");
	displayMedicine();
	string Medicines[20];
	double pricesOfMedicines[20];
	int qtyMedicines[20];
	
	int numOfItems, j = 0, price, id, i = 1;
	double Amount = 0.0;

	if (Head == NULL)
	{
		cout << "\n<<<< There are no items to buy ! >>>>\n\n";
	}
	else
	{
		cout << "How many items you want to buy : ";
		cin >> numOfItems;
		int count = displayMedicine(); // 
		while (i <= numOfItems)
		{
			Pharmacy *curr = Head;
			int qty, choice;

		A:
			cout << "\nEnter ID of item that you want to buy : ";
			int id, searchResult = 0;
			cin >> id;
			if (id == -1)
			{
				system("cls");
				return;
			}
			searchResult = search(id);
			if (searchResult != -1)
			{
				//     item is available in store
				while (curr->ID != id)
				{
					curr = curr->next;
				}
				cout << "\nEnter the quantity : ";
				cin >> qty;
				if (curr->quantity < qty)
				{
					cout << "\n\n\t\t\t---- The Quantity You Entered Is Not Available ---" << endl;
					cout << "\n\t\t\t----- Press -1 To Go Back to Main Menu ------" << endl;
					goto A;
				}
				Medicines[j] = curr->medName;    // this array will conatin the medicines bought;
				pricesOfMedicines[j] = curr->medPrice;
				qtyMedicines[j] = qty;
				j++;

				curr->quantity -= qty;   // change quantity from linked list
				i++;					 // looping variable
			}
			else
			{
				cout << "\n<<<< This item is currently not available in our store ! >>>>\n\n";
			}
		}
		Amount = calculateBill(pricesOfMedicines, qtyMedicines, j);
		generateBill(numOfItems, Amount, Medicines, pricesOfMedicines, qtyMedicines);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//Function to display admin dashboard
void administator()
{
	system("cls");
	int ch;

	do
	{
		// Dispplaying administrator accessibility options

		cout << "\t\t\t\t ============================================" << endl;
		cout << "\t\t\t\t||          Administator Dashboard          ||" << endl;
		cout << "\t\t\t\t ============================================\n\n" << endl;

		cout << "\t\t\t\t     Enter 1 to ADD a New Medicine    " << endl;
		cout << "\t\t\t\t     Enter 2 to DISPLAY All Medicines   " << endl;
		cout << "\t\t\t\t     Enter 3 to UPDATE Existing Medicine" << endl;
		cout << "\t\t\t\t     Enter 4 to DELETE a particular Medicine" << endl;
		cout << "\t\t\t\t     Enter 5 to VIEW Customer List" << endl;
		cout << "\t\t\t\t     Enter 6 to DEQUEUE Customer" << endl;
		cout << "\t\t\t\t     Enter 7 to VIEW Sales" << endl;
		cout << "\t\t\t\t     Enter 8 to MANAGE Staff" << endl;
		cout << "\t\t\t\t     Enter 0 for Main Menu" << endl;

		cout << "\nEnter Your choice >>> : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			insertMedicine();
			break;
		case 2:
			system("cls");
			displayMedicine();
			break;
		case 3:
			modifyMedicine();
			system("cls");
			break;
		case 4:
			deleteMedicine();
			break;
		case 5:
			system("cls");
			cout << "||============  CUSTOMERS NAMES LIST  ==============||\n" << endl;
			displayQueue();
			break;
		case 6:
			system("cls");
			cout << "||============  CUSTOMERS NAMES LIST  ==============||\n" << endl;
			Dequeue();
			displayQueue();
			break;
		case 7:
			viewSales();
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			ManageEmployers();

		default:
			system("cls");
		}
	} while (ch != 0);
}
// Main Driver function
int main()
{

	for (int i = 0; i <= 26; i++) // pushing (n-2) baskets in stack for our store
	{
		push(i);
	}
	Append(01, "Brufen", 120.50, 15);
	Append(02, "Flagyl", 150, 156);
	system("cls");
	cout << "\n\n\n\t\t\t --------------------------------------------------" << endl;
	cout << "\n\n\t\t\t||            Pharmacy Management System            ||" << endl;
	cout << "\n\n\n\t\t\t --------------------------------------------------\n\n\n" << endl;
	
	system("pause");
	system("cls");
	 //system("color F1");
	//system("color Fc");

	int ch;
	while (ch != 3)
	{

		//Main Menu 
		cout << "\t\t\t\t ============================================" << endl;
		cout << "\t\t\t\t||                Main Menu                 ||" << endl;
		cout << "\t\t\t\t ============================================" << endl;
		cout << "\n\n";
		cout << "\t\t\t\t 1) Administator Dashboard\n";
		cout << "\t\t\t\t 2) Customer Dashboard\n";
		cout << "\t\t\t\t 3) Exit                    \n";

		cout << "\nEnter Your choice >>> : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			login();
			administator();
			break;

		case 2:
			cout << endl<< endl;
			customerProceed();
			system("pause");
			buyMedicine();
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "\n\n\t\t\t\t\t <<< Thank You for choosing us ! >>> \t\t\t\t";
			break;
		}
	}
	return 0;
}
