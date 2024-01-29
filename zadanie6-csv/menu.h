#pragma once
#include <iostream>
#include "Operacje.h"
#include "Dane.h"

using namespace std;

class Menu
{
private:
	Operacje* operacje;
	Dane* dane;
	Drzewo* drzewo;
public:
	Menu(Drzewo* drzewo, Operacje* operacje, Dane* dane) : drzewo(drzewo), operacje(operacje), dane(dane) {}
	void WypiszMenu();
	void WybierzOpcje();
};

