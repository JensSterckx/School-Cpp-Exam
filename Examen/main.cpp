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
			break;
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
			viewKlant();
			break;
		case 2:
			addKlant(BC);
			break;
		case 3:
			deleteKlantMenu();
			break;
		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void viewKlant()
{
	int in;
	Klant** klants = BC->getKlanten();

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*               KLANT ZOEKEN              A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Alle Klanten                           *" << endl;
		cout << "* 2. Specifiek  (Met Klant nummer)          *" << endl;
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
			cout << "*             KLANTEN OPSOMMEN            A *" << endl;
			cout << "*                 ---------                 *" << endl;
			cout << "KLANT NUMMER      KLANT NAAM   KLANT TYPE    " << endl << endl;

			for (int i = 0; i < MAX_KLANTEN; i++)
			{
				if (klants[i] == nullptr)
					continue;

				cout << setw(3) << i << ":" << setw(23) << klants[i]->getNaam();
				if (klants[i]->isBedrijf())
				{
					cout << setw(12) << "'BEDRIJF'";
				}
				else
				{
					cout << setw(12) << "'PERSOON'";
				}
				cout << endl;
			}

			cout << endl << "Druk op enter om door te gaan" << endl;
			cin.get();

			break;

		case 2:
			//Specifiek artikelnummer
			printKlantM();
			break;

		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void printKlantM()
{
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*              KLANT INFORMATIE           A *" << endl;
	cout << "*                 ---------                 *" << endl;
	cout << "Geef het klant id: ";

	int in = getNumericInput();
	Klant* klan = BC->getKlant(in);
	if (klan == nullptr)
	{
		cout << endl << "Klant niet gevonden!" << endl;

		cout << endl << "Druk op enter om verder te gaan...";
		cin.get();
		return;
	}

	cout << endl << "#############################################" << endl;
	cout << "ID: " << in << endl;
	cout << "Naam: " << klan->getNaam() << endl;
	cout << "Adres: " << klan->getAdres() << endl;
	cout << "Setkorting: " << klan->getSetKorting() << endl;
	cout << "SetKorting2: " << klan->getSetKorting2() << endl;
	if (klan->isBedrijf())
	{
		//Bedrijf
		cout << "TYPE: BEDRIJF" << endl;
		BedrijfsKlant* tempb = (BedrijfsKlant*)klan;

		cout << "BTWNummer: " << tempb->getBtwNummer() << endl;
		cout << "Volumekorting: " << tempb->getVolumeKorting() << endl;
		cout << "BedrijfsKorting: " << tempb->getBedrijfsKorting() << endl;
	}
	else
	{
		//Particulier
		cout << "TYPE: PARTICULIER" << endl;
	}

	cout << "Druk op enter om verder te gaan...";
	cin.get();

	return;
}

void deleteKlantMenu()
{
	int in;

	system("cls");
	cout << "*********************************************" << endl;
	cout << "*               KLANT DELETEN             A *" << endl;
	cout << "*                                           *" << endl;
	cout << "Geef het klantennummer: ";
	in = getNumericInput();

	Klant* art = BC->getKlant(in);
	if (art == nullptr)
	{
		cout << in << " is geen geldig klantennummer!" << endl;
	}
	else
	{
		cout << "Bent u zeker dat u '" << art->getNaam() << "' wilt deleten?" << endl;
		cout << "(y/n): ";
		char temp;
		cin >> temp;
		cin.get();
		if (temp == 'y')
		{
			char tempstorn[20];
			strcpy_s(tempstorn, art->getNaam());
			BC->deleteKlant(in);
			art = nullptr;
			cout << tempstorn << "is succesvol verwijderd" << endl;
		}
	}

	cout << endl << "Druk op enter om terug te gaan...";
	cin.get();
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
			cout << "ART NUMMER         ART NAAM  ART TYPE  STOCK    " << endl << endl;

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
				cout << setw(5) << arts[i]->getStock();
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
	cout << endl << "ART NUMMER         ART NAAM          " << endl << endl;
	for (int i = 0; i < MAX_ARTIKELEN; i++)
	{
		if (arts[i] == nullptr)
			continue;

		if (arts[i]->getType() == in)
		{
			cout << setw(3) << i << ":" << setw(23) << arts[i]->getNaam();
			if (arts[i]->getStock() < 2)
			{
				cout << setw(15) << "!CHECK STOCK!";
			}
			cout << endl;
		}
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
	Artikel* art = BC->getArtikel(in);
	if (art == nullptr)
	{
		cout << endl << "Artikel niet gevonden!" << endl;
		cin.get();
		return;
	}

	cout << endl << "#############################################" << endl;
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
	int in;
	
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*              ARTIKEL DELETEN            A *" << endl;
	cout << "*                                           *" << endl;
	cout << "Geef het artikelnummer: ";
	in = getNumericInput();

	Artikel* art = BC->getArtikel(in);
	if (art == nullptr)
	{
		cout << in << " is geen geldig artikel numer!" << endl;
	}
	else
	{
		cout << "Bent u zeker dat u '" << art->getNaam() << "' wilt deleten?" << endl;
		cout << "(y/n): ";
		char temp;
		cin >> temp;
		cin.get();
		if (temp == 'y')
		{
			char tempstorn[20];
			strcpy_s(tempstorn, art->getNaam());
			BC->deleteArtikel(in);
			art = nullptr;
			cout << tempstorn << "is succesvol verwijderd" << endl;
		}
	}

	cout << endl << "Druk op enter om terug te gaan...";
	cin.get();
	return;
}

void viewStockMenu()
{
	int in;
	Artikel** arts = BC->getArtikels();
	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                   STOCK                 A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Artikels met lage stock                *" << endl;
		cout << "* 2. Artikelstock aanpassen                 *" << endl;
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
			cout << endl;
			//Eerst de compleet lege showen
			for (int i = 0; i < MAX_ARTIKELEN; i++)
			{
				if (arts[i] == nullptr)
					continue;

				if (arts[i]->getStock() == 0)
				{
					cout << setw(3) << i << ":" << setw(23) << arts[i]->getNaam() << setw(10);
					if (arts[i]->getType() == 0)
					{
						cout  << "'BAND'";
					}
					else
					{
						cout  << "'VELG'";
					}
					cout << setw(16) << "0 STOCK OVER!!";
					cout << endl;
				}
			}

			//En dan de lage
			for (int i = 0; i < MAX_ARTIKELEN; i++)
			{
				if (arts[i] == nullptr)
					continue;

				if (arts[i]->getStock() < 5 && arts[i]->getStock() != 0)
				{
					cout << setw(3) << i << ":" << setw(23) << arts[i]->getNaam() << setw(10);
					if (arts[i]->getType() == 0)
					{
						cout << "'BAND'";
					}
					else
					{
						cout << "'VELG'";
					}
					cout << setw(3) << arts[i]->getStock() << " STOCK OVER";
					cout << endl;
				}
			}
			cout << "Druk op enter om verder te gaan...";
			cin.get();

			break;

		case 2:
			cout << endl << "Geef het artikel nummer om de stock aan te passen: ";
			in = getNumericInput();
			if (arts[in] == nullptr)
			{
				cout << "Ongekend artikel" << endl;
			}
			else
			{
				cout << "Huidige stock: " << arts[in]->getStock() << endl;
				cout << "Nieuwe stock: ";
				int ni = getNumericInput();
				if (ni < 0)
				{
					cout << endl << ni << " is een ongeldige stock!";
				}
				else
				{
					arts[in]->setStock(ni);
					cout << "Stock van '" << arts[in]->getNaam() << "' is gezet naar: " << ni;
				}
			}

			cout << endl << "Druk op enter om verder te gaan...";
			cin.get();
			break;

		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void factuurMenu()
{
	int in;
	Factuur** facts = BC->getFacturen();

	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*                 FACTUREN                A *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 1. Bekijken                               *" << endl;
		Factuur* huidig = BC->getHuidigFactuur();
		if(huidig == nullptr)
			cout << "* 2. NIEUW factuur aanmaken                 *" << endl;
		else
			cout << "* 2. Huidig factuur beheren                 *" << endl;
		cout << "* 3. Opsommen (alle weergeven)              *" << endl;
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
			bekijkFactuur();
			break;
		case 2:
			manageHuidigFactuur();
			break;
		case 3:
			//Alle facturen
			system("cls");
			cout << "*********************************************" << endl;
			cout << "*             FACTUREN OPSOMMEN           A *" << endl;
			cout << "*                 ---------                 *" << endl;
			cout << "FACT NUMMER   FACT #ARTS   FACT PRIJS         FACT DATUM" << endl << endl;

			for (int i = 0; i < MAX_FACTUREN; i++)
			{
				if (facts[i] == nullptr)
					continue;

				Artikel** artikels = facts[i]->getArtikels();

				cout << setw(3) << i << ":" << setw(10);
				int cnt = 0;
				for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
				{
					if (artikels[cnt] == nullptr)
						continue;
					cnt++;
				}

				cout << cnt << " artikels" << setw(10) << facts[i]->getTotaalPrijs();
				cout << setw(35) << facts[i]->getDatum();
				cout << endl;
			}

			cout << endl << "Druk op enter om door te gaan" << endl;
			cin.get();
			break;
		default:
			printVerkeerdeInput();
			break;
		}
		BC->save();
	} while (in != 0);
	return;
}

void bekijkFactuur()
{
	int in;
	system("cls");
	cout << "*********************************************" << endl;
	cout << "*                 FACTUUR                 A *" << endl;
	cout << "*                                           *" << endl;
	cout << "Geef het factuur nummer: ";

	in = getNumericInput();
	Factuur* fact = BC->getFactuur(in);
	if (fact == nullptr)
	{
		cout << endl << "Factuur niet gevonden!" << endl;
		cout << endl << "Druk op enter om door te gaan" << endl;
		cin.get();
		return;
	}

	cout << endl << "#############################################" << endl;
	cout << "ID: " << in << endl;
	cout << "Datum: " << fact->getDatum() << endl;
	cout << "Klant: " << fact->getKlant()->getNaam() << endl;
	cout << "ADR: " << fact->getKlant()->getAdres() << endl;
	cout << "Totaalprijs: " << fact->getTotaalPrijs() << endl;
	cout << "Verkregen korting: " << fact->getKorting() << endl;

	cout << "Artikels:" << endl;
	Artikel** arts = fact->getArtikels();
	for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
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

		cout << setw(5) << arts[i]->getPrijs() << " eur";
		cout << endl;
	}

	cout << endl << "Druk op enter om door te gaan" << endl;
	cin.get();
}

void manageHuidigFactuur()
{
	Factuur* huidig = BC->getHuidigFactuur();
	Artikel* art = nullptr;
	int in, artid;
	char keuze;

	system("cls");
	cout << "*********************************************" << endl;
	cout << "*                OPEN FACTUUR             A *" << endl;
	cout << "*                 ---------                 *" << endl;
	if (huidig == nullptr)
	{
		//We hebben nog geen open factuur
		cout << "Geef het klantennummer voor de factuur: ";
		in = getNumericInput();

		Klant* klan = BC->getKlant(in);
		if (klan == nullptr)
		{
			cout << endl << "Klant niet gevonden!" << endl;
			cout << endl << "Druk op enter om terug te gaan...";
			cin.get();
			return;
		}

		huidig = BC->openFactuur(klan);
	}

	//Factuur zou ier open moeten zijn
	do {
		system("cls");
		cout << "*********************************************" << endl;
		cout << "*              HUIDIG FACTUUR             A *" << endl;
		cout << "*                 ---------                 *" << endl;
		cout << "KLANT: " << huidig->getKlant()->getNaam() << endl <<endl;
		cout << "*********************************************" << endl;
		cout << "Artikels:" << endl;

		Artikel** arts = huidig->getArtikels();
		float totaal = 0;

		for (int i = 0; i < MAX_ARTIKELEN_PER_FACTUUR; i++)
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

			cout << setw(6) << arts[i]->getPrijs() << " eur";
			cout << endl;
			totaal += arts[i]->getPrijs();
		}
		huidig->sluiten(); //Berekend alles
		cout << "TOTAAL (zonder korting): " << totaal << endl;
		cout << "KORTING (alles erop en eraan): " << huidig->getKorting() << endl;
		cout << "TOTAAL (met korting): " << huidig->getTotaalPrijs() << endl;
		cout << endl;
		cout << "*********************************************" << endl;
		cout << "* 1. Artikel toevoegen                      *" << endl;
		cout << "* 2. Artikel verwijderen                    *" << endl;
		cout << "* 3. Factuur sluiten                        *" << endl;
		cout << "* 4. Factuur annuleren (Discard)            *" << endl;
		cout << "*                                           *" << endl;
		cout << "* 0. Terug                                  *" << endl;
		cout << "*********************************************" << endl;
		cout << "Uw Keuze: ";

		in = getNumericInput();
		switch (in)
		{
		case 0:// Quit
			break;
		case 1:
			cout << endl << "Geef het artikelnumer dat u wilt toevoegen: " << endl;
			artid = getNumericInput();
			art = BC->getArtikel(artid);
			if (art == nullptr)
			{
				cout << endl << "Artikel niet gevonden!" << endl;
				cout << endl << "Druk op enter om verder te gaan.";
				cin.get();
			}
			else
			{
				if (art->getStock() == 0)
				{
					cout << endl << "Artikel '" << art->getNaam() << "' is uit stock!!!!";
				}
				else
				{
					huidig->addArtikel(art);
					art->decrementStock();
					cout << endl << "Artikel '" << art->getNaam() << "' is toegevoegd";
				}

				cout << endl << "Druk op enter om verder te gaan.";
				cin.get();
			}
			break;
		case 2:
			cout << endl << "Geef het artikelnumer dat u wilt VERWIJDEREN (index zoals hierboven): " << endl;
			artid = getNumericInput();
			if (arts[artid] == nullptr)
			{
				cout << endl << "Artikel niet in mandje!" << endl;
				cout << endl << "Druk op enter om verder te gaan.";
				cin.get();
			}
			else
			{
				arts[artid]->incrementStock();
				huidig->delArtikel(artid);
				cout << endl << "Artikel is verwijderd" << endl;
				
				cout << endl << "Druk op enter om verder te gaan.";
				cin.get();
			}
			break;
		case 3:
			cout << endl << "Bent u zeker dat de factuur gesloten mag worden? (y/n): ";
			cin >> keuze;
			cin.get();

			if (keuze == 'y')
			{
				BC->sluitHuidigFactuur(true);
				in = 0;
			}
			break;
		case 4:
			cout << endl << "Bent u zeker dat de factuur weg mag? (y/n): ";
			cin >> keuze;
			cin.get();

			//Stocks terug goed zetten
			for (int o = 0; o < MAX_ARTIKELEN_PER_FACTUUR; o++)
			{
				if (arts[o] == nullptr)
					continue;

				arts[o]->incrementStock();
			}

			if (keuze == 'y')
			{
				BC->sluitHuidigFactuur(false);
				in = 0;
			}
			break;
		default:
			printVerkeerdeInput();
			break;
		}
	} while (in != 0);
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