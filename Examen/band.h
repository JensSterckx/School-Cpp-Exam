#pragma once
#include "artikel.h"
class Band :
	public Artikel
{
public:
	Band();
	Band(char[], char[], float, float, float, float, float, char, int);
	~Band();

	// SETTERS
	void setBreedte(float);
	void setHoogte(float);
	void setSnelheidsIndex(float);
	void setSeizoen(char);

	//GETTERS
	int getType();
	float getBreedte();
	float getHoogte();
	float getSnelheidsIndex();
	char getSeizoen();

private:
	const int type = 0;
	float breedte;
	float hoogte;
	float snelheidsIndex;
	char seizoen;
};

