#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>
#include "bandencentrale.h"

Bandencentrale::Bandencentrale(char naam[], char adres[])
{
#ifdef DEBUG
	std::cout << "#\tConstructed Bandencentrale()#\n";
	std::cout << "#\tSETTING KLANTEN OP LEGE KLANT#\n";
#endif

	for (int i = 0; i < MAX_KLANTEN; i++)
	{
		klanten[i] = nullptr;
	}

#ifdef DEBUG
	std::cout << "#\tSETTING ARTIKELEN OP LEEG ARTIKEL#\n";
#endif

	for (int i = 0; i < MAX_ARTIKELEN; i++)
	{
		artikels[i] = nullptr;
	}


#ifdef DEBUG
	std::cout << "#\tSETTING FACTUREN OP LEEG FACTUUR#\n";
#endif

	for (int i = 0; i < MAX_FACTUREN; i++)
	{
		facturen[i] = nullptr;
	}

	// FILES LADEN EN IN DE ARRAY ZETTEN.
	this->setNaam(naam);
	this->setAdres(adres);
	this->load(); // ALE GEGEVENS LADEN
}

Bandencentrale::~Bandencentrale()
{
#ifdef DEBUG
	std::cout << "#\tDestructed Bandencentrale()#\n";
#endif
}

/*
	ACTIES
*/
void Bandencentrale::save() //Saves klanten en artikels
{
	int i = 0;

	/*
		ARTIKELS SAVEN
	*/
	cout << "FILE OPENEn";
	//FILE OPENENEN
	ofstream binFile;
	binFile.open("save/artikels.bin", ios::binary);

	//Index zoeken voor lege artikelplaats
	while (i < MAX_ARTIKELEN) //Al onze artikels doorlopen
	{
		if (artikels[i] == nullptr) //Als deze nullptr is gaan we naar de volgende
		{
			i++;
			continue;
		}
		int type = artikels[i]->getType();
		cout << "WRITE TYPE  " << type;
		binFile.write((char*)&type, sizeof(type));

		if (type == 0)
		{
			cout << "WRITE BAND";
			binFile.write((char*)artikels[i], sizeof(Band));
		}
		else
		{
			cout << "WRITE VELG";
			binFile.write((char*)artikels[i], sizeof(Velg));
		}

		i++;
	}
	binFile.close();

	/*
		KLANTEN SAVEN
	*/
	cout << "FILE OPENEn";
	//FILE OPENENEN
	binFile.open("save/klanten.bin", ios::binary);
	i = 0;

	//Index zoeken voor lege artikelplaats
	while (i < MAX_KLANTEN) //Al onze artikels doorlopen
	{
		if (klanten[i] == nullptr) //Als deze nullptr is gaan we naar de volgende
		{
			i++;
			continue;
		}
		bool bedrijf = klanten[i]->isBedrijf();
		cout << "WRITE BEDRIJF OF NIET  " << bedrijf;
		binFile.write((char*)&bedrijf, sizeof(bedrijf));

		if (bedrijf)
		{
			cout << "WRITE BEDRIJF";
			binFile.write((char*)klanten[i], sizeof(BedrijfsKlant));
		}
		else
		{
			cout << "WRITE KLANT";
			binFile.write((char*)klanten[i], sizeof(Klant));
		}

		i++;
	}
	binFile.close();

	/*
	FACTUREN SAVEN
	*/
	cout << "FILE OPENEn";
	//FILE OPENENEN
	binFile.open("save/facturen.bin", ios::binary);
	i = 0;

	//Index zoeken voor lege artikelplaats
	while (i < MAX_FACTUREN) //Al onze artikels doorlopen
	{
		if (facturen[i] == nullptr) //Als deze nullptr is gaan we naar de volgende
		{
			i++;
			continue;
		}

		cout << "WRITE FACTUUR";
		binFile.write((char*)facturen[i], sizeof(Factuur));

		i++;
	}
	binFile.close();
}

void Bandencentrale::load() //Loades klanten en artikels
{
	int i = 0;

	/*
		ARTIKELS
	*/
	cout << "FILE OPENEn";
	//FILE OPENENEN
	ifstream binFile;
	binFile.open("save/artikels.bin", ios::binary);

	while (binFile.peek() != EOF)
	{
		int type;
		binFile.read((char*)&type, sizeof(type));

		if (type == 0)
		{
			Band b;
			cout << "LOAD BAND";
			binFile.read((char*)&b, sizeof(Band));
			this->addArtikel(new Band(b.getNaam(), b.getFabrikant(), b.getPrijs(), b.getDiameter(), b.getBreedte(), b.getHoogte(), b.getSnelheidsIndex(), b.getSeizoen()));
		}
		else
		{
			Velg v;
			cout << "LOAD VELG";
			binFile.read((char*)&v, sizeof(Velg));
			this->addArtikel(new Velg(v.getNaam(), v.getFabrikant(), v.getPrijs(), v.getDiameter(), v.getBreedte(), v.getKleur(), v.getAluminium()));
		}
		i++;
	}
	binFile.close();

	/*
		KLANTE LADEN
	*/
	binFile.open("save/klanten.bin", ios::binary);

	while (binFile.peek() != EOF)
	{
		bool bedrijf;
		binFile.read((char*)&bedrijf, sizeof(bedrijf));

		if (bedrijf)
		{	
			BedrijfsKlant b;
			cout << "LOAD BEDRIJF";
			binFile.read((char*)&b, sizeof(BedrijfsKlant));
			this->addKlant(new BedrijfsKlant(b.getNaam(), b.getAdres(), b.getSetKorting(), b.getSetKorting2(), b.getBtwNummer(), b.getVolumeKorting(), b.getBedrijfsKorting()));
		}
		else
		{
			Klant k;
			cout << "LOAD KLANT";
			binFile.read((char*)&k, sizeof(Klant));
			this->addKlant(new Klant(k.getNaam(), k.getAdres(), k.getSetKorting(), k.getSetKorting2()));
		}
		i++;
	}
	binFile.close();
}

//SETTERS
void Bandencentrale::setNaam(char naam[])
{
	strcpy_s(this->naam, naam);
	return;
}
void Bandencentrale::setAdres(char adres[])
{
	strcpy_s(this->adres, adres);
	return;
}

void Bandencentrale::addKlant(Klant* klant)
{
	int i = 0;

	//Index zoeken voor lege artikelplaats
	while (klanten[i] != nullptr)
		i++;

	klanten[i] = klant;
	return;
}

void Bandencentrale::addArtikel(Artikel* artikel)
{
	int i = 0;

	//Index zoeken voor lege artikelplaats
	while (artikels[i] != nullptr)
		i++;

	artikels[i] = artikel;
	return;
}

//GETTERS
Klant** Bandencentrale::getKlanten()
{
	return this->klanten;
}

Klant* Bandencentrale::getKlant(int id)
{
	return this->klanten[id];
}

Artikel** Bandencentrale::getArtikels()
{
	return this->artikels;
}

Artikel* Bandencentrale::getArtikel(int id)
{
	return this->artikels[id];
}

char* Bandencentrale::getNaam()
{
	return this->naam;
}

char* Bandencentrale::getAdres()
{
	return this->adres;
}

