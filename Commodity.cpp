#include "Commodity.h"



Commodity::Commodity(double square, string name, string username, int time)
{
	SetName(name);
	SetSquare(square);
	SetUser(username);
	SetTime(time);
	SetPrice(time * square);
}


Commodity::~Commodity()
{
}

void Commodity::SetSquare(double square)
{
	if (square < 0)
		square = 1;
	this->square = square;
}

void Commodity::SetName(string name)
{
	this->name = name;
}

void Commodity::SetUser(string user)
{
	this->userName = user;
}

void Commodity::SetTime(int time)
{
	if (time < 0)
		time = 1;
	this->time = time;
}

void Commodity::SetPrice(double price)
{
	if (price < 0)
		price = 10;
	this->price = price;
}

double Commodity::GetSquare()
{
	return square;
}

string Commodity::GetName()
{
	return name;
}

string Commodity::GetUsername()
{
	return userName;
}

int Commodity::GetTime()
{
	return time;
}

double Commodity::GetPrice()
{
	return price;
}

void Commodity::ShowInfo()
{
	cout << "Product name: " << name << endl;;
	cout << "Square: " << square<<endl;
	cout << "Time: " << time << endl;
	cout << "Price: " << price << endl;
	cout << "User name: " << userName << endl;
}
