#pragma once
#include <iostream>
#include <string>

class Klant
{
public:
	Klant();
	Klant(char[], char[], float, float);
	virtual ~Klant();

	//SETTERS
	void setNaam(char[]);
	void setAdres(char[]);
	void setSetKorting(float);
	void setSetKorting2(float);
	void setBedrijf(bool);

	//GETTERS
	char* getNaam();
	char* getAdres();
	float getSetKorting();
	float getSetKorting2();
	bool isBedrijf();

private:
	char naam[20];
	char adres[64];
	float setKorting;
	float setKorting2;
	bool bedrijf;
};

