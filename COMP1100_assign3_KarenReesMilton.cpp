#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

/**************************************************
Karen Rees-Milton
Section number 105
COMP1100 Assignment3
A program to produce a listing of books in a store
***************************************************/

int main()
{
	//housekeeping: Declare all variables, open files, set output rules, print report titles

	const int SIZE = 10;
	string bookTitle[SIZE];
	int noCopies[SIZE], length;
	int noBooks = 0, fewestIndex = 0, totalCopies = 0;

	ofstream fout("books.file");
	if (!fout.is_open())
	{
		cout << "Error opening file";
		system("pause");
		exit(666);
	}

	fout << fixed;

	fout << left << setw(25) << "Book Title"
		<< right << setw(15) << "# of Copies" << endl << endl;

	//input: Use a for loop to obtain to populate an array. Obtain and validate more data

	for (length = 0; length < SIZE; length++)
	{
		cout << "Enter a book title or ^Z to end: ";
		getline(cin, bookTitle[length]);

		if (cin.eof())
			break;

		noBooks++;

		cout << "Enter number of copies of this book: ";
		cin >> noCopies[length];

		while (cin.fail() || noCopies[length] < 0 || noCopies[length] > 50)
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Error. Copies must be a number between 1 and 50. Re-enter: ";
			cin >> noCopies[length];
		}

		//processing: Code nested if, arithmetic, accumulating. End the for loop

		totalCopies += noCopies[length];

		if (noCopies[length] < noCopies[fewestIndex])
			fewestIndex = length;

		cin.ignore(80, '\n');

	}

	//output: Use a for loop to print data in the arrays to the file

	for (int ctr = 0; ctr < length; ctr++)
	{
		fout << left << setw(25) << bookTitle[ctr]
			<< right << setw(15) << noCopies[ctr];

		if (ctr == fewestIndex)
			fout << setw(20) << "*****Fewest******";

		fout << endl;
	}

	//Print and calculate final totals to the file

	fout << endl << left << setw(25) << "Total number of copies"
		<< right << setw(15) << totalCopies << endl;

	fout << left << setw(25) << "Number of books"
		<< right << setw(15) << noBooks << endl << endl;

	cout << "Program ended successfully" << endl;

	system("type books.file");
	system("pause");
}
/******************************************************
Input/Output dialog:
*******************************************************

Enter a book title or ^Z to end : C++ Programming
Enter number of copies of this book : twenty two
Error.Copies must be a number between 1 and 50. Re - enter : 222
Error.Copies must be a number between 1 and 50. Re - enter : -22
Error.Copies must be a number between 1 and 50. Re - enter : 22
Enter a book title or ^Z to end : Java Programming
Enter number of copies of this book : 10
Enter a book title or ^Z to end : Networking
Enter number of copies of this book : 33
Enter a book title or ^Z to end : ^Z
Program ended successfully
Book Title                   # of Copies

C++ Programming                       22
Java Programming                      10 * ****Fewest******
Networking                            33

Total number of copies                65
Number of books                        3

Press any key to continue . . .

*/

