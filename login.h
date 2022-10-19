bool login()
{
	string userName;
	string userPassword;
	int loginAttempt = 0;	 // for restriction inorder to make program more secure.
	while (loginAttempt < 2) // restrictions for not more than 2 attempts
	{
		cout << "\n\n\t\t============= Admin ============\n" << endl;
		cout << "\n\n\t\tPlease enter your user name: ";
		cin >> userName;
		cout << "\n\n\t\tPlease enter your user password: ";
		cin >> userPassword;

		if (userName == "admin" && userPassword == "admin") // checking if both value are true then proceeding further
		{
			cout << "Welcome !\n";
			return true;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n"
				 << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 2) // terminating program if attempts more than specified occurs.
	{
		cout << "Too many login attempts! The program will now terminate.";
		exit(0);
	}
}
