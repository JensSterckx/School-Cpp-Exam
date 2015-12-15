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

	open_factuur = nullptr;

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
		binFile.write((char*)&bedrijf, sizeof(bool));

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

		//FACTUUR
		cout << "WRITE FACTUUR";
		binFile.write((char*)facturen[i], sizeof(Factuur));

		//KLANT
		bool bedrijf = facturen[i]->getKlant()->isBedrijf();
		cout << "WRITE FACT BEDRIJF OF NIET  " << bedrijf;
		binFile.write((char*)&bedrijf, sizeof(bool));
		if (bedrijf)
		{
			cout << "WRITE FACT BEDRIJF";
			BedrijfsKlant* tmp = (BedrijfsKlant*)facturen[i]->getKlant();
			binFile.write((char*)tmp, sizeof(BedrijfsKlant));
		}
		else
		{
			cout << "WRITE FACT KLANT";
			Klant* tmp = (Klant*)facturen[i]->getKlant();
			binFile.write((char*)tmp, sizeof(Klant));
		}

		//ARTIKELS
		cout << "WRITE ARTIKELS OF FACTUUR";
		int j = 0;
		Artikel** arts = facturen[i]->getArtikels();
		while (j < MAX_ARTIKELEN_PER_FACTUUR) //Al onze artikels doorlopen
		{
			int type;
			if (arts[j] == nullptr) //Als deze nullptr is schrijven we als type -1 weg (Voor uitlezen)
			{
				type = -1;
			}
			else
			{
				type = arts[j]->getType();
			}
			cout << "WRITE TYPE  " << type;
			binFile.write((char*)&type, sizeof(int));
			if (type == 0)
			{
				cout << "WRITE FACT BAND";
				binFile.write((char*)arts[j], sizeof(Band));
			}
			else if(type == 1)
			{
				cout << "WRITE FACT VELG";
				binFile.write((char*)arts[j], sizeof(Velg));
			}
			j++;
		}
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
			this->addArtikel(new Band(b.getNaam(), b.getFabrikant(), b.getPrijs(), b.getDiameter(), b.getBreedte(), b.getHoogte(), b.getSnelheidsIndex(), b.getSeizoen(), b.getStock()));
		}
		else
		{
			Velg v;
			cout << "LOAD VELG";
			binFile.read((char*)&v, sizeof(Velg));
			this->addArtikel(new Velg(v.getNaam(), v.getFabrikant(), v.getPrijs(), v.getDiameter(), v.getBreedte(), v.getKleur(), v.getAluminium(), v.getStock()));
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

	/*
	FACTUREN LADEN
	*/
	binFile.open("save/facturen.bin", ios::binary);

	int type;
	while (binFile.peek() != EOF)
	{
		//Structuur is
		/*
		FACTUUR
		BOOL true: bedrijf false: klant
		KLANT
		TYPE 0 = band, 1 = velg, -1 = leeg
		ART
		TYPE
		ART
		....
		
		*/
		Factuur tfact;
		binFile.read((char*)&tfact, sizeof(Factuur));
		tfact.fixNietLegeArtikels(); //Bug ofzo? De constructor maakt de eerste 2 artikels niet leeg

		Factuur* finalfact = new Factuur(tfact.getKlant());
		finalfact->setDatum(tfact.getDatum());

		bool bedrijf;
		binFile.read((char*)&bedrijf, sizeof(bool));

		if (bedrijf)
		{
			BedrijfsKlant b;
			cout << "LOAD BEDRIJF";
			binFile.read((char*)&b, sizeof(BedrijfsKlant));
			finalfact->setKlant(new BedrijfsKlant(b.getNaam(), b.getAdres(), b.getSetKorting(), b.getSetKorting2(), b.getBtwNummer(), b.getVolumeKorting(), b.getBedrijfsKorting()));
		}
		else
		{
			Klant k;
			cout << "LOAD KLANT";
			binFile.read((char*)&k, sizeof(Klant));
			finalfact->setKlant(new Klant(k.getNaam(), k.getAdres(), k.getSetKorting(), k.getSetKorting2()));
		}

		for (int j = 0; j < MAX_ARTIKELEN_PER_FACTUUR; j++)
		{
			binFile.read((char*)&type, sizeof(int));
			if (type == 0)
			{
				Band b;
				cout << "LOAD FACT BAND";
				binFile.read((char*)&b, sizeof(Band));
				finalfact->addArtikel(new Band(b.getNaam(), b.getFabrikant(), b.getPrijs(), b.getDiameter(), b.getBreedte(), b.getHoogte(), b.getSnelheidsIndex(), b.getSeizoen(), -1));
			}
			else if(type == 1)
			{
				Velg v;
				cout << "LOAD FACT VELG";
				binFile.read((char*)&v, sizeof(Velg));
				finalfact->addArtikel(new Velg(v.getNaam(), v.getFabrikant(), v.getPrijs(), v.getDiameter(), v.getBreedte(), v.getKleur(), v.getAluminium(), -1));
			}
		}
		finalfact->sluiten(); //Prijzen en kortingen herberekenen
		this->addFactuur(finalfact);
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
void Bandencentrale::addFactuur(Factuur* factuur)
{
	int i = 0;

	//Index zoeken voor lege artikelplaats
	while (facturen[i] != nullptr)
		i++;

	facturen[i] = factuur;
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

void Bandencentrale::deleteArtikel(int id)
{
	delete this->artikels[id];
	this->artikels[id] = nullptr;
	return;
}


void Bandencentrale::deleteKlant(int id)
{
	delete this->klanten[id];
	this->klanten[id] = nullptr;
	return;
}

char* Bandencentrale::getNaam()
{
	return this->naam;
}

char* Bandencentrale::getAdres()
{
	return this->adres;
}

Factuur** Bandencentrale::getFacturen()
{
	return this->facturen;
}

Factuur* Bandencentrale::getFactuur(int id)
{
	return this->facturen[id];
}

// FACTUREN
Factuur* Bandencentrale::openFactuur(Klant* klant)
{
	this->open_factuur = new Factuur(klant);
	return this->open_factuur;
}

Factuur* Bandencentrale::getHuidigFactuur()
{
	return this->open_factuur;
}

void Bandencentrale::sluitHuidigFactuur(bool opslaan)
{
	//als opslaan true is, voegen we hem toe tot facturen, anders delete
	if (opslaan)
	{
		open_factuur->sluiten(); //Prijzen berekenen
		this->addFactuur(open_factuur); //huidige factuur pointer bij facturen voegen
		
		//open_factuur terug naar null laten verwijzen.
		//NIET DELETE DOEN, want dan is de warde in facturen ook leeg
	}
	else
	{
		//Nu mogen we wel deleten, niet meer nodig
		delete this->open_factuur;
	}
	//open_factuur terug naar null laten verwijzen.
	this->open_factuur = nullptr;
}