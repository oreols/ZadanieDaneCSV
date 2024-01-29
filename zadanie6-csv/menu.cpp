#include "Menu.h"

void Menu::WypiszMenu()
{
	cout << endl<< "--------------------------- MENU ------------------" << endl;
	cout << "1. Wczytaj plik csv" << endl;
	cout << "2. Zapisz dane do pliku binarnego" << endl;
	cout << "3. Odczytaj dane z pliku binarnego" << endl;
	cout << "4. Wypisz sume autokonsumpcji" << endl;
	cout << "5. Wypisz sume eksportu" << endl;
	cout << "6. Wypisz sume importu" << endl;
	cout << "7. Wypisz sume poboru" << endl;
	cout << "8. Wypisz sume produkcji" << endl;
	cout << "9. Wypisz srednia autokonsumpcji" << endl;
	cout << "10. Wypisz srednia eksportu" << endl;
	cout << "11. Wypisz srednia importu" << endl;
	cout << "12. Wypisz srednia poboru" << endl;
	cout << "13. Wypisz srednia produkcji" << endl;
	cout << "14. Porownaj autokonsumpcje" << endl;
	cout << "15. Porownaj eksporty" << endl;
	cout << "16. Porownaj importy" << endl;
	cout << "17. Porownaj pobory" << endl;
	cout << "18. Porownaj produkcje" << endl;
	cout << "19. Wyszukaj rekordy" << endl;
	cout << "20. Wypisz dane" << endl;
	cout << "0. Wyjdz z programu" << endl;
	cout << "----------------------------------------------------" << endl;
}


void Menu::WybierzOpcje()
{
	int wybor;
	do {
		string nazwa_pliku;
		string data_od, data_do, data_od1, data_do1, data_od2, data_do2, kategoria;
		string godzina_od, godzina_do, godzina2_od, godzina2_do;
		double wartosc, tolerancja;
		vector<Pomiar> wyniki;
		cout <<endl<< "Wybierz opcje: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1: // wczytanie pliku csv

			cout << "Podaj nazwe pliku w formacie 'x.csv':";
			cin >> nazwa_pliku;
			dane->WczytajPlik(nazwa_pliku);

			for (const auto& pomiar : dane->GetPomiary())
			{
				this->drzewo->DodajPomiar(pomiar);
			}

			break;
		case 2: // zapis do pliku binarnego
			cout << "Podaj nazwe pliku do zapisu, w formacie 'x.bin':";
			cin >> nazwa_pliku;
			this->dane->ZapiszBinarnie(nazwa_pliku);
			break;
		case 3: // odczyt z pliku binarnego
			cout << "Podaj nazwe pliku do odczytu binarnego: ";
			cin >> nazwa_pliku;
			dane->OdczytajBinarnie(nazwa_pliku);
			for (const auto& pomiar : dane->GetPomiary())
			{
				this->drzewo->DodajPomiar(pomiar);
			}
			break;
		case 4: // suma autokonsumpcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SumaAutokonsumpcji((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 5: // suma eksportu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SumaEksportu((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 6: // suma importu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SumaImportu((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 7: // suma poboru
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SumaPoboru((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 8: // suma produkcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SumaProdukcji((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 9: // srednia autokonsumpcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SredniaAutokonsumpcja((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 10: // srednia eksportu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SredniaEksport((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 11: // srednia importu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SredniaImport((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 12: // srednia poboru
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SredniaPobor((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 13: // srednia produkcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << operacje->SredniaProdukcja((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 14: // porownywanie autokonsumpcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Podaj drugi przedzial: ";
			cout << "Data i godzina od: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "Data i godzina do: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajAutokonsumpcje(data_od1, data_do1, data_od2, data_do2);
			break;
		case 15: // porownanie eksportu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Podaj drugi przedzial: " << endl;
			cout << "Data i godzina od: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "Data i godzina do: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajEksport(data_od1, data_do1, data_od2, data_do2);
			break;
		case 16: // porownanie importu
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Podaj drugi przedzial: ";
			cout << "Data i godzina od: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "Data i godzina do: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajImport(data_od1, data_do1, data_od2, data_do2);
			break;
		case 17: // porownanie poboru
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Podaj drugi przedzial: ";
			cout << "Data i godzina od: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "Data i godzina do: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajPobor(data_od1, data_do1, data_od2, data_do2);
			break;
		case 18: // porownanie produkcji
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Podaj drugi przedzial: ";
			cout << "Data i godzina od: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "Data i godzina do: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajProdukcje(data_od1, data_do1, data_od2, data_do2);
			break;
		case 19: // wyszukanie rekordow

			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00" << endl;
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Podaj wartosc do szukania: ";
			cin >> wartosc;
			cout << "Podaj tolerancje: ";
			cin >> tolerancja;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Podaj kategorie (autokonsumpcja, eksport, import, pobor lub produkcja): ";
			cin >> kategoria;
			wyniki = operacje->WyszukajRekordy(wartosc, tolerancja, data_od1, data_do1, kategoria);
			cout << "Znalezione rekordy: ";
			cout << "-----------------------" << endl;
			for (const auto& rekord : wyniki)
			{
				cout << rekord._czas << " " << rekord._autokonsumpcja << " " << rekord._eksport << " " << rekord._import << " " << rekord._pobor << " " << rekord._produkcja << endl;
			}
			break;
		case 20: // wypisz dane
			cout << "Podaj przedzial dat i godzin w formacie dd.mm.rrrr hh:mm, np. 3.10.2021 00:00";
			cout << "Data i godzina od: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "Data i godzina do: ";
			cin >> data_do1;
			cin >> godzina_do;
			operacje->WypiszDane((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 0: // wyjdz
			cout << "Koniec programu" << endl;
			return;
			break;
		}

	} while (wybor != 0);
}
