#include "main.h"
#include "add_hulp.h"

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