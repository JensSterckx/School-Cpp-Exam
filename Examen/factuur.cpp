#include "factuur.h"

Factuur::Factuur()
{
	//Setting defaults

	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
		this->artikels[i] = nullptr;
	

	//Construct tijd zetten
	time_t temp = time(0);
	strcpy_s(datum, ctime(&temp));
}

Factuur::Factuur(Klant* klant)
{
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
		this->artikels[i] = nullptr;

	//Construct tijd zetten
	time_t temp = time(0);
	strcpy_s(datum, ctime(&temp));

	this->setKlant(klant);
	return;
}

Factuur::~Factuur()
{
}

void Factuur::setKlant(Klant* klant)
{
	this->klant = klant;
	return;
}

void Factuur::setKorting(float korting)
{
	this->korting = korting;
	return;
}

Klant* Factuur::getKlant()
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

char* Factuur::getDatum()
{
	return datum;
}

void Factuur::setDatum(char dat[])
{
	strcpy_s(this->datum, dat);
	return;
}

void Factuur::addArtikel(Artikel* art)
{
	int i = 0;

	//Index zoeken voor lege artikelplaats
	while (artikels[i] != nullptr)
		i++;

	artikels[i] = art;
	return;
}
void Factuur::delArtikel(int id)
{
	this->artikels[id] = nullptr;
	return;
}
void Factuur::sluiten()
{
	totaalPrijs = 0;
	korting = 0;
	int itemcount = 0;
	float tempprijs = 0;
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
	{
		if (artikels[i] == nullptr)
			continue;

		totaalPrijs += artikels[i]->getPrijs();
		itemcount++;
	}

	/* KORTING */
	if (itemcount >= 2)
	{
		tempprijs = totaalPrijs;
		totaalPrijs *= klant->getSetKorting();
		totaalPrijs /= 100;
		korting += totaalPrijs;
		totaalPrijs = tempprijs - totaalPrijs;
	}
	if (itemcount >= 4)
	{
		tempprijs = totaalPrijs;
		totaalPrijs *= klant->getSetKorting2();
		totaalPrijs /= 100;
		korting += totaalPrijs;
		totaalPrijs = tempprijs - totaalPrijs;
	}
	if (klant->isBedrijf())
	{
		BedrijfsKlant* temp = (BedrijfsKlant*)klant;
		tempprijs = totaalPrijs;
		totaalPrijs *= temp->getBedrijfsKorting();
		totaalPrijs /= 100;
		korting += totaalPrijs;
		totaalPrijs = tempprijs - totaalPrijs;

		if (itemcount == 10)
		{
			tempprijs = totaalPrijs;
			totaalPrijs *= temp->getVolumeKorting();
			totaalPrijs /= 100;
			korting += totaalPrijs;
			totaalPrijs = tempprijs - totaalPrijs;
		}
	}
}

void Factuur::fixNietLegeArtikels()
{
	//Voor een of andere reden, bij het maken van een factuur & inlezen van de file
	// Zijn de eerste 2 artikels niet naar NULL
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
		this->artikels[i] = nullptr;
}