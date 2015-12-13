#include "add_hulp.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void addBand(Bandencentrale* BC)
{
	char naam[20], fabrikant[64], seizoen;
	float prijs, diameter, breedte, hoogte, snelheidsIndex;
	int stock;

	system("cls");
	cout << "*            BAND TOEVOEGEN              *" << endl;

	cout << "Geef Naam[20] v/h product: ";
	cin.getline(naam, 20);
	cout << endl << "Geef fabrikant[64] v/h product: ";
	cin.getline(fabrikant, 64);

	cout << endl << "Geef de prijs(float) v/h product: ";
	cin >> prijs;

	cout << endl << "Geef de diameter(float) v/h product: ";
	cin >> diameter;

	cout << endl << "Geef de breedte(float) v/h product: ";
	cin >> breedte;

	cout << endl << "Geef de hoogte(float) v/h product: ";
	cin >> hoogte;

	cout << endl << "Geef de snelheidsIndex(float) v/h product: ";
	cin >> snelheidsIndex;

	cout << endl << "Geef de huidige stock(int) v/h product: ";
	cin >> stock;

	cin.ignore();
	cout << endl << "Geef de seizoensindex(char) A(ll) Z(omer) W(inter) M(odder) v/h product: ";
	cin.get(seizoen);

	BC->addArtikel(new Band(naam, fabrikant, prijs, diameter, breedte, hoogte, snelheidsIndex, seizoen, stock));
	return;
}

void addVelg(Bandencentrale* BC)
{
	char naam[20], fabrikant[64], kleur[64], tempalum;
	float prijs, diameter;
	int breedte, stock;
	bool aluminum = false;

	system("cls");
	cout << "*            VELG TOEVOEGEN              *" << endl;

	cout << "Geef Naam[20] v/h product: ";
	cin.getline(naam, 20);

	cout << endl << "Geef fabrikant[64] v/h product: ";
	cin.getline(fabrikant, 64);

	cout << endl << "Geef de prijs(float) v/h product: ";
	cin >> prijs;

	cout << endl << "Geef de diameter(float) v/h product: ";
	cin >> diameter;

	cout << endl << "Geef de breedte(int) v/h product: ";
	cin >> breedte;

	cout << endl << "Geef de huidige stock(int) v/h product: ";
	cin >> stock;

	cin.get();

	cout << endl << "Geef kleur[64] v/h product: ";
	cin.getline(kleur, 64);

	cout << endl << "Is de velg aluminium? (y/n)";
	cin >> tempalum;
	if (tempalum == 'y')
	{
		aluminum = true;
	}
	cin.get();


	BC->addArtikel(new Velg(naam, fabrikant, prijs, diameter, breedte, kleur, aluminum, stock));

	return;
}

void addKlant(Bandencentrale* BC)
{
	char naam[20], adres[64], tempbedr;
	float setkorting, setkorting2;

	system("cls");
	cout << "*            KLANT TOEVOEGEN              *" << endl;

	cout << "Geef Naam[20] v/d klant: ";
	cin.getline(naam, 20);

	cout << endl << "Geef adres[64] v/d klant: ";
	cin.getline(adres, 64);

	cout << endl << "Geef de setkorting(float) v/d klant: ";
	cin >> setkorting;

	cout << endl << "Geef de setkorting2(float) v/d klant: ";
	cin >> setkorting2;

	cout << endl << "Is de klant een bedrijf? (y/n)";
	cin >> tempbedr;
	cin.get();
	if (tempbedr == 'y')
	{
		char btwNummer[32];
		float volumeKorting, bedrijfsKorting;

		cout << endl << "Geef btwnummer[32] v/d klant: ";
		cin.getline(btwNummer, 64);

		cout << endl << "Geef de volumeKorting(float) v/d klant: ";
		cin >> volumeKorting;

		cout << endl << "Geef de bedrijfsKorting(float) v/d klant: ";
		cin >> bedrijfsKorting;

		BC->addKlant(new BedrijfsKlant(naam, adres, setkorting, setkorting2, btwNummer, volumeKorting, bedrijfsKorting));
	}
	else
	{
		BC->addKlant(new Klant(naam, adres, setkorting, setkorting2));
	}
	return;
}
