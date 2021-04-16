#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
struct dob
{
	int day, year;
	char month[10];
};
struct student
{
	int id,sem;
	char name[15],gender,dept[10];
	float gpa;
	dob dmy;
};
student* arr;
void input(student *ar,int size,int start)
{
	for (int i = start; i < size; i++)
	{
		cout << "\n_________________________\nEnter  credentials for " << i + 1 << " Location";
		cout << "\nInput ID\n";
		cin >> ar[i].id;
		cout << "Input Name\n";
		cin.getline(ar[i].name, 50);
		if (ar[i].name[0] == '\0')
		{
			cin.getline(ar[i].name, 50);
		}
		cout << "Input Date of birth\n";
		cin >> ar[i].dmy.day;
		cout << "Input Month of birth\n";
		cin >> ar[i].dmy.month;
		cout << "Input Year of birth\n";
		cin >> ar[i].dmy.year;
		cout << "\nInput Gender\n";
		cin >> ar[i].gender;
		cout << "Input Semester\n";
		cin >> ar[i].sem;
		cout << "Input Department\n";
		cin.getline(ar[i].dept, 15);
		if (ar[i].dept[0] == '\0')
		{
			cin.getline(ar[i].dept, 15);
		}
		cout << "Input GPA\n";
		cin >> ar[i].gpa;
		
		
	}
}
void output(student* ptr, int size, int start)
{
	cout << "\nID\tNAME\t\tGENDER\tSEMESTER\tDEPARTMENT\tGPA\n";
	for (int i = 0; i < size; i++)
		cout << ptr[i].id << "\t" << ptr[i].name << "\t" << ptr[i].gender << "\t" << ptr[i].sem << "\t\t" << ptr[i].dept << "\t\t" << ptr[i].gpa << endl;
}
int search(student* ptr, int size)
{
	char srh[20];
	cout << "Search by ID only\n";
	cin >> srh;
	for (int i = 0; i < size; i++)
		if(strcmp(ptr[i].name,srh)==0)
		{
			output(ptr, size, 1);
			return i;
		}
}

void modify(student* ptr, int size)
{
	int f, j;
	j = search(ptr, size);
	cout << "Press the corresponding number to modify :\n1 : Number\n2 : ID\n3 : Description\n";
	cin >> f;
	switch (f)
	{
	case 1:
		cout << "New ID\n";
		cin >> ptr[j].id;
		break;
	case 2:
		cout << "New name\n";
		cin.getline(ptr[j].name, 50);
		if (ptr[j].name[0] == '\0')
		{
			cin.getline(ptr[j].name, 50);
		}
		break;
	case 3:
		cout << "New Day of birth\n";
		cin >> ptr[j].dmy.day;
		break;
	case 4:
		cout << "New Month of birth\n";
		cin >> ptr[j].dmy.month;
		break;
	case 5:
		cout << "New Year of birth\n";
		cin >> ptr[j].dmy.year;
		break;
	}
	output(ptr, j, 1);
}
void delet(int& number)
{
	student* ptr1;
	int j,st=0,end=number;
	cout << "Which location you want to delete?\n";
	j=search(arr, number);
	ptr1 = new student[number -1];
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
	student* ptr1;
	int add;
	cout << "How many new locations you want to enter\n";
	cin >> add;
	ptr1 = new student[number + add];
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
	arr = new student[size];
	cout << "INPUT PROCEDURE\n1)ID and Quantity(integers)\n2) Title and Author(strings)";
	input(arr,size,0);
	cout << "Enter the value to perform the corresponding function\n_____________________\n1 : Add\n2 : Delete\n3 : Modify\n4 : Search\n5 : Print\n6 : End\n_____________________\n";
	cin >> n;
	while (n != 6)
	{
		switch (n)
		{
		case 1:
			cout << "ADDING INFORMATION\n_________________\n";
			resize(size);
			break;
		case 2:
			cout << "DELETING INFORMATION\n_________________\n";
			delet(size);
			break;
		case 3:
			cout << "MODIFYING INFORMATION\n_________________\n";
			modify(arr, size);
			break;
		case 4:
			cout << "SEARCING INFORMATION\n_________________\n";
			search(arr, size);
			break;
		case 5:
			cout << "PRINTING INFORMATION\n_________________\n";
			output(arr, size, 0);
		}
		cout << "\nPress your desired function key\n";
		cin >> n;
	}
	arr = NULL;
	delete[]arr;
}
