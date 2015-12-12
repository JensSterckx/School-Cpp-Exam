#include "bedrijfsklant.h"


BedrijfsKlant::BedrijfsKlant(){}
BedrijfsKlant::BedrijfsKlant(char naam[], char adres[], float setkorting, float setkorting2, char btwNummer[], float volumeKorting, float bedrijfsKorting)
{
	std::cout << "#\tConstructed BedrijfsKlant()#\n";
	this->setNaam(naam);
	this->setAdres(adres);
	this->setSetKorting(setkorting);
	this->setSetKorting2(setkorting2);

	this->setBedrijf(true);
	this->setBtwNummer(btwNummer);
	this->setVolumeKorting(volumeKorting);
	this->setBedrijfsKorting(bedrijfsKorting);
}

BedrijfsKlant::~BedrijfsKlant()
{
}

//GETTERS
char * BedrijfsKlant::getBtwNummer()
{
	return this->btwNummer;
}

float BedrijfsKlant::getVolumeKorting()
{
	return this->volumeKorting;
}

float BedrijfsKlant::getBedrijfsKorting()
{
	return this->bedrijfsKorting;
}

//SETTERS
void BedrijfsKlant::setBtwNummer(char btw[])
{
	strcpy_s(this->btwNummer, btw);
	return;
}

void BedrijfsKlant::setVolumeKorting(float volumekorting)
{
	this->volumeKorting = volumekorting;
	return;
}

void BedrijfsKlant::setBedrijfsKorting(float korting)
{
	this->bedrijfsKorting = korting;
	return;
}
