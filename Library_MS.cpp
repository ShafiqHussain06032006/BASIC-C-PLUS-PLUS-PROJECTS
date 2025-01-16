#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class temp
{
    string id, name, Author, search;
    fstream file;

public:
    void addbook();
    void showAll();
    void extractbook();
};
int main()
{
        temp obj;
   
    int choice;
    char select;
    do
    {
        do
        {   
        
            cout << "-------------------------------------" << endl;
            cout << "\t\tWELCOME TO LIBRARY MANAGE SYSTEM    " << endl;
            cout << "\t\t1) Show All Books " << endl;
            cout << "\t\t2) Extract Book  " << endl;
            cout << "\t\t3) Add Books(Admin) " << endl;
            cout << "\t\t4) Exit  " << endl;
            cout << "-------------------------------------" << endl;
            cout << "Enter your choice :: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cin.ignore();
                obj.showAll();
                break;
            case 2:
                cin.ignore();
                obj.extractbook();
                break;
            case 3:
                cin.ignore();
                obj.addbook();
                break;
            case 4:
                cout << "Exiting ......" << endl;
                break;

            default:
                cout << "Invalid Choice !" << endl;
                break;
            }

        } while (choice != 4);
        {

            cout << "Do you want to continue (y/Y or no)";
            cin >> select;
        }
    } while (select == 'Y' || select == 'y');
    {

        cout << "Continue...................." << endl;
    }
}
void temp ::addbook()
{
    cout << "Enter book ID :: ";
    getline(cin, id);

    cout << "Enter book Name :: ";
    getline(cin, name);
    cout << "Enter book Author Name ::";
    getline(cin, Author);
    // Writing form the files .
    file.open("bookData.txt", ios ::out | ios ::app);
    file << id << "*" << name << "*" << Author << endl;
    file.close();
}
void temp ::showAll()
{
    file.open("bookData.txt", ios ::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, Author, '\n');
    cout << "\n\n";
    cout<<"\t\tBook ID\t\t\tBook Name\t\t\tAuthor's Name "<<endl;
    while (!file.eof())
    {
     cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<Author<<endl;
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, Author, '\n');
    }
    file.close();
}
void temp ::extractbook()
{
    showAll();
    cout << "Enter Book ID ::";
    getline(cin, search);
    file.open("bookData.txt", ios ::in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, Author, '\n');

    cout << "\n"
         << endl;
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name " << endl;
    while (!file.eof())
    {
        if (search == id)
        {
            cout << "\t\t"<<id<<" \t\t\t"<<name<< " \t\t\t" <<Author<<  endl;
            cout << "Book Extracted Successfully ...." << endl;
        }
        getline(file, id, '*');
        getline(file, name, '*');
        getline(file, Author, '\n');
    }
    file.close();
}