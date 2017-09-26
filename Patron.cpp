/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Patron class implementation file
 */


#include <iostream>
#include "Patron.hpp"
#include "Book.hpp"
#include <string>
#include <vector>
#include <cmath>
using namespace std;

 

/*******************************************
 *        Patron::Patron                   *
 * Default constructor                     *
 *******************************************/
 	Patron::Patron()
	{
	   idNum = "";
	   name = "";
	   fineAmount = 0.0;
	}

/*******************************************
 *          Patron::Patron                 *
 * Creates patron object with name and id  *
 *******************************************/       
	Patron::Patron(string idn, string n)
	{
	   idNum = idn;
	   name = n;
	   fineAmount = 0.0;
	}


/*******************************************
 * 	   Patron::getIdNum                *
 * Returns member variable idNum           *
 *******************************************/
	string Patron::getIdNum()
	{
	   return idNum;
	}

/*******************************************
 *          Patron::getName                *
 * Returns member variable name            *
 * *****************************************/
	string Patron::getName()
	{
	   return name;
	}


/*******************************************
 * 	  Patron::getCheckedOutBooks       *
 * Returns vector of currently checked out *
 * books.                                  *
 * *****************************************/
	vector<Book*> Patron::getCheckedOutBooks()
	{
	   return checkedOutBooks;
	}

/*******************************************
 * 	      Patron::addBook              *
 * Adds a book to the patron's checked out *
 * list.                                   *
 * *****************************************/
	void Patron::addBook(Book* b)
	{
	   checkedOutBooks.push_back(b);
	}

/*******************************************
 *          Patron::removeBook             *
 * Removes a book from the patron's list   *
 * of checked out books.                   *
 * *****************************************/
	void Patron::removeBook(Book* b)
	{
	Patron *pat;
	pat = b->getCheckedOutBy();
	

	bool removed = false;
	int place, i = 0;
	
	while(!removed)
	{
	  if(i < checkedOutBooks.size()) 
	  {
		if(checkedOutBooks[i]->getIdCode()  == b->getIdCode())
		{
		   
		    removed = true;
		    checkedOutBooks.erase(checkedOutBooks.begin() +i);
		}
	  }
	i++;

	}
	}

/*******************************************
 * 	   Patron::getFineAmount           *
 * Returns the amount of the user's fine.  *
 * *****************************************/
	double Patron::getFineAmount()
	{
	   return fineAmount;
	}


/*******************************************
 * 	  Patron::amendFine                *
 * Adjusts the patron's fine.              *
 * *****************************************/
	void Patron::amendFine(double amount)
	{
	   fineAmount = fineAmount + amount;
	   if(fineAmount < 0.1)
	   {
		fineAmount = round(fineAmount);
	   }
	}

  




