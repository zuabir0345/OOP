//small student database without file handling
#include <iostream>
using namespace std;
//creating  data type 
struct Address
{
    int house, street;
    char  city[10], province[10];
};
// creating  nested data type 
struct Student
{
    char name[15];
    Address hcp;
    int age;
    double gpa;
};

int main()
{
    int l = 1;
    cout << "Enter the number of students you want to take data of\n";
    cin >> l;
    Student* student = new Student[l]; //creating DM array
    //entering data from user 
    for (int i = 0; i < l; i++)
    {
        cout << "CREDENTIALS FOR " << i + 1 << " STUDENT\n";
        cout << "Enter Name of Student\n";
        cin.getline(student[i].name, 15);
        if (student[i].name[0] == '\0')
            cin.getline(student[i].name, 15);

        cout << "Enter the house number\n";
        cin >> student[i].hcp.house;
        cout << "Enter the street number\n";
        cin >> student[i].hcp.street;
        cout << "Enter the city the student lives in\n";
        cin.getline(student[i].hcp.city, 10);
        if (student[i].hcp.city[0] == '\0')
            cin.getline(student[i].hcp.city, 10);
        cout << "Enter the province the student is from\n";
        cin.getline(student[i].hcp.province, 10);
        if (student[i].hcp.province[0] == '\0')
            cin.getline(student[i].hcp.province, 10);
        cout << "Enter the age of the student\n";
        cin >> student[i].age;
        cout << "Enter the GPA of the student\n";
        cin >> student[i].gpa;
    }
    // outputing data 
    cout << "NAME\t\tHOUSE\tSTREET\tCITY\tPPROVINCE\tAGE\tGPA\n";
    for (int i = 0; i < l; i++)
    {
        cout << student[i].name << "\t\t" << student[i].hcp.house << "\t" << student->hcp.street << "\t" << student[i].hcp.city << "\t" << student[i].hcp.province << "\t\t" << student[i].age << "\t" << student->gpa << endl;
    }
    student = NULL;
    delete[]student;

}
