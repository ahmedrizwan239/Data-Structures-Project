//function
void ManageEmployers()
{
    class staff
    {
    public:
    	// Initialize variable of staff class
        int staff_id;
        char name[20];
        float salary;
		
    	//function for takes user input
        void input()
        {
            cout << "\n Enter Staff Id : ";
            cin >> staff_id;
            cout << "\n Enter Staff Name : ";
            cin >> name;
            cout << "\n Enter Salary : ";
            cin >> salary;
        }

		//display function for printing info of staff
        void display()
        {
            cout << "\n Staff Id : " << staff_id;
            cout << "\n Name : " << name;
            cout << "\n Salary : " << salary << "\n";
        }
		
		//use selection sort to sort_staff data by its name
        void sortByName(int z, staff *s)
        {
            staff temp;
            for (int i = 0; i < z; i++)
            {
                for (int j = i + 1; j < z; j++)
                {
                    int r = strcmp(s[i].name, s[j].name);
                    if (r > 0)
                    {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
        }
	
		//use insertion sort to sort_staff data by its id
        void sortById(int z, staff *s)
        {
            for (int i = 0; i < z; i++)
            {
                staff current = s[i];
                int j = i - 1;
                while (s[j].staff_id > current.staff_id && j >= 0)
                {
                    s[j + 1] = s[j];
                    j--;
                }
                s[j + 1] = current;
            }
        }

		//use insertion sort to sort_staff data by its salary
        void sortBySalary(int z, staff *s)
        {
            for (int i = 0; i < z; i++)
            {
                staff current = s[i];
                int j = i - 1;
                while (s[j].salary < current.salary && j >= 0)
                {
                    s[j + 1] = s[j];
                    j--;
                }
                s[j + 1] = current;
            }
        }
        
        //displayEmployees function for display data of staff completely
        void displayEmployees(int z, staff *s)
        {
        	for (int i = 0; i < z; i++)
	        {
	            s[i].display();
	        }
		}
    };
	//end staff class
	
	//initialize variable
    int in;
    staff *s;  // initialize array pointer of staff data type
    int n;
    int z = 0;
    s = new staff[n];  // declare array pointer of staff data type
	
	//do while loop
    do
    {
    	system("cls");
        cout << "\n 1. Insert Data ";
        cout << "\n 2. Display Data ";
        cout << "\n 3. Sort Data by Name ";
        cout << "\n 4. Sort Data by ID ";
        cout << "\n 5. Sort Data by Salary ";
        cout << "\n 6. Exit: ";

        cout << "\n\n Enter Your Choice : ";
        cin >> in;
		system("cls");
		
        switch (in)
        {
        case 1:
			// insert records of staff when in = 1
            cout << "\n Enter No.of Records You Want insert: ";
            cin >> n;
            
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n Enter Data for Employee " << i + 1 << "\n";
                s[z].input(); //store data in an array
                z++;
            }
            cout << "\nRecords Entered successfully !\n"<< endl;
            system("pause");
            break;

        case 2:
			// display employee data when in = 2
            system("cls");
            s->displayEmployees(z, s);
            system("pause");
            break;

        case 3:
			// sort by name when in = 3
            system("cls");
            s->sortByName(z, s);
            cout << "\n Data is Sorted By Name !!!\n\n";
            s->displayEmployees(z, s);
            system("pause");
            break;

        case 4:
			// sort by id when in = 4
            system("cls");
            s->sortById(z, s);
            cout << "\n Data is Sorted By Id!!!\n\n";
            s->displayEmployees(z, s);
            system("pause");
            break;

        case 5:
			// sort by salary when in = 5
            system("cls");
            s->sortBySalary(z, s);
            cout << "\n Data is Sorted By Salary!!!\n\n";
            s->displayEmployees(z, s);
            system("pause");
            break;

        case 6:
            break;

        default:
        	// default msg
            cout << "\n Invalid Choice . . . Please enter correct choice !";
            system("pause");
        }
        
    } while (in != 6);  //exit condition

     
}
