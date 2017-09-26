/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Library implementation file
 */

#include <iostream>
#include "Library.hpp"
#include "Book.hpp"
#include "Patron.hpp"
#include <string>
#include <vector>
using namespace std;


/*******************************************
 * 	      Library::Library             *
 * Default constructor.                    *
 * *****************************************/
	Library::Library()
	{
	  currentDate = 0;
 	  vector<Book> holdings;
	  holdings.reserve(100);
	  vector<Patron> members;
	  members.reserve(100);          
	}


/*******************************************    
 *  	      Library::addBook             *
 * Gets info from user for a book to add   *
 * to the library.                         *
 * *****************************************/
	void Library::addBook()
	{
	string ID, TITLE, AUTHOR;
	
	cout << "\n  Enter book title:  ";
	cin.ignore();
	getline(cin, TITLE);
	

	cout << "\n  Enter book author:  ";
	getline(cin, AUTHOR);
	

	cout << "\n  Enter book id:  ";
	cin >> ID;

	Book newBook(ID, TITLE, AUTHOR);

	bool inLib = false;
	int i = 0;

	while((!inLib) && (i < holdings.size()))
	{

		if (holdings[i].getIdCode() == ID)
		{ inLib = true;
		}

		else
		{ inLib = false; }	

	    i++;
	}
	
	if (inLib == true)
	{  cout << "\n  Sorry, that ID is already in use.";  }

	else
	{   
 	    holdings.push_back(newBook);
	    newBook.setLocation(ON_SHELF);
	    cout << "\n  " << TITLE << " has been added to the library :)\n";
	}
	
	}


/*******************************************    ************
 *           Library::addMember            *
 * Gets patron info from user.             *
 * *****************************************/
	void Library::addMember()
	{
	string NAME, PID;
	
	cout << "\n Enter Patron name:  ";
	cin.ignore();
	getline(cin, NAME);
	

	cout << "\n  Enter Patron ID:  ";
	cin >> PID;
	

	Patron noob(PID, NAME);

	bool exist = false;
	int k = 0;

	while((!exist) && (k < members.size()))
	{
	    
	  	if (members[k].getIdNum() == PID)
	  	{
	    	exist = true;
	        
	  	}

	 	else
	  	{
	   	exist = false;}
	    	
	    k++;  	
	}
	  
	if (exist == true)
	{ cout << "\n  Sorry, that ID is taken!"; }

	else
	{  members.push_back(noob);
	   cout << "\n  " << NAME << " has become a member of the library!\n";
	}	
	}


	
/*******************************************
 *          Library::checkOutBook          *
 * Allows patron to check out book if it is*
 * in the library and on the shelf, and    *
 * updates patrons checkedOut vector. Else,*  
 * print a message and return to menu.     *
 * *****************************************/
	void Library::checkOutBook(string pid, string bid)
	{

	int pat, place;   


	// see if the book is in the library
	bool BID = false;      // initialize flag to false
	int i = 0;

	while((!BID) && (i < holdings.size()))     // while false and smaller than vector
	{
	    
	  	if (holdings[i].getIdCode() == bid) // if the id is in teh vector
	  	{
	    	place = i;        // mark where the book is
		BID = true;	      // set flag to true
	  	}
	    	
	    i++;  	// increment counter
	}
 



	// see if patron is a member of the library
	bool PID = false;    // initialize flag to false
	int k = 0;



	while((!PID) && (k < members.size()))         // while false and smaller than vector 
	{
	    
	  	if ((members[k].getIdNum()) == pid)    // if the id is in the vector
	  	{
		pat = k;		// mark where the patron is
	    	PID = true;		// set flag to true
	  	}
	    	
	    k++;  	// increment counter
	}
	



	if (BID == false)	// print message if book is not in library
	{ 
		cout << "\n  Sorry, that book is not in the library.";	
	}

	else if (PID == false)  // print message if patron is not member of library
	{
		cout << "\n  Sorry, that patron is not a member.";
	}



	// if the book is checked out, print message
	else if (holdings[place].getLocation() == CHECKED_OUT)
	{
	   cout << "\n  Sorry, that book is already checked out.";
	}

	// if the book is on hold, print message
	else if ((holdings[place].getLocation() == ON_HOLD_SHELF) && ((&(members[pat])) != (holdings[place].getRequestedBy())))
	{
	   cout << "\n  Sorry, that book is on hold.";
	}

	
	else
	{
	holdings[place].setCheckedOutBy(&(members[pat]));   // update checkedOutBy

	holdings[place].setDateCheckedOut(currentDate);            // set date to 0

	holdings[place].setLocation(CHECKED_OUT);        // update location

	members[pat].addBook(&(holdings[place]));        // update patron's list
	
		// see if patron had requested book
		if((holdings[place].getRequestedBy()) == (&(members[pat]))) 
		{
			// if so, set back to NULL
			holdings[place].setRequestedBy(NULL);
		}
		
		
	cout << "\n  " << holdings[place].getTitle() << " has been checked out to " << members[pat].getName() << ".";

	}
	}

/*******************************************
 *            Library::returnBook          *
 * Checks if book is in library, and its   *
 * location. Updates patron's list, locale *
 * and checkedOutBy.                       *
 * *****************************************/
	void Library::returnBook(string bid)
	{
        int place;    // declare variable to hold book's location
	    
	// see if the book is in the library
	bool BID = false;      // initialize flag to false
	int i = 0;

	while((!BID) && (i < holdings.size()))    // while false and smaller than vector
	{
	  	if (holdings[i].getIdCode() == bid) // if the id is in the vector
	  	{
	    	place = i;        // mark where the book is
		BID = true;	      // set flag to true
	  	}

	    i++;  	// increment counter
	}

	
	// if not in library, print message 
	if(BID == false)
	{
	   cout << "\n  That book is not part of this library's collection.";
	}

	// if the book isn't checked out, print message
	else if(holdings[place].getLocation() != CHECKED_OUT)
	{
	   cout << "\n  That book is not checked out.";
	}
	

	// else, update several fields
	else
	{

	  for(int r = 0; r < members.size(); r++)
	  {	
		if(&(members[r]) == (holdings[place].getCheckedOutBy()))
		{
		members[r].removeBook(&(holdings[place]));	
		}
	  }
		
	  // update patron's list
	  //members.at(holdings[place].getCheckedOutBy().removeBook(&(holdings[place]));
	
	  // update checkedOutBy
	  holdings[place].setCheckedOutBy(NULL);
	
	   // if nobody else has requested the book, set location to ON_SHELF
	   if((holdings[place].getRequestedBy()) == 0)
	   {
	 	 holdings[place].setLocation(ON_SHELF);
	   } 
	
	   // else, move to hold shelf
	   else
	   {
		holdings[place].setLocation(ON_HOLD_SHELF);
	   }

	   cout << "\n " << holdings[place].getTitle() << " has been returned."; 
	}

	}


/*******************************************
 *          Library::requestBook           *
 * Let's patron put a book on hold if it is*
 * available.                              *
 * *****************************************/
	void Library::requestBook(string pid, string bid)
	{

	int pat, place;   // declare place-indicator variables  


	// see if the book is in the library
	bool BID = false;      // initialize flag to false
	int i = 0;

	while((!BID) && (i < holdings.size()))     // while false and smaller than vector
	{
	  	if (holdings[i].getIdCode() == bid) // if the id is in teh vector
	  	{
	    	place = i;        // mark where the book is
		BID = true;	      // set flag to true
	        }

	    i++;  	// increment counter
	}
 
	// see if patron is a member of the library
	bool PID = false;    // initialize flag to false
	int k = 0;

	while((!PID) && (k < members.size()))        // while false and smaller than vector
	{
	  	if ((members[k].getIdNum()) == pid)    // if the id is in the vector
	  	{
		pat = k;		// mark where the patron is
	    	PID = true;		// set flag to true
	  	}

	    k++;  	// increment counter
	}
	

	if (BID == false)	// print message if book is not in library
	{ 
		cout << "\n  Sorry, that book is not in the library.";	
	}

	else if (PID == false)  // print message if patron is not member of library
	{
		cout << "\n  Sorry, that patron is not a member.";
	}


	// if the book is already requested, print message
	else if (holdings[place].getRequestedBy() != 0)
	{
	   cout << "\n  Sorry, that book is already on hold for another patron.";
	}

	// if the book checked out by the patron requesting it, print message
	else if ((holdings[place].getCheckedOutBy()) == (&(members[pat])))
	{
	   cout << "\n  That book is currently checked out by you.";
	}

	// else, update several fields
	else
	{
		holdings[place].setRequestedBy(&members[pat]);       // update requestedBy
		

		// if book is on shelf, change to on hold shelf
		if(holdings[place].getLocation() == ON_SHELF)
		{
			holdings[place].setLocation(ON_HOLD_SHELF);
		}
		
		// print updated information
		cout << "\n  " << holdings[place].getTitle() << " is on request for " << members[pat].getName() << ".";

	}
	}


/*******************************************
 *           Library::payFine              *
 * Lets patron adjust their fine amount.   *
 * *****************************************/
	void Library::payFine(string pid, double payment)  //get from main
	{
	// see if patron is a member of the library
	bool PID = false;    // initialize flag to false
	int pat, k = 0;

	while((!PID) && (k < members.size()))      // while false and smaller than vector
	{
	
	  	if (members[k].getIdNum() == pid)    // if the id is in the vector
	  	{
		pat = k;		// mark where the patron is
	    	PID = true;		// set flag to true
	  	}

	    k++;  	// increment counter
	}
	

	if (PID == false)	// print message if patron is not in library
	{ 
		cout << "\n  Sorry, that patron is not a library member.";	
	}

	//else, amend fine and print message
	else
	{
		members[pat].amendFine(-(payment));
		cout << "\n  " << members[pat].getName() << "'s fine is now " << members[pat].getFineAmount() << ".";
	}
	}



/*******************************************
 *      Library::incrementCurrentDate      *
 * Updates current date and patron's fine's*
 * increase by 10 cents each day book is   *
 * overdue.                                *
 * *****************************************/
	void Library::incrementCurrentDate()
	{	
		int fine = 0;
		
		currentDate++;    // increment current date
		
		// loop through the members	
		for(int q = 0; q < members.size(); q++)
		{
		    // loop through member's checked out books
		    for(int m = 0; m < (members[q].getCheckedOutBooks()).size(); m++)
		    {	
			
			//check how long the books have been checked out 
			fine = (currentDate - (((members[q].getCheckedOutBooks()).at(m))->getDateCheckedOut()));
			
			// if they've been out for more than 21 days,
			if(fine > 21)
			{
		//	owes = ((fine - 21) *(0.10));
		//	cout << "!" << owes << "!";	
			// increment the patron's fine
			members[q].amendFine(0.10);
			}
		}}
		 cout << "\n  The current date is: " << currentDate << "\n";
	}



/*******************************************
 *        Library::viewPatronInfo          *
 * Shows patrons ID, name, titles of books *
 * checked out, and current fine.          *
 * *****************************************/
	void Library::viewPatronInfo(string pid)
	{


	// see if patron is a member of the library
	bool PID = false;    // initialize flag to false
	int pat, k = 0;


	while((!PID) && (k < members.size()))        // while false and smaller than vector
	{
	  	if (members[k].getIdNum() == pid)    // if the id is in the vector
	  	{
		pat = k;		// mark where the patron is
	    	PID = true;		// set flag to true
	  	}

	    k++;  	// increment counter
	}

	

	if (PID == false)	// print message if patron is not in library
	{ 
		cout << "\n  Sorry, that patron is not a library member.";	
	}


	else
	{
		cout << "\n  Patron ID: " << members[pat].getIdNum();
		cout << "\n  Patron Name: " << members[pat].getName();
		cout << "\n  Books checked out: ";

		for(int p = 0; p < (members[pat].getCheckedOutBooks()).size(); p++)
		{
			cout << (*(members[pat].getCheckedOutBooks())[p]).getTitle() << "\n  ";
		}         // or go through holdings and find books checked out by this patron

		cout << "\n  Fine amount: " << members[pat].getFineAmount(); 
	}	 

	}




/*******************************************
 *           Library::viewBookInfo         *
 * Prints out the books information        *
 * *****************************************/
	void Library::viewBookInfo(string bid)
	{
	
	// see if the book is in the library
	bool BID = false;      // initialize flag to false
	int place, i = 0;

	while((!BID) && (i < holdings.size()))     // while false and smaller than vector
	{
	  	if (holdings[i].getIdCode() == bid) // if the id is in teh vector
	  	{
	    	place = i;        // mark where the book is
		BID = true;	      // set flag to true
	  	}

	    i++;  	// increment counter
	}
 
        if(BID == false)
	{
		cout << "\n  That book is not at this library.";
	}
	
	else
	{
		// print book info
		cout << "\n  Book ID:        " << holdings[place].getIdCode();
		cout << "\n  Title:          " << holdings[place].getTitle();
		cout << "\n  Author:         " << holdings[place].getAuthor();
		cout << "\n  Location:       "; 


		int d =  holdings[place].getLocation();
		if (d == 0)
		{ cout << "The book is in the library."; }

	 	else if (d == 1)
		{ cout << "The book is on hold."; }

		else 
		{  cout << "The book is checked out."; } 
	

		// print who (if anybody) book is requested by
		if(holdings[place].getRequestedBy() != 0)
		{
		   	
	            cout << "\n  Requested By:   " << (holdings[place].getRequestedBy()->getName());
		}

		else
		{
		   cout << "\n  Requested By:   Not Requested";
		}

		// print who (if anybody) book is checked out to
		if(holdings[place].getCheckedOutBy() != 0)
		{
		   cout << "\n  Checked Out To: " << (holdings[place].getCheckedOutBy()->getName());
		}

		else
		{
		   cout<< "\n  Checked Out To: Not Checked Out";
		}

		cout << "\n  Returned In:    ";

		int dueBack = 0, out, owe;
		if(holdings[place].getLocation() == CHECKED_OUT)
		{

		out = (holdings[place].getDateCheckedOut());
		owe = (currentDate - out);
		dueBack = (21 - (currentDate - out));
		
//		dueBack = (currentDate - (holdings[place].getDateCheckedOut()));

			if(owe < 22)
			{
		    	    cout << dueBack << " days";
			}
		

			else
			{
		   	    cout << "Overdue! \n"; 
			}
		 }
		
		else
		{
		   cout << " book not checked out\n";
		}
	}

	}






