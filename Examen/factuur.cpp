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

void Factuur::addArtikel(Artikel* art)
{
	int i = 0;

	//Index zoeken voor lege artikelplaats
	while (artikels[i] != nullptr)
		i++;

	artikels[i] = art;
	return;
}
void Factuur::sluiten()
{
	totaalPrijs = 0;
	korting = 0;
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
	{
		if (artikels[i] == nullptr)
			continue;

		totaalPrijs += artikels[i]->getPrijs();
	}
}

void Factuur::fixNietLegeArtikels()
{
	//Voor een of andere reden, bij het maken van een factuur & inlezen van de file
	// Zijn de eerste 2 artikels niet naar NULL
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
		this->artikels[i] = nullptr;
}