#include <iostream>
using namespace std;
#include <iomanip>
struct book// structure for car record 
{
	int quantity;
	char id[5] ,title[20], author[20];
};
book* arr;
book input(book* ar, int size,int start)
{
	for (int i = start; i < size; i++)
	{
		cout << endl<<"________________________\nEnter credential for " << i + 1 << " Book\n";
		cout << "Input ID\n";
		cin >> ar[i].id;
		cout << "Input Title\n";
		cin >> ar[i].title;
		cout << "Input Author\n";
		cin >> ar[i].author;
		cout << "Input quantity\n";
		cin >> ar[i].quantity;
	}
	return *ar;
}
void output(book* ptr, int size,int start)
{
	if (start == 1)
		cout << "\n_____________________\nBook ID  : " << ptr[size].id << "\nName     : " << ptr[size].title << "\nAuthor   : " << ptr[size].author << "\nQuantity : " << ptr[size].quantity << "\n_____________________\n";
	else
	for (int i = 0; i < size; i++)
	{
		cout << "\n_____________________\nBook ID  : " << ptr[i].id << "\nName     : " << ptr[i].title << "\nAuthor   : " << ptr[i].author << "\nQuantity : " << ptr[i].quantity << "\n_____________________\n";
	}
}
int serch(book* ptr, int size)
{
	char srh[20];
	cout << "Search by ID only\n";
	cin >> srh;
	for (int i = 0; i < size; i++)
		if (strcmp(ptr[i].id, srh) == 0)
			return i;
}
void modify(book *ptr,int size)
{ 
	int f, j;
	j = serch(ptr, size);
	cout << "Press the corresponding number to modify :\n1 : ID\n2 : Title\n3 : Author\n4 : Quantity\n";
	cin >> f;
	switch (f)
	{
	case 1:
		cout << "New ID";
		cin >> ptr[j].id;
		break;
	case 2:
		cout << "New Title ";
		cin >> ptr[j].title;
		break;
	case 3:
		cout << "New Author name";
		cin >> ptr[j].author;
		break;
	case 4:
		cout << "New Quantity";
		cin >> ptr[j].quantity;
		break;
	}
	output(ptr, j, 1);
}
void specific(int size)
{
	char srh[20];
	int c;
	cout << "Enter ID,Title or Author name\n";
	cin >> srh;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].id, srh) == 0 || strcmp(arr[i].title, srh) == 0 || strcmp(arr[i].author, srh) == 0)
			output(arr, i, 1);
	}
}
void issue( int size)
{
	int n;
	int j=serch(arr, size);
	n=arr[j].quantity;
	if (n == 0)cout << "Error:Out of stock \n";
	arr[j].quantity = --n;
	output(arr, j, 1);
}
 void resize(int &number)
 {
	 book* ptr1;
	 int add;
	 cout << "How many new books you want to enter";
	 cin >> add;
		 ptr1 = new book[number +add];
		 for (int i = 0; i < number ; i++)  // Intializing with values
		 {
			 ptr1[i] = arr[i];
		 }
		 input(ptr1, number+add,number);
		 output(arr, number, 0);
		 arr = ptr1;
		 number = number+ add;
		 ptr1 = NULL;
		 delete[]ptr1;
 }

 int main()
 {
	 cout << "_________________\nNAME : ZUBAIR AHMED\nROLL NUMBER : 20F-0345\n_________________\n";
	 int size = 3, n;
	 arr = new book[size];
	 cout << "INPUT PROCEDURE\n1)ID and Quantity(integers)\n2) Title and Author(strings)";
	 input(arr, size, 0);
	 cout << "Enter the value to perform the corresponding function\n_____________________\n1 : Add more books\n2 : Search\n3 : Modify\n4 : Issue\n5 : Print\n6 : End\n_____________________\n";
	 cin >> n;
	 while (n != 6)
	 {
		 switch (n)
		 {
		 case 1:
			 cout << "ADDING BOOK\n______________\n";
			 resize(size);
			 break;
		 case 2:
			 cout << "SEARCHING BOOK\n______________\n";
			 specific(size);
			 break;
		 case 3:
			 cout << "MODIFYING BOOK\n______________\n";
			 modify(arr, size);
			 break;
		 case 4:
			 cout << "ISSUING BOOK\n______________\n";
			 issue(size);
			 break;
		 case 5:
			 cout << "PRINTING BOOK\n______________\n";
			 output(arr, size, 0);
		 }
		 cout << "\nPress your desired function key";
		 cin >> n;
	 }
	 arr = NULL;
	 delete[]arr;
 }
