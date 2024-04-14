// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Cars {
    string company[200] = { "Maruti Suzuki","Volkswagen","BMW","Audi","KIA","Tesla","Mercedes","Mahindra","TATA" };
    string model[200] = { "800","2020","Q7","R8","Saltos","S-Series","Benz","Thar","Nano" };
    string color[200] = { "Yellow","Black","Red","Brown","Blue","Silver","Black","Grey","Red" };
    string max_speed[200] = { "80 Km/h ","200 Km/h","300 Km/h","250 Km/h","320 Km/h","400 Km/h","200 Km/h","250 Km/h","280 Km/h" };
    int price[100] = { 10000,20000,50000,40000,50000,50000,20000,20000,20000 };
    int date[100] = { 2020,2012,2019,2018,2017,2016,2015,2021,2010 };
} car;

struct Lease_info {
    string Name[100];
    string Natio_ID[100];
    int payment_acc[100];
} lease;

// Display menu of cars
void Menu() {
    int num = 1;
    for (int i = 0; i < 9; ++i) {
        cout << "\t\t\t";
        cout << "Enter " << num << "\t- To Select  " << car.company[i] << endl;
        num++;
    }
}

// Display details of selected car
void Details(int Choice) {
    system("CLS");
    cout << "\n\n\n\t\t\t-----------------------------\n";
    cout << "\t\t\tYou Have Selected - " << car.company[Choice - 1] << endl;
    cout << "\t\t\t-----------------------------\n\n\n";
    cout << "\t\t\tModel : " << car.model[Choice - 1] << endl;
    cout << "\t\t\tColor : " << car.color[Choice - 1] << endl;
    cout << "\t\t\tMaximum Speed : " << car.max_speed[Choice - 1] << endl;
    cout << "\t\t\tPrice : " << car.price[Choice - 1] << endl;
}

// Check if payment is sufficient for rental
void checklease(int k) {
    if (lease.payment_acc[k] >= car.price[k])
        cout << "\n\n\n\t\t\tProcess has been done successfully!! " << endl;
    else
        cout << "\n\n\n\t\t\tNot Available " << endl;
}

// Take user input for personal details
void user_input(int theChoice) {
    system("CLS");
    int j = theChoice - 1;
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tPlease Provide Your Personal Details  : \n";
    cout << "\t\t\t----------------------------------------\n\n";
    cout << "\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THAN THE RATE OF CAR\n\n\n\n";
    cout << "\t\t\tEnter Your Name : ";
    cin >> lease.Name[j];
    cout << "\t\t\tEnter Your National ID : ";
    cin >> lease.Natio_ID[j];
    cout << "\t\t\tPayment Amount: ";
    cin >> lease.payment_acc[j];
    checklease(j);
}

// Login function
int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t  Car Rental System Login";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) { // character 13 is Enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass") {
        cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
        system("PAUSE");
        system("CLS");
        return 0;
    }
    else {
        cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        return -1;
    }
}

int main() {
    login();
    string decide = "yes";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company ,Choose from the menu : " << endl;
    cout << "\t\t\t----------------------------------------------\n";
    while (decide != "exit") {
        Menu();
        cout << "\n\n\n\t\t\tYour Choice: ";
        int theChoice;
        cin >> theChoice;
        Details(theChoice);
        cout << "\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
        cin >> decide;
        if (decide == "yes") {
            user_input(theChoice);
            cout << "\n\n\t\t\tDo you want to continue ?(yes/no) ";
            cin >> decide;
            if (decide == "no") break;
            system("CLS");
        }
        else {
            if (decide == "no") {
                system("CLS");
                continue;
            }
            else if (decide == "exit") {
                system("CLS");
                break;
            }
        }
    }
    _getch();
    return 0;
}

//
//#include<fstream>
//#include<conio.h>
//#include<string.h>
//#include<iomanip>
//#include<iostream>
//
//
//using namespace std;
//
//
//class book_data
//{
//	char books_number[30];
//	char Book_Name[50];
//	char Author_Name[20];
//	int No_Copies;
//
//
//public:
//	void Get_BookDetails()
//	{
//		cout << "\nENTER DETAILS OF YOUR DESIRED BOOK WHICH YOU WANT TO PURCHASE\n";
//		cout << "\nEnter The Book's Number: ";
//		cin >> books_number;
//		cout << "\nEnter Book's Name: ";
//		cin.ignore();
//		cin.getline(Book_Name, 50);
//		cout << "\nEnter The Author's Name: ";
//		cin.ignore();
//		cin.getline(Author_Name, 50);
//		fflush(stdin);
//		cout << "\nEnter No. Of Copies of the desired book : ";
//		cin >> No_Copies;
//	}
//
//
//	void Show_Book_Data()
//	{
//		cout << "\nBook Number: " << books_number;
//		cout << "\nBook Name: " << Book_Name;
//		cout << "\nAuthor's Name: " << Author_Name;
//		cout << "\nCOPIES : " << No_Copies;
//	}
//	void Modify_Book_Data()
//	{
//		cout << "\nBook number : " << books_number;
//		cout << "\nModify Book Name : ";
//		cin.ignore();
//		cin.getline(Book_Name, 50);
//		cout << "\nModify Author's Name: ";
//		cin.ignore();
//		cin.getline(Author_Name, 50);
//		fflush(stdin);
//		cout << "\nEnter No. Of Copies : ";
//		cin >> No_Copies;
//	}
//	char* get_book_number()
//	{
//		return books_number;
//	}
//	void Report()
//	{
//		cout << books_number << setw(30) << Book_Name << setw(30) << Author_Name << setw(30) << No_Copies << endl;
//	}
//
//
//};
//
//
//
//
//
//fstream fp;
//book_data bk;
//void write_book_data()
//{
//	system("cls");
//	int moremain;
//	fp.open("book.dat", ios::out | ios::app);
//	do
//	{
//		bk.Get_BookDetails();
//		fp.write((char*)&bk, sizeof(book_data));
//		cout << "\nPress 1 to add some more books to the system";
//		cout << "\nPress 2 to go back to the main menu\n";
//		cout << "Enter your choice : ";
//		cin >> moremain;
//	} while (moremain == 1);
//	fp.close();
//}
//
//
//void Display_books(char n[])
//{
//	system("cls");
//	cout << "\nBOOK DETAILS\n";
//	int check = 0;
//	fp.open("book.dat", ios::in);
//	while (fp.read((char*)&bk, sizeof(book_data)))
//	{
//		if (strcmp(bk.get_book_number(), n) == 0)
//		{
//			bk.Show_Book_Data();
//			check = 1;
//		}
//	}
//	fp.close();
//	if (check == 0)
//		cout << "\n\nBook does not exist";
//	_getch();
//}
//
//
//void Modify_Book_Data()
//{
//	system("cls");
//	char n[20];
//	int found = 0;
//	cout << "\n\n\tMODIFY BOOK";
//	cout << "\n\n\tEnter The book number: ";
//	cin >> n;
//	fp.open("book.dat", ios::in | ios::out);
//	while (fp.read((char*)&bk, sizeof(book_data)) && found == 0)
//	{
//		if (strcmp(bk.get_book_number(), n) == 0)
//		{
//			bk.Show_Book_Data();
//			cout << "\nEnter The New Details of book" << endl;
//			bk.Modify_Book_Data();
//			int pos = -1 * sizeof(bk);
//			fp.seekp(pos, ios::cur);
//			fp.write((char*)&bk, sizeof(book_data));
//			cout << "\n\n\t Record Updated Successfully...";
//			found = 1;
//		}
//	}
//	fp.close();
//	if (found == 0)
//		cout << "\n\n Record Not Found ";
//	_getch();
//}
//
//
//void delete_book_data()
//{
//	system("cls");
//	char n[20];
//	int flag = 0;
//	cout << "\n\n\n\tDELETE BOOK";
//	cout << "\n\nEnter The Book's number You Want To Delete: ";
//	cin >> n;
//	fp.open("book.dat", ios::in | ios::out);
//	fstream fp2;
//	fp2.open("Temp.dat", ios::out);
//	fp.seekg(0, ios::beg);
//	while (fp.read((char*)&bk, sizeof(book_data)))
//	{
//		if (strcmp(bk.get_book_number(), n) != 0)
//		{
//			fp2.write((char*)&bk, sizeof(book_data));
//		}
//		else
//			flag = 1;
//	}
//	fp2.close();
//	fp.close();
//	remove("book.dat");
//	rename("Temp.dat", "book.dat");
//	if (flag == 1)
//		cout << "\n\n\tRecord Deleted ..";
//	else
//		cout << "\n\nRecord not found";
//	_getch();
//}
//
//
//void display_all_books()
//{
//	system("cls");
//	fp.open("book.dat", ios::in);
//	if (!fp)
//	{
//		cout << "ERROR!!! Sorry you file can't be opened ";
//		_getch();
//		return;
//	}
//	cout << "\n\n\t\t------Book LIST-------\n\n";
//	cout << "============================================================================================\n";
//	cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
//	cout << "============================================================================================\n";
//	while (fp.read((char*)&bk, sizeof(book_data)))
//	{
//		bk.Report();
//	}
//	fp.close();
//	_getch();
//}
//
//
//void intro()
//{
//	system("color 06");
//	system("cls");
//	/*cout << "\t\t\t\t**\t**";
//	cout << "\t\t\t\t***\t***";
//	cout << "\t\t\t\t****\t****";
//	cout << "\t\t\t\t*****\t*****";
//	cout << "\t\t\t\t******\t******";
//	cout << "\t\t\t\t*******\t*******";*/
//	cout << "\t\t\t\t********\t********";
//	cout << "\t\t\t\t********\t********";
//	/*cout << "\t\t\t\t*******\t*******";
//	cout << "\t\t\t\t******\t******";
//	cout << "\t\t\t\t*****\t*****";
//	cout << "\t\t\t\t****\t****";
//	cout << "\t\t\t\t***\t***";
//	cout << "\t\t\t\t**\t**";*/
//}
//
//
//
//int main()
//{
//	int option = 0;
//	for (;;)
//	{
//		intro();
//		cout << "\n";
//		cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
//		cout << "\n\t\tPress 1 to PURCHASE A BOOK";
//		cout << "\n\t\tPress 2 to DISPLAY ALL BOOKS";
//		cout << "\n\t\tPress 3 to CHECK AVAILABILITY OF THE BOOK IN STORE";
//		cout << "\n\t\tPress 4 to MODIFY BOOK RECORDS";
//		cout << "\n\t\tPress 5 to DELETE BOOK RECORDS";
//		cout << "\n\t\tPress 6 to Exit ";
//		cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
//		cout << "\n\t\tOption: ";
//		cin >> option;
//		switch (option)
//		{
//		case 1: system("cls");
//			write_book_data();
//			break;
//		case 2: display_all_books();
//			break;
//		case 3:
//			char num[20];
//			system("cls");
//			cout << "\n\n\tPlease Enter The book No. ";
//			cin >> num;
//			Display_books(num);
//			break;
//		case 4: Modify_Book_Data(); break;
//		case 5: delete_book_data(); break;
//		case 6: exit(0);
//			break;
//		default:cout << "\a";
//		}
//
//
//	}
//}