#include "main.h"
#include "add_hulp.h"
#include <iomanip>

using namespace std;

/*
	GLOBALE BANDENCENTRALE VARIABELE
	reden: Anders moet ik deze met elke functie oproep van een menu mee geven.
*/
Bandencentrale* BC;

int main()
{
	int in;

	/*
		INIT BANDENCENTRALE
	*/
	BC = new Bandencentrale("Jens Shop", "Apenland Bananenstraat 93");

	do {
		system("cls");
		cout << "WELKOM << " << BC->getNaam() << " >>" << endl;
		cout << "(" << BC->getAdres() << ")" << endl;
		cout << "*********************************************" << endl;
		cout << "*                  LOG IN                   *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Werkgever (Admin)                      *" << endl;
		cout << "* 2. Werknemer                              *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:// Quit
			break;
		case 1:
			adminMenu();
			break;
		case 2:
			userMenu();
		default:
			printVerkeerdeInput();
			break;
		}
	} while (in != 0);

	//Save just to be sure.
	BC->save();
	return 0;
}

/*
	INPUTS
*/
int getNumericInput()
{
	int choice;
	cin >> choice;
	if (!cin) // or if(cin.fail())
	{	//No numeric input
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input	next, request user reinput
	}
	else
	{
		cin.get();
	}
	return choice;
}

void printVerkeerdeInput()
{
	cout << endl << "Verkeerde keuze, druk op een toets om verder te gaan." << endl;

	//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cin.get();

	return;
}


/*
	ACTIONS
*/


/*
	MENU PRINTS
*/
//ADMIN
void adminMenu()
{
	int in;

	do {
		//Scherm clearen
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                   ADMIN                   *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Artikels                               *" << endl;
		cout << "* 2. Klanten                                *" << endl;
		cout << "* 3. Facturen                               *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:// Quit
			break;
		case 1:
			adminArtikelMenu();
			break;
		case 2:
			adminKlantenMenu();
			break;
		case 3:
			factuurMenu();
		default:
			printVerkeerdeInput();
			break;
		}
	} while (in != 0);

}
void adminArtikelMenu()
{
	int in;

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                 ARTIKELS                A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Bekijken                               *" << endl;
		cout << "* 2. Toevoegen                              *" << endl;
		cout << "* 3. Verwijderen                            *" << endl;
		cout << "* 4. Stock                                  *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:// Quit
			break;
		case 1:
			viewArtikelMenu();
			break;
		case 2:
			addArtikelMenu();
			break;
		case 3:
			deleteArtikelMenu();
			break;
		case 4:
			viewStockMenu();
			break;
		default:
			printVerkeerdeInput();
			break;
		}
	} while (in != 0);
	return;
}

void adminKlantenMenu()
{
	int in;

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                  KLANTEN                A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Bekijken                               *" << endl;
		cout << "* 2. Toevoegen                              *" << endl;
		cout << "* 3. Verwijderen                            *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:// Quit
			break;
		case 1:
			break;
		case 2:
			addKlant(BC);
			break;
		case 3:
			break;
		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void viewArtikelMenu()
{
	/*
	Het programma moet de stock kunnen weergeven van alle banden en velgen die er verkocht worden. 
	Ook indien ze niet voorradig zijn moeten deze weergegeven worden. 
	De stock moet volledig kunnen weergegeven worden, 
	maar er moet ook kunnen gefilterd worden op banden of velgen. 
	Ook hadden ze graag kunnen filteren op maat
	*/
	int in;
	Artikel** arts = BC->getArtikels();

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*              ARTIKEL ZOEKEN             A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Alle Artikels                          *" << endl;
		cout << "* 2. Specifiek  (Met Art nummer)            *" << endl;
		cout << "* 3. Zoeken  (Velgen of Banden)             *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:
			break;

		case 1:
			//Alle artikels
			system("cls");
			cout << "*********************************************" << endl;
			cout << "*             ARTIKELS OPSOMMEN           A *" << endl;
			cout << "*                 ---------                 *" << endl;
			cout << "ART NUMMER         ART NAAM    ART TYPE      " << endl << endl;

			for (int i = 0; i < MAX_ARTIKELEN; i++)
			{
				if (arts[i] == nullptr)
					continue;

				cout << setw(3) << i << ":" << setw(23) << arts[i]->getNaam();
				if (arts[i]->getType() == 0)
				{
					cout << setw(10) << "'BAND'";
				}
				else
				{
					cout << setw(10) << "'VELG'";
				}

				if (arts[i]->getStock() < 2)
				{
					cout << setw(15) << "!CHECK STOCK!";
				}
				cout << endl;
			}

			cout << endl << "Druk op enter om door te gaan" << endl;
			cin.get();

			break;

		case 2:
			//Specifiek artikelnummer
			printArtikelM();
			break;

		case 3:
			//Zoeken
			printZoekArtM();
			break;

		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void printZoekArtM()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*             ARTIKEL INFORMATIE          A *" << endl;
	cout << "*                 ---------                 *" << endl;
	cout << "Zoeken op:" << endl;
	cout << "1. Banden" << endl;
	cout << "2. Velgen" << endl;
	cout << "Keuze: ";

	int in = getNumericInput();
	in -= 1;

	Artikel** arts = BC->getArtikels();
	int i = 0;
	cout << endl << "ART NUMMER         ART NAAM          " << endl << endl;
	while (i < MAX_ARTIKELEN)
	{
		if (arts[i] == nullptr)
		{
			i++;
			continue;
		}

		if (arts[i]->getType() == in)
		{
			cout << setw(3) << i << ":" << setw(23) << arts[i]->getNaam();
			if (arts[i]->getStock() < 2)
			{
				cout << setw(15) << "!CHECK STOCK!";
			}
			cout << endl;
		}
		i++;
	}
	cout << endl << "Druk op enter om door te gaan" << endl;
	cin.get();
}

void printArtikelM()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*             ARTIKEL INFORMATIE          A *" << endl;
	cout << "*                 ---------                 *" << endl;
	cout << "Geef het artikel id: ";

	int in = getNumericInput();
	Artikel* art = BC->getArtikels()[in];
	if (art == nullptr)
	{
		cout << endl << "Artikel niet gevonden!" << endl;
		cin.get();
		return;
	}

	cout << "#############################################" << endl;
	cout << "ID: " << in << endl;
	cout << "Naam: " << art->getNaam() << endl;
	cout << "Fabrikant: " << art->getFabrikant() << endl;
	cout << "Prijs: " << art->getPrijs() << endl;
	cout << "Diameter: " << art->getDiameter() << endl;
	cout << "Stock: " << art->getStock() << endl;
	if (art->getType() == 0)
	{
		//BAND
		cout << "TYPE: BAND" << endl;
		Band* tempb = (Band*)art;

		cout << "Breedte: " << tempb->getBreedte() << endl;
		cout << "Hoogte: " << tempb->getHoogte() << endl;
		cout << "Snelheids Index: " << tempb->getSnelheidsIndex() << endl;
		cout << "Seizoen: " << tempb->getSeizoen() << endl;
	}
	else
	{
		//VELG
		cout << "TYPE: VELG" << endl;
		Velg* tempv = (Velg*)art;

		cout << "Breedte: " << tempv->getBreedte() << endl;
		cout << "Kleur: " << tempv->getKleur() << endl;
		cout << "Is aluminium: " << tempv->getAluminium() << endl;
	}

	cout << "Druk op enter om verder te gaan...";
	cin.get();

	return;
}

void addArtikelMenu()
{
	int in;

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*            ARTIKEL TOEVOEGEN            A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Band                                   *" << endl;
		cout << "* 2. Velg                                   *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Stop                                   *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:
			break;

		case 1:
			addBand(BC);		
			break;

		case 2:
			addVelg(BC);
			break;

		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void deleteArtikelMenu()
{
	return;
}

void viewStockMenu()
{
	return;
}


void factuurMenu()
{
	return;
}


//USERS
void userMenu()
{
	//Scherm clearen
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*                   USER                    *" << endl;
	cout << "*                                           *" << endl;
	cout << "* 0. Stop                                   *" << endl;
	cout << "*********************************************" << endl;
	cout << "Uw Keuze: ";
	getNumericInput();
}