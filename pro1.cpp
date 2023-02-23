#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class book
{
    public:
        void endline();
        void mainscreen();
        void loscreen();
        void Add_book();
        void Show_book();
        void Check_book();
        void Update_book();
        void Del_book();
};
void book::endline()
{
    cout<<"*********************************************************"<<endl;
}
void book::mainscreen()
{
    system("cls");
    book b;
    int i;
    endline();
    cout<<"\t \t \t"<<"Main Screen"<<endl;
    cout<<endl;
    cout<<"\t"<<"1.Add book \t\t\t"<<"2.Check book"<<endl;
    cout<<endl;
    cout<<"\t"<<"3.Show book \t\t\t"<<"4.update book"<<endl;
    cout<<endl;
    cout<<"\t"<<"5.Delete book"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t 6.back"<<endl;
    cout<<"Enter the option:";
    cin>>i;
    cout<<endl;
    switch (i)
    {
    case 1:
        b.Add_book();
        break;
    case 2:
        b.Check_book();
        break;
    case 3:
        b.Show_book();
        break;
    case 4:
        b.Update_book();
        break;
    case 5:
        b.Del_book();
        break;
    case 6:
        b.loscreen();
        break;
    default:
        b.mainscreen();
        break;
    }
    
    endline();
}
void book::loscreen()
{
    system("cls");
    book b;
    string id,pass; 
    endline();
    cout<<"\t \t \t"<<"Login Screen"<<endl;
    cout<<endl;
    cout<<"\t"<<"Enter your id:";
    cin>>id;
    cout<<endl;
    cout<<"\t"<<"Enter your Password:";
    cin>>pass;
    cout<<endl;
    endline();
    if (id=="Ramlal"&& pass=="ramlal@169")
    {
        b.mainscreen();
    }
    else
    {
        exit(0);
    }
}
void book::Add_book()
{
    system("cls");
    fstream file;
    char x;
    int no_copy;
    string b_name, a_name, b_id;
    book b;
    endline();
    cout<<"\t \t \t"<<"Add Book"<<endl;
    cout<<endl;
    cout<< "\n\nBook ID : ";
    cin>>b_id;
    cout<< "\nBook Name : ";
    cin>>b_name;
    cout<< "\nAuthor Name : ";
    cin>>a_name;
    cout<< "\nNo. of Books : ";
    cin>>no_copy;
    cout<<endl;
    file.open("A://Work//C++//book.txt",
              ios::out | ios::app);
    file << " " << b_id << " "
         << b_name << " " << a_name
         << " " << no_copy << "\n";
    file.close();
    cout << "\n\nWant to add another book? (y/n) :";
        cin >> x;
        if (x=='y' or x=='Y')
        {
            b.Add_book();
            cout << "\n\nWant to add another book? (y/n) :";
            cin >> x;
        }else
        {
            b.mainscreen();
        }
    endline();

}
void book::Show_book()
{
    system("cls");
    fstream file;
    int no_copy;
    book b;
    string b_name, b_id, a_name;
    endline();
    cout<<"\t \t \t"<<"All Book"<<endl;
    file.open("A://Work//C++//book.txt", ios::in);
    if(!file)
    {
        cout << "\n\nFile Opening Error!";
    }
    else 
    {
        cout << "\n\n\nBook ID\t\tBook"
             << "\t\tAuthor\t\tNo. of "
                "Books\n\n";
        file >> b_id >> b_name;
        file >> a_name >> no_copy;

        while (!file.eof()) {
 
            cout << "  " << b_id
                 << "\t\t" << b_name
                 << "\t\t" << a_name
                 << "\t\t" << no_copy
                 << "\n\n";
            file >> b_id >> b_name;
            file >> a_name >> no_copy;
        }
        system("pause");
        file.close();
    }
    endline();
    b.mainscreen();
}
void book::Check_book()
{
    system("cls");
    fstream file;
    int no_copy, count = 0;
    string b_id, b_name, a_name, b_idd;
    book b;

    endline();
    cout<<"\t \t"<<"Check Particular Book"<<endl;

    file.open("A://Work//C++//book.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
 
        cout << "\n\nBook ID : ";
        cin >> b_idd;
        file >> b_id >> b_name;
        file >> a_name >> no_copy;
 
        while (!file.eof()) {
 
            if (b_idd == b_id) {
 
                system("cls");
                endline();
                cout << "\t\t"
                     << "Check Particular Book";
                cout << "\n\nBook ID : "
                     << b_id;
                cout << "\nName : "
                     << b_name;
                cout << "\nAuthor : "
                     << a_name;
                cout << "\nNo. of Books : "
                     << no_copy;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> b_id >> b_name;
            file >> a_name >> no_copy;
        }
        system("pause");
        file.close();
        if (count == 0)
            cout << "\n\nBook ID Not"
                 << " Found...";
    }
    endline();
    b.mainscreen();
}
void book::Update_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name;
    string a_na, b_idd, b_id;
    book b;

    endline();
    cout << "\t\tUpdate Book Record";
    file1.open("A://Work//C++//book1.txt",
               ios::app | ios::out);
    file.open("A://Work//C++//book.txt", ios::in);
 
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
 
        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;

        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                endline();
                cout << "\t\t\t"
                     << "Update Book Record";
                cout << "\n\nNew Book Name : ";
                cin >> b_na;
                cout << "\nAuthor Name : ";
                cin >> a_na;
                cout << "\nNo. of Books : ";
                cin >> no_co;
                file1 << " " << b_id << " "
                      << b_na << " "
                      << a_na << " " << no_co
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                      << " " << b_name
                      << " " << a_name
                      << " " << no_copy
                      << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");
 
    file.close();
    file1.close();
    remove("A://Work//C++//book.txt");
    rename("A://Work//C++//book1.txt",
           "A://Work//C++//book.txt");
    endline();
    b.mainscreen();
}
void book::Del_book()
{
    system("cls");
    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name;
    book b;
    endline();
    cout << "\t\t\tDelete a Book";
 
    file1.open("A://Work//C++//book1.txt",
               ios::app | ios::out);
    file.open("A://Work//C++//book.txt",
              ios::in);
 
    if (!file)
        cout << "\n\nFile Opening Error...";
    else {
 
        cout << "\n\nBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> no_copy;
        while (!file.eof()) {
 
            if (b_id == b_idd) {
 
                system("cls");
                endline();
                cout << "\t\t\t"
                     << "Delete a Book";
                cout << "\n\nBook is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << b_idd
                      << " " << b_name
                      << " " << a_name
                      << " " << no_copy
                      << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> no_copy;
        }
        if (count == 0)
            cout << "\n\nBook ID "
                 << "Not Found...";
    }
    system("pause");
 
    file.close();
    file1.close();
    remove("A://Work//C++//book.txt");
    rename("A://Work//C++//book1.txt",
           "A://Work//C++//book.txt");
    endline();
    b.mainscreen();
}
int main()
{
    book b;
    b.loscreen();
    return 0;
}