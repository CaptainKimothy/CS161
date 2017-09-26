/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Book class declaration file
 */


#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
using namespace std;

class Patron;   // forward declaration

// These three locations are mutually exclusive, but note that
// a Book can be on request for a Patron while being checked
// out to another Patron. In that case, the Book's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.

enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};


class Book
{

	private:
	string idCode;
	string title;
	string author;

	Locale location;
	Patron* checkedOutBy;
	Patron* requestedBy;
	int dateCheckedOut;


	public:
	static const int CHECK_OUT_LENGTH = 21;
	Book();
	Book(string idc, string t, string a);

	string getIdCode();
	string getTitle();
	string getAuthor();

	Locale getLocation();
	void setLocation(Locale lo);

	Patron* getCheckedOutBy();
	void setCheckedOutBy(Patron* p);

	Patron* getRequestedBy();
	void setRequestedBy(Patron* p);

	int getDateCheckedOut();
	void setDateCheckedOut(int d);
};

#endif





