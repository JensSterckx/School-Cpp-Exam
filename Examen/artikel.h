#pragma once
#include <iostream>

class Artikel
{
public:
	Artikel();
	virtual ~Artikel();

	//SETTERS
	void setNaam(char[]);
	void setFabrikant(char[]);
	void setPrijs(float);
	void setDiameter(float);
	void setStock(int);

	//GETTERS
	char* getNaam();
	char* getFabrikant();
	float getPrijs();
	float getDiameter();
	virtual int getType() = 0;
	int getStock();

	void decrementStock();
	void incrementStock();

private:
	char naam[20];
	char fabrikant[64];
	float prijs;
	float diameter;
	int stock;
};
