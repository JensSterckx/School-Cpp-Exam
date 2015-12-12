#pragma once
#include "klant.h"
class BedrijfsKlant :
	public Klant
{
public:
	BedrijfsKlant();
	BedrijfsKlant(char[], char[], float, float, char[], float, float);
	~BedrijfsKlant();

	char* getBtwNummer();
	float getVolumeKorting();
	float getBedrijfsKorting();

	void setBtwNummer(char[]);
	void setVolumeKorting(float);
	void setBedrijfsKorting(float);

private:
	char btwNummer[32];
	float volumeKorting;
	float bedrijfsKorting;
};

