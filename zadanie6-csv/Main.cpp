
#include <iostream>
#include "Dane.h"
#include "Drzewo.h"
#include "Operacje.h"
#include "Pomiar.h"
#include "Menu.h"

using namespace std;


int main()
{
    Dane* dane = new Dane();
	Drzewo* drzewo = new Drzewo(2020);
	Drzewo* drzewo_2 = new Drzewo(2021);

	Operacje* operacje = new Operacje(drzewo_2);

	Menu* menu = new Menu(drzewo_2, operacje, dane);
	menu->WypiszMenu();
	menu->WybierzOpcje();
	

    return EXIT_SUCCESS;
}

