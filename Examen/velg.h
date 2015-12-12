#pragma once
#include "artikel.h"
#include <string.h>

class Velg :
	public Artikel
{
public:
	Velg();
	Velg(char[], char[], float, float, int, char[], bool);
	~Velg();

	// SETTERS
	void setBreedte(int);
	void setKleur(char[]);
	void setAluminium(bool);

	//GETTERS
	int getType();
	int getBreedte();
	char* getKleur();
	bool getAluminium();

private:
	const int type = 1;
	int breedte;
	char kleur[64];
	bool aluminium;
};

