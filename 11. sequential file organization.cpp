#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Student
{
   typedef struct studentinfo
    {
        char name[50];
        int rollno;
        char division[5];
        char address[100];
    }rec ;
    rec records;
    public:
    void create();
    void display();
    void search();
    void Delete(int a);
};
void Student:: create()
{
    char ch ='y';
    fstream seq;
    seq.open("StudentRecord.txt",ios::out);
    do{
        cout << "Enter name : ";
        cin >> records.name;
        cout << "Enter roll number : ";
        cin >> records.rollno;
        cout << "Enter division : ";
        cin >> records.division;
        cout << "Enter address : ";
        cin >> records.address;
        seq.write((char*)&records,sizeof(records));
         cout <<"\n Do you want to add more records :  ";
         cin >> ch;
    }while (ch=='y');
    seq.close();
}
void Student::display()
{
    fstream seq;
    int n;
    seq.open("StudentRecord.txt",ios::in);
    seq.seekg(0,ios::beg);
    cout << "\n Content of file are ... "<< endl;
     while (seq.read((char*)&records, sizeof(records)))
     {
        if(records.rollno!=-1)
        {
            cout << "\nName: " << records.name;
            cout << "\nRoll No: " << records.rollno;
            cout << "\nDivision: " << records.division;
            cout << "\nAddress: " << records.address << endl;
        }
    }
    int lastrecord = seq.tellg();
    n = lastrecord/(sizeof(rec));
}
void Student::search()
{
    fstream seq;
    int id,pos;
    cout << "\n Enter the roll number to search";
    cin >> id;
   seq.open("StudentRecord.txt",ios::in|ios::binary);
   seq.seekg(0,ios::beg);
   bool found = false;
    while (seq.read((char*)&records, sizeof(records)))
    {
        if(records.rollno==id)
        {
            found= true;
            cout<<"Student record found";
            cout << "\nRoll Number: " << records.rollno << endl;
            cout << "\nName: " << records.name << endl;
            cout << "\nDivision: " << records.division << endl;
            cout << "\nAddress: " << records.address << endl;
            break;
        }
    }
    seq.close();
    if(!found)
    {
        cout << "Roll No :"<< id << " is not found!" << endl;
    }
}
void Student::Delete(int id)
{ 
    ifstream infile;
    ofstream outfile;
    infile.open("StudentRecord.txt",ios::in);//open file for read purpose
    outfile.open("temp.txt",ios::app);//create file for write purpose if no matching record found
    infile.seekg(0,ios::beg);
    bool flag =false;
    while(infile.read((char *)&records,sizeof(records)))
    {
        if(records.rollno==id)
        {
            flag =true;
            continue;
        }
        outfile.write((char *)&records,sizeof(records));     
    }
    infile.close();
    outfile.close();
    if(flag==false)
    {   remove("temp.txt");
        cout<<"\nRoll no :"<< id <<" is not present in record.";
    }
    else
    {
        remove("StudentRecord.txt");
        rename("temp.txt","StudentRecord.txt");
        cout << "Record deleted successfully." ;
    }
}
int main()
{
    Student s;
    char ans ='y';
    int ch,id;
    bool key;
    do
    {
        cout << "\n 1. Create";
        cout << "\n 2. Display";
        cout << "\n 3. search";
        cout << "\n 4. Delete";
        cout << "\n 5.exit";
        cout << "\n Enter your choice";
        cin >> ch;
        switch(ch)
        {
             case 1: s.create();
                    break;
            case 2: s.display();
                    break;
            case 3: s.search();                                  
                    break;
            case 4: cout << "enter the roll no to delete";
                    cin>> id;
                    s.Delete(id);
                    break;
            default:
            cout << "\n Enter valid choice";
            break;
        }
         cout << "\n Do you want to go back to main menu";
         cin >> ans;
    }while(ans == 'y');
    return 0;
}
