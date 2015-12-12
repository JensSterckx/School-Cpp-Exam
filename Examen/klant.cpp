#include "klant.h"

Klant::Klant() {}
Klant::Klant(char naam[], char adres[], float setkorting, float setkorting2)
{
	std::cout << "#\tConstructed Klant()#\n";
	this->setNaam(naam);
	this->setAdres(adres);
	this->setSetKorting(setkorting);
	this->setSetKorting2(setkorting2);
	this->setBedrijf(false);
}


Klant::~Klant()
{
	std::cout << "#\tDestructed Klant()#\n";
}

//SETTERS
void Klant::setNaam(char naam[])
{
	strcpy_s(this->naam, naam);
	return;
}

void Klant::setAdres(char adres[])
{
	strcpy_s(this->adres, adres);
	return;
}

void Klant::setSetKorting(float setKorting)
{
	this->setKorting = setKorting;
	return;
}

void Klant::setSetKorting2(float setKorting2)
{
	this->setKorting2 = setKorting2;
	return;
}

void Klant::setBedrijf(bool bedrijf)
{
	this->bedrijf = bedrijf;
	return;
}

//GETTERS
char* Klant::getNaam()
{
	return this->naam;
}

char* Klant::getAdres()
{
	return this->adres;
}

float Klant::getSetKorting()
{
	return this->setKorting;
}

float Klant::getSetKorting2()
{
	return this->setKorting2;
}

bool Klant::isBedrijf()
{
	return this->bedrijf;
}


