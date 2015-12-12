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
	strcpy(this->naam, naam);
	return;
}

void Artikel::setFabrikant(char fabrikant[])
{
	strcpy(this->fabrikant, fabrikant);
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
