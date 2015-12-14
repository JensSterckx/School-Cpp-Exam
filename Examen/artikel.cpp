#include "artikel.h"

Artikel::Artikel()
{
	std::cout << "#\tConstructed Artikel()#\n";
}

Artikel::~Artikel()
{
	std::cout << "#\tDestructed Artikel()#\n";
}

//SETTERS
void Artikel::setNaam(char naam[])
{
	strcpy_s(this->naam, naam);
	return;
}

void Artikel::setFabrikant(char fabrikant[])
{
	strcpy_s(this->fabrikant, fabrikant);
	return;
}

void Artikel::setPrijs(float prijs)
{
	this->prijs = prijs;
	return;
}

void Artikel::setDiameter(float diameter)
{
	this->diameter = diameter;
	return;
}

void Artikel::setStock(int stock)
{
	this->stock = stock;
	return;
}


//GETTERS
char* Artikel::getNaam()
{
	return this->naam;
}

char* Artikel::getFabrikant()
{
	return this->fabrikant;
}

float Artikel::getPrijs()
{
	return this->prijs;
}

float Artikel::getDiameter()
{
	return this->diameter;
}

int Artikel::getStock()
{
	return this->stock;
}