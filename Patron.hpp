/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Patron class declaration file
 */


#ifndef PATRON_HPP
#define PATRON_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Book;  // forward declaration

class Patron
{

	private:
	string idNum;
	string name;
	vector<Book*> checkedOutBooks;
	double fineAmount;

	public:
	Patron();
	Patron(string idn, string n);

	string getIdNum();
	string getName();

	vector<Book*> getCheckedOutBooks();
	void addBook(Book* b);
	void removeBook(Book* b);

	double getFineAmount();
	void amendFine(double amount);
};

#endif
