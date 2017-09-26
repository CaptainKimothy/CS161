/* Author: Kim McLeod
 * Date: 3.9.15
 * Description: Library class declaration file
 */


#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patron;  // forward declarations
class Book;


class Library
{

	private:
	vector<Book> holdings;
	vector<Patron> members;
	int currentDate;


	public:
	Library();
	void addBook();
	void addMember();

	void checkOutBook(string pid, string bid);
	void returnBook(string bid);
	
	void requestBook(string pid, string bid);
	void incrementCurrentDate();
	void payFine(string pid, double payment);

	void viewPatronInfo(string pid);
	void viewBookInfo(string bid);

};

#endif
 
