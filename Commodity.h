#pragma once
#include <string>
#include <iostream>
using namespace std;
class Commodity
{
	double square;
	string name;
	string userName;
	int time;
	double price;
public:
	Commodity(double square=1,string name="Unnamed Commodity",string username="Unnamed user",int time=1);
	~Commodity();
	void SetSquare(double square);
	void SetName(string name);
	void SetUser(string user);
	void SetTime(int time);
	void SetPrice(double price);

	double GetSquare();
	string GetName();
	string GetUsername();
	int GetTime();
	double GetPrice();
	
	void ShowInfo();
};

