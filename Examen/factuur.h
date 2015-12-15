#pragma once

#include "klant.h"
#include "band.h"
#include "velg.h"
#include <ctime>

#define MAX_ARTIKELEN_PER_FACTUUR 10

class Factuur
{
public:
	Factuur();
	Factuur(Klant*);
	~Factuur();

	void setKlant(Klant*);
	void setKorting(float);
	void addArtikel(Artikel*);

	Klant* getKlant();
	float getKorting();

	Artikel** getArtikels();

	char* getDatum();

	float getTotaalPrijs();

	void sluiten();

	void fixNietLegeArtikels();

private:
	float korting;
	float totaalPrijs;
	char datum[64];

	Klant* klant;
	Artikel* artikels[MAX_ARTIKELEN_PER_FACTUUR];
};

