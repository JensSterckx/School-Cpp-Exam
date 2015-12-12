#include "velg.h"

Velg::Velg() {}
Velg::Velg(char naam[], char fabrikant[], float prijs, float diameter, int breedte, char kleur[], bool aluminium)
{
	std::cout << "#\tConstructed Velg()#\n";
	this->setNaam(naam);
	this->setFabrikant(fabrikant);
	this->setPrijs(prijs);
	this->setDiameter(diameter);
	this->setBreedte(breedte);
	this->setKleur(kleur);
	this->setAluminium(aluminium);
}

Velg::~Velg()
{
}

void Velg::setBreedte(int breedte)
{
	this->breedte = breedte;
	return;
}

void Velg::setKleur(char kleur[])
{
	strcpy_s(this->kleur, kleur);
	return;
}

void Velg::setAluminium(bool isalum)
{
	this->aluminium = isalum;
	return;
}

int Velg::getType()
{
	return this->type;
}

int Velg::getBreedte()
{
	return this->breedte;
}

char * Velg::getKleur()
{
	return this->kleur;
}

bool Velg::getAluminium()
{
	return this->aluminium;
}
