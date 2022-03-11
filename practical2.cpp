#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class student
{
public:
    int Rollno, Year;
    char Name[20];
    char Class[20];
    double TotalMarks;
    void getinpt()
    {
        cout << "Enter student details:- " << endl;
        cout << "\nEnter student roll number: ";
        cin >> Rollno;
        cout << "Enter student year: ";
        cin >> Year;
        cout << "Enter student name: ";
        cin >> Name;
        cout << "Enter student class: ";
        cin >> Class;
        cout << "Enter student total marks: ";
        cin >> TotalMarks;
    }
};

int main()
{
    student s1[2];
    char ch;
    for (int i = 0; i < 2; i++)
        s1[i].getinpt();
    ofstream f1;
    f1.open("Student.txt");
    if (!f1)
    {
        cout << "Error in opening  ";
        exit(10);
    }
    for (int i = 0; i < 3; i++)
    {
        f1 << setw(5) << s1[i].Rollno;
        f1 << setw(5) << s1[i].Name;
        f1 << setw(5) << s1[i].Class;
        f1 << setw(5) << s1[i].Year;
        f1 << setw(5) << s1[i].TotalMarks << endl;
    }
    cout << " records taken! "<< endl;
    //f1.close();
    
    ifstream f2;
    f2.open("Student.txt");
    cout << "displaying records:-" << endl;
    while(f2.get(ch))
    cout<<ch;
	

    return 0;
}
