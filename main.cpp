#include <iostream>
#include "Commodity.h"
#include <string>
using namespace std;
void ShowMenu();
void ShowPlaces(Commodity*temp[], const int SIZE);
void Fill(Commodity* com);
int main()
{
	const size_t SIZE = 20;
	Commodity*storage[SIZE] = {};
	char choise;
	string user;
	string name;
	do
	{
		system("cls");
		ShowMenu();
		cout << "enter choise: ";
		cin >> choise;

		switch (choise)
		{
		case '1':
			ShowPlaces(storage, SIZE);
			
			cout << "enter your name: ";
			cin >> user;
			cout << "enter your product name: ";
			cin >> name;
			for (int i = 0; i < SIZE; i++)
			{
				if (storage[i] == nullptr)
					continue;
				if (storage[i]->GetName() == name && storage[i]->GetUsername() == user)
				{
					storage[i] == nullptr;
					cout << "your product was taked succesfully\n";
					break;
				}
			}
			break;
		case '2':
			ShowPlaces(storage, SIZE);
			int choice;
			do
			{
				cout << "enter place: ";
				cin >> choice;
			} while (choice<0 || choice>SIZE || storage[choice] != nullptr);

			storage[choice] = new Commodity();
			Fill(storage[choice]);
			break;
		case '3':
			ShowPlaces(storage, SIZE);
			break;
		case '4':
			
			do
			{
				cout << "enter place: ";
				cin >> choice;
			} while (choice<0 || choice>SIZE || storage[choice] != nullptr);
			cout<<"Product name: "<<storage[choice]->GetName()<<endl;
			cout << "User name: " << storage[choice]->GetUsername() << endl;
			cout << "Time: " << storage[choice]->GetTime() << endl;
			cout << "Square: " << storage[choice]->GetSquare() << endl;
			cout << "Price: " << storage[choice]->GetPrice() << endl;
			break;
		case '5':

			cout << "enter your name: ";
			cin >> user;
			cout << "enter your product name: ";
			cin >> name;
			for (int i = 0; i < SIZE; i++)
			{
				if (storage[i] == nullptr)
					continue;
				if (storage[i]->GetName() == name && storage[i]->GetUsername() == user)
				{
					cout << "enter how much you want to extend: ";
					cin >> choice;
					storage[i]->SetPrice(storage[i]->GetPrice() + (choice * storage[i]->GetSquare()));
					break;
				}
			}

			break;
		case '0':

			break;
		default:
			break;
		}
		system("pause");

		for (int i = 0; i < SIZE; i++)
		{
			if (storage[i] == nullptr)
				continue;
			else
			{
				if (storage[i]->GetTime() == 0)
				{
					storage[i]->SetPrice(storage[i]->GetPrice() + storage[i]->GetSquare());
					storage[i]->SetTime(1);
					cout << "place number " << i << "was extented\n";
				}
				else
					storage[i]->SetTime(storage[i]->GetTime() - 1);
			}
		}
	} while (choise != '0');
	system("pause");
	return 0;
}

void ShowMenu()
{
	cout << "*************************\n";
	cout << "*1)Take Product         *\n";
	cout << "*2)Put Product for save *\n";
	cout << "*3)Show all places      *\n";
	cout << "*4)Product info         *\n";
	cout << "*5)To extend            *\n";
	cout << "*0)Exit                 *\n";
	cout << "*************************\n";
}

void ShowPlaces(Commodity * temp[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (temp[i] == nullptr)
			cout << i << ") " << "Free  \t";
		else
			cout << i << ") " << "Lock  \t";
		if (i % 2 != 0)
			cout << endl;
	}
}

void Fill(Commodity* com)
{
	double square;
	int time;
	string name;
	string userName;

	cout << "Enter square: ";
	cin >> square;
	cout << "Enter time: ";
	cin >> time;
	cout << "Enter product name: ";
	cin >> name;
	cout << "Enter username: ";
	cin >> userName;
	com->SetSquare(square);
	com->SetName(name);
	com->SetTime(time);
	com->SetUser(userName);
	com->SetPrice(time * square);
}
