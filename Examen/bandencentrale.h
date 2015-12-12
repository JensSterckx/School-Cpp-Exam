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

		//GETTERS
		char* getNaam();
		char* getAdres();

		Klant** getKlanten();
		Klant* getKlant(int);

		Artikel** getArtikels();
		Artikel* getArtikel(int);

	private:
		char naam[20];
		char adres[63];
		Klant* klanten[MAX_KLANTEN];
		Artikel* artikels[MAX_ARTIKELEN];
		Factuur* facturen[MAX_FACTUREN];
};