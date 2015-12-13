#include "band.h"

Band::Band() {}
Band::Band(char naam[], char fabrikant[], float prijs, float diameter, float breedte, float hoogte, float snelheidsindex, char seizoen, int stock)
{
	std::cout << "#\tConstructed Band()#\n";
	this->setNaam(naam);
	this->setFabrikant(fabrikant);
	this->setPrijs(prijs);
	this->setDiameter(diameter);
	this->setBreedte(breedte);
	this->setHoogte(hoogte);
	this->setSnelheidsIndex(snelheidsindex);
	this->setSeizoen(seizoen);
	this->setStock(stock);
}

Band::~Band()
{
}

void Band::setBreedte(float breedte)
{
	this->breedte = breedte;
}

void Band::setHoogte(float hoogte)
{
	this->hoogte = hoogte;
	return;
}

void Band::setSnelheidsIndex(float index)
{
	this->snelheidsIndex = index;
	return;
}

void Band::setSeizoen(char seizoen)
{
	this->seizoen = seizoen;
}

int Band::getType()
{
	return this->type;
}

float Band::getBreedte()
{
	return this->breedte;
}

float Band::getHoogte()
{
	return this->hoogte;
}

float Band::getSnelheidsIndex()
{
	return this->snelheidsIndex;
}

char Band::getSeizoen()
{
	return this->seizoen;
}
