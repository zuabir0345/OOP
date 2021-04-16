#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct matrix
{
    int rows,colom,**mat;
};

int main()
{
    matrix details;
    int lines = 0,size=0,x;
    string line;
    ifstream myfile("o.txt");
    while (getline(myfile, line))
        ++lines;
    details.rows = lines;
    myfile.close();
    ifstream file("o.txt");//opening the file
    while (file >> x)//getting the size of the array and the element in the array
    {
        size++;
    }
    file.close();
    details.colom = size / lines;
    details.mat = new int* [details.rows];
    for (int i = 0; i<details.rows; i++)
      details.mat[i] = new int[details.colom];
    
    ifstream fil("o.txt");
   for(int i=0;i<details.rows;i++)
     for (int j = 0; fil >> x; j++) //storing the values from file in array
     {
            details.mat[i][j] = x;
            cout << details.mat[i][j] << " ";
     }
    fil.close();
}
