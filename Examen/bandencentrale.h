//ZAL OUTPUTS REGELEN
#define DEBUG

#include "klant.h"
#include "bedrijfsklant.h"
#include "band.h"
#include "factuur.h"
#include "velg.h"

using namespace std;

#define MAX_KLANTEN 100
#define MAX_ARTIKELEN 100
#define MAX_FACTUREN 100

#pragma once
class Bandencentrale
{
	public:
		Bandencentrale(char[], char[]);
		~Bandencentrale();

		//ACTIES
		void save();
		void load();

		//SETTERS
		void setNaam(char[]);
		void setAdres(char[]);

		void addKlant(Klant*);
		void addArtikel(Artikel*);
		void addFactuur(Factuur*);

		Factuur* openFactuur(Klant*);

		//GETTERS
		char* getNaam();
		char* getAdres();

		Klant** getKlanten();
		Klant* getKlant(int);

		Artikel** getArtikels();
		Artikel* getArtikel(int);
		void deleteArtikel(int);

		Factuur** getFacturen();
		Factuur* getFactuur(int);
		Factuur* getHuidigFactuur();
		void sluitHuidigFactuur(bool);

	private:
		char naam[20];
		char adres[63];
		Klant* klanten[MAX_KLANTEN];
		Artikel* artikels[MAX_ARTIKELEN];
		Factuur* facturen[MAX_FACTUREN];
		Factuur* open_factuur;
};