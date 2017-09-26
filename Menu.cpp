/* Author: Kim McLeod
 * Date: 3.13.15
 * Description: Menu that displays the library options.
 * Loops until user selects 'quit'
 */


 #include <iostream>
 #include <string>
 #include <vector>
 #include "Book.hpp"
 #include "Patron.hpp"
 #include "Library.hpp"
 using namespace std;


 int main()
 {
	
	int choice;  // declare variables and call library constructor
	Library bookWorld; 
	string bookID, patID;
	double pay;

	do
	{
		// display meny and get user's choice
		cout << "\n  ::Library Options:: \n";
		cout << "1. Add a Book \n";
		cout << "2. Add a Member \n";
		cout << "3. Check Out a Book \n";
		cout << "4. Return a Book \n";
		cout << "5. Request a Book \n";
		cout << "6. Pay a Fine \n";
		cout << "7. Increment Current Date \n";
		cout << "8. View Patron Info \n";
		cout << "9. View Book Info \n"; 
		cout << "10. Quit \n";
		cin >> choice;

		while ((choice < 1) || (choice > 10))
		{
		   cout << "\n  Please enter a number from 1 through 10)";
		   cin >> choice;
		   cin.ignore();
		}

		// process user's choice 
		if (choice != 10)
		{
		
	   	   // enter switch statement
 		   switch(choice)
		   {
			case 1: bookWorld.addBook();
				break;
		
			case 2: bookWorld.addMember();
				break;

			case 3: {
				// Get input from user
				cout << "\n  Please enter a book ID: ";
				cin >> bookID;

				cout << "\n  Please enter a patron ID: ";
				cin >> patID;
				
				// call function with user input as parameters	
				bookWorld.checkOutBook(patID, bookID);
				break;
				}

			case 4: {
				cout << "\n  Please enter the book ID: ";
				cin >> bookID;

				bookWorld.returnBook(bookID);
				break;
				}

			case 5: {
				cout << "\n  Please enter book ID: ";
				cin >> bookID;

				cout << "\n  Please enter patron ID: ";
				cin >> patID;
	
				bookWorld.requestBook(patID, bookID);
				break;
				}

			case 6: {
				cout << "\n  Please enter patron ID: ";
				cin >> patID;

				cout << "\n  Please enter amount you wish to pay: ";	
				cin >> pay;
				
				bookWorld.payFine(patID, pay);
				break;
				}	
	
			case 7: bookWorld.incrementCurrentDate();
				break;

			case 8:{
				cout << "\n  Please enter patron ID: ";
				cin >> patID;

				bookWorld.viewPatronInfo(patID);
				break;
				}

			case 9: {
				cout << "\n  Please enter book ID: ";
				cin >> bookID;

				bookWorld.viewBookInfo(bookID);
				break;
				}
		   } 
		}
	} while (choice != 10); 

	return 0;
 }






	
