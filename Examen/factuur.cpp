#include "factuur.h"

Factuur::Factuur()
{
}

Factuur::~Factuur()
{
}

void Factuur::setFactuurNummer(int nummer)
{
	this->factuurNummer = nummer;
	return;
}

void Factuur::setKlant(Klant klant)
{
	this->klant = klant;
	return;
}

void Factuur::setKorting(float korting)
{
	this->korting = korting;
	return;
}

int Factuur::getFactuurNummer()
{
	return this->factuurNummer;
}

Klant Factuur::getKlant()
{
	return this->klant;
}

float Factuur::getTotaalPrijs()
{
	return this->totaalPrijs;
}

float Factuur::getKorting()
{
	return this->korting;
}

Artikel ** Factuur::getArtikels()
{
	return this->artikels;
}
