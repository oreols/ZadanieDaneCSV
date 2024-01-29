#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Pomiar.h"

using namespace std;


class Dane
{
private:
	vector<Pomiar> pomiary;

public:
	void WczytajPlik(string nazwa_pliku);
	void ZapiszBinarnie(string nazwa_pliku);
	void OdczytajBinarnie(string nazwa_pliku);
	vector<Pomiar> GetPomiary();
};

