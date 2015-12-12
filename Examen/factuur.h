#pragma once

#include "klant.h"
#include "band.h"
#include "velg.h"

class Factuur
{
public:
	Factuur();
	~Factuur();

	void setFactuurNummer(int);
	void setKlant(Klant);
	void setKorting(float);

	int getFactuurNummer();
	Klant getKlant();
	float getKorting();

	Artikel** getArtikels();

	float getTotaalPrijs();

private:
	int factuurNummer;
	Klant klant;
	float korting;

	Artikel* artikels[10];

	float totaalPrijs;
};

