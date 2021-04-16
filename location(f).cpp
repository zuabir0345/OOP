Source code
#include <iostream>
using namespace std;
#include <string>

struct location 
{
	int number;
	char id[15],descrip[50];
};
location* arr;
void input(location *ar,int size,int start)
{
	for (int i = start; i < size; i++)
	{
		cout << "\n_________________________\nEnter  credentials for " << i + 1 << " Location";
		cout << "\nInput ID\n";
		cin >> ar[i].id;
		cout << "Input Number\n";
		cin >> ar[i].number;
		cout << "Input Description\n";
		cin.getline(ar[i].descrip, 50);
		if (ar[i].descrip[0] == '\0')
		{
			cin.getline(ar[i].descrip, 50);
		}
	}
}
void output(location* ptr, int size, int start)
{
	if (start == 1)
		cout << "\n_____________________\nNumber      : " << ptr[size].number << "\n ID         : " << ptr[size].id << "\nDescription : " << ptr[size].descrip <<  "\n_____________________\n";
	else
		for (int i = 0; i < size; i++)
		{
			cout << "\n_____________________\nNumber      : " << ptr[i].number << "\n ID         : " << ptr[i].id << "\nDescription : " << ptr[i].descrip << "\n_____________________\n";
		}
}
int search(location* ptr, int size)
{
	char srh[20];
	cout << "Search by ID only\n";
	cin >> srh;
	for (int i = 0; i < size; i++)
		if (strcmp(ptr[i].id, srh) == 0)
		{
			output(ptr, size, 1);
			return i;
		}
}

void modify(location* ptr, int size)
{
	int f, j;
	j = search(ptr, size);
	cout << "Press the corresponding number to modify :\n1 : Number\n2 : ID\n3 : Description\n";
	cin >> f;
	switch (f)
	{
	case 1:
		cout << "New Number\n";
		cin >> ptr[j].number;
		break;
	case 2:
		cout << "New ID\n";
		cin >> ptr[j].id;
		break;
	case 3:
		cout << "New Description\n";
		cin.getline(ptr[j].descrip, 50);
		if (ptr[j].descrip[0] == '\0')
		{
			cin.getline(ptr[j].descrip, 50);
		}
		break;
	}
	output(ptr, j, 1);
}
void delet(int& number)
{
	location* ptr1;
	int j,st=0,end=number;
	cout << "Which location you want to delete?\n";
	j=search(arr, number);
	ptr1 = new location[number -1];
	if (j == 0) 
	{ptr1[0] = arr[1];
	goto label1;
	}
	else if (j == end - 1) end = end - 1;
	for (int i = st; i < end; i++)  // Intializing with values
	{
		if (i >= j)
			ptr1[i] = arr[abs(i - 1)];
		else
		ptr1[i] = arr[i];
	}
	label1:
	arr = ptr1;
	number = number - 1;
	ptr1 = NULL;
	delete[]ptr1;
}
void resize(int& number)
{
	location* ptr1;
	int add;
	cout << "How many new locations you want to enter\n";
	cin >> add;
	ptr1 = new location[number + add];
	for (int i = 0; i < number; i++)  // Intializing with values
	{
		ptr1[i] = arr[i];
	}
	input(ptr1,number+add,number);
	arr = ptr1;
	number = number + add;
	ptr1 = NULL;
	delete[]ptr1;
}

int main()
{
	cout << "_________________\nNAME : ZUBAIR AHMED\nROLL NUMBER : 20F-0345\n_________________\n";
	int size = 2, n;
	arr = new location[size];
	cout << "INPUT PROCEDURE\n1)ID and Quantity(integers)\n2) Title and Author(strings)";
	input(arr,size,0);
	cout << "Enter the value to perform the corresponding function\n_____________________\n1 : Add\n2 : Delete\n3 : Modify\n4 : Search\n5 : Print\n6 : End\n_____________________\n";
	cin >> n;
	while (n != 6)
	{
		switch (n)
		{
		case 1:
			cout << "ADDING LOCATION\n_________________\n";
			resize(size);
			break;
		case 2:
			cout << "DELETING LOCATION\n_________________\n";
			delet(size);
			break;
		case 3:
			cout << "MODIFYING LOCATION\n_________________\n";
			modify(arr, size);
			break;
		case 4:
			cout << "SEARCING LOCATION\n_________________\n";
			search(arr, size);
			break;
		case 5:
			cout << "PRINTING LOCATION\n_________________\n";
			output(arr, size, 0);
		}
		cout << "\nPress your desired function key\n";
		cin >> n;
	}
	arr = NULL;
	delete[]arr;
}
