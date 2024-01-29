#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Pomiar.h"

using namespace std;
class Drzewo
{
public:
	int rok;
	vector<vector<vector<vector<Pomiar>>>> miesiace;
public:
	Drzewo(int rok)
	{
		this->rok = rok;
		miesiace.resize(12);
	}

	void DodajPomiar(Pomiar p)
	{
		string czas = p._czas;
		stringstream ss(czas);
		string rok, miesiac, dzien, godzina, minuta;
		getline(ss, dzien, '.');
		getline(ss, miesiac, '.');
		getline(ss, rok, ' ');
		getline(ss, godzina, ':');
		getline(ss, minuta, ',');
		int r = stoi(rok);
		int m = stoi(miesiac);
		int d = stoi(dzien);
		int g = stoi(godzina);
		int min = stoi(minuta);
		if (r == this->rok)
		{
			int im = m - 1;
			if (miesiace[im].empty())
			{
				miesiace[im].resize(31);
			}
			int id = d - 1;
			if (miesiace[im][id].empty())
			{
				miesiace[im][id].resize(4);
			}
			int ic;
			if (g < 6)
			{
				ic = 0;
			}
			else if (g < 12)
			{
				ic = 1;
			}
			else if (g < 18)
			{
				ic = 2;
			}
			else
			{
				ic = 3;
			}
			miesiace[im][id][ic].push_back(p);
		}
	}

	void WyswietlDane()
	{

		cout << "Rok: " << rok << endl;
		for (int i = 0; i < 12; i++)
		{
			if (!miesiace[i].empty())
			{
				cout << "Miesiac: " << i + 1 << endl;
				for (int j = 0; j < 31; j++)
				{
					if (!miesiace[i][j].empty())
					{
						cout << "Dzien: " << j + 1 << endl;
						for (int k = 0; k < 4; k++)
						{
							if (!miesiace[i][j][k].empty())
							{
								cout << "Cwiartka: " << k + 1 << endl;
								for (Pomiar p : miesiace[i][j][k])
								{
									cout << "Czas: " << p._czas << endl;
									cout << "Autokonsumpcja: " << p._autokonsumpcja << endl;
									cout << "Eksport: " << p._eksport << endl;
									cout << "Import: " << p._import << endl;
									cout << "Pobor: " << p._pobor << endl;
									cout << "Produkcja: " << p._produkcja << endl;
									cout << "---------------------" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
};