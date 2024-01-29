#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Drzewo.h"
#include "Pomiar.h"

using namespace std;

class Operacje
{
private:
	Drzewo* drzewo;
public:
	Operacje(Drzewo* drzewo) : drzewo(drzewo) {}

	double SumaAutokonsumpcji(string data_od, string data_do);
	double SumaEksportu(string data_od, string data_do);
	double SumaImportu(string data_od, string data_do);
	double SumaPoboru(string data_od, string data_do);
	double SumaProdukcji(string data_od, string data_do);
	double SredniaAutokonsumpcja(string data_od, string data_do);
	double SredniaEksport(string data_od, string data_do);
	double SredniaImport(string data_od, string data_do);
	double SredniaPobor(string data_od, string data_do);
	double SredniaProdukcja(string data_od, string data_do);

	string PorownajAutokonsumpcje(string data_od1, string data_do1, string data_od2, string data_do2);
	string PorownajEksport(string data_od1, string data_do1, string data_od2, string data_do2);
	string PorownajImport(string data_od1, string data_do1, string data_od2, string data_do2);
	string PorownajPobor(string data_od1, string data_do1, string data_od2, string data_do2);
	string PorownajProdukcje(string data_od1, string data_do1, string data_od2, string data_do2);
	vector<Pomiar> WyszukajRekordy(double wartosc, double tolerancja, string data_od, string data_do, string kategoria);

	void WypiszDane(string data_od, string data_do);
};


