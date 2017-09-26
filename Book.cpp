/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Book class implementation file
 */

#include <iostream>
#include <string>
#include "Patron.hpp"
#include "Book.hpp"
using namespace std;
 


/********************************************
 *             Book::Book                   *
 * Default constructor.                     *
 * ******************************************/
	Book::Book()
	{
	   idCode = "";
	   title = "";
	   author = "";

	   checkedOutBy = NULL;
	   requestedBy = NULL;
	   location = ON_SHELF;
	}

/********************************************
 *             Book::Book                   *
 * Book object constructor. Sets idCode,    *
 * title, and author with parameters.       *
 * ******************************************/
	Book::Book(string idc, string t, string a)
	{
	   idCode = idc;
	   title = t;
	   author = a;

	   checkedOutBy = NULL;
	   requestedBy = NULL;
	   location = ON_SHELF;
	}

/*******************************************
 *           Book::getIdCode               *
 * Retruns the book's id code.             *
 * *****************************************/
	string Book::getIdCode()
	{
	   return idCode;
	}


/*******************************************
 *           Book::getTitle                *
 * Returns the book's title.               *
 * *****************************************/
	string Book::getTitle()
	{
	   return title;
	}


/*******************************************
 *           Book::getAuthor               *
 * Returns the book's author.              *
 * *****************************************/
	string Book::getAuthor()
	{
	   return author;
	}


/*******************************************
 * 	     Book::getLocation             *
 * Returns current location of book.       *
 * *****************************************/
	Locale Book::getLocation()
	{
	   return location;
	}


/*******************************************
 * 	     Book::setLocation             *
 * Sets location member variable.          *
 * *****************************************/
	void Book::setLocation(Locale lo)
	{
	   location = lo;
	}


/*******************************************
 *          Book::getCheckedOutBy          *
 * Returns member variable checkedOutBy    *
 * *****************************************/
	Patron* Book::getCheckedOutBy()
	{
	   return checkedOutBy;
	}


/*******************************************
 * 	   Book::setCheckedOutBy           *
 * Sets the member variable checkedOutBy   *
 * *****************************************/
	void Book::setCheckedOutBy(Patron* p)
	{
	   checkedOutBy = p;
	}


/*******************************************
 *          Book::getRequestedBy           *
 * Returns member variable requestedBy     *
 * *****************************************/
	Patron* Book::getRequestedBy()
	{
	    return requestedBy;
	}


/*******************************************
 * 	     Book::setRequestedBy          *
 * Sets member variable requestedBy        *
 * *****************************************/
	void Book::setRequestedBy(Patron* p)
	{
	   requestedBy = p;
	}


/*******************************************
 * 	    Book::getDateCheckedOut        *
 * Returns member variable dateCheckedOut  *
 * *****************************************/
	int Book::getDateCheckedOut()
	{
	   return dateCheckedOut;
	}

/*******************************************
 * 	    Book::setDateCheckedOut        *
 * Sets member variable dateCheckedOut     *
 * *****************************************/
	void Book::setDateCheckedOut(int d)
	{
	   dateCheckedOut = d;
	}

	



