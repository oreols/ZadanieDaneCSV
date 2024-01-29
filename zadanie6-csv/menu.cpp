#include "Menu.h"

void Menu::WypiszMenu()
{
	cout << endl<< "--------------------------- MENU ------------------" << endl;
	cout << "1. Wczytaj plik csv" << endl;
	cout << "2. Wypisz sume autokonsumpcji" << endl;
	cout << "3. Wypisz sume eksportu" << endl;
	cout << "4. Wypisz sume importu" << endl;
	cout << "5. Wypisz sume poboru" << endl;
	cout << "6. Wypisz sume produkcji" << endl;
	cout << "7. Wypisz srednia autokonsumpcji" << endl;
	cout << "8. Wypisz srednia eksportu" << endl;
	cout << "9. Wypisz srednia importu" << endl;
	cout << "10. Wypisz srednia poboru" << endl;
	cout << "11. Wypisz srednia produkcji" << endl;
	cout << "12. Porownaj autokonsumpcje" << endl;
	cout << "13. Porownaj eksporty" << endl;
	cout << "14. Porownaj importy" << endl;
	cout << "15. Porownaj pobory" << endl;
	cout << "16. Porownaj produkcje" << endl;
	cout << "17. Wyszukaj rekordy" << endl;
	cout << "18. Wypisz dane" << endl;
	cout << "19. Zapisz dane do pliku binarnego" << endl;
	cout << "20. Odczytaj dane z pliku binarnego" << endl;
	cout << "0. Wyjdz z programu" << endl;
	cout << "----------------------------------------------------" << endl;
}


void Menu::WybierzOpcje()
{
	int wybor;
	do {
		string nazwa_pliku, data_od, godzina_od, godzina_do, data_do,
			data_od1, data_do1, data_od2, data_do2, godzina2_od, godzina2_do, kategoria;
		
		double wartosc, tolerancja;
		vector<Pomiar> wyniki;

		cout <<endl<< "Wybierz opcje: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1: // wczytanie pliku csv

			cout << "Nazwa pliku (np plik.csv):";
			cin >> nazwa_pliku;
			dane->WczytajPlik(nazwa_pliku);

			for (const auto& pomiar : dane->GetPomiary())
			{
				this->drzewo->DodajPomiar(pomiar);
			}

			break;
		case 2: // suma autokonsumpcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)" << endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Suma autokonsumpcji: "<< operacje->SumaAutokonsumpcji((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 3: // suma eksportu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)" << endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Suma eksportu: " << operacje->SumaEksportu((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 4: // suma importu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Suma importu: " << operacje->SumaImportu((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 5: // suma poboru
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Suma poboru: " << operacje->SumaPoboru((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 6: // suma produkcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Suma produkcji: " << operacje->SumaProdukcji((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 7: // srednia autokonsumpcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Srednia suma autokonsumpcji: " << operacje->SredniaAutokonsumpcja((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 8: // srednia eksportu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Srednia suma eksportu: " << operacje->SredniaEksport((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 9: // srednia importu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Srednia suma importu: " << operacje->SredniaImport((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 10: // srednia poboru
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Srednia suma poboru: " << operacje->SredniaPobor((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 11: // srednia produkcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Srednia suma produkcji: " << operacje->SredniaProdukcja((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 12: // porownywanie autokonsumpcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)"<<endl;
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Drugi przedzial: ";
			cout << "OD: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "DO: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajAutokonsumpcje(data_od1, data_do1, data_od2, data_do2);
			break;
		case 13: // porownanie eksportu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)";
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Drugi przedzial: " << endl;
			cout << "OD: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "DO: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajEksport(data_od1, data_do1, data_od2, data_do2);
			break;
		case 14: // porownanie importu
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)";
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Drugi przedzial: ";
			cout << "OD: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "DO: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajImport(data_od1, data_do1, data_od2, data_do2);
			break;
		case 15: // porownanie poboru
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)";
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Drugi przedzial: ";
			cout << "OD: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "DO: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajPobor(data_od1, data_do1, data_od2, data_do2);
			break;
		case 16: // porownanie produkcji
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)";
			cout << "OD: ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			cout << "Drugi przedzial: ";
			cout << "OD: ";
			cin >> data_od2;
			cin >> godzina2_od;
			cout << "DO: ";
			cin >> data_do2;
			cin >> godzina2_do;
			data_od1 = data_od1 + " " + godzina_od;
			data_do1 = data_do1 + " " + godzina_do;
			data_od2 = data_od2 + " " + godzina2_od;
			data_do2 = data_do2 + " " + godzina2_do;
			cout << operacje->PorownajProdukcje(data_od1, data_do1, data_od2, data_do2);
			break;
		case 17: // wyszukanie rekordow

			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)" << endl;
			cout << "OD: ";
			cin >> data_od1;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "DO: ";
			cin >> data_do1;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Jakie wartosci chcesz znalezc: ";
			cin >> wartosc;
			cout << "Tolerancja: ";
			cin >> tolerancja;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Podaj jaka kategorie mam przeszukac (autokonsumpcja, eksport, import, pobor lub produkcja): ";
			cin >> kategoria;
			wyniki = operacje->WyszukajRekordy(wartosc, tolerancja, data_od1, data_do1, kategoria);
			cout << "Znalezione rekordy: ";
			cout << "-----------------------" << endl;
			for (const auto& rekord : wyniki)
			{
				cout << rekord._czas << " " << rekord._autokonsumpcja << " " << rekord._eksport << " " << rekord._import << " " << rekord._pobor << " " << rekord._produkcja << endl;
			}
			break;
		case 18: // wypisz dane
			cout << "Przedzial DD.MM.RRRR MM:HH (1.10.2020 8:00)";
			cout << "OD ";
			cin >> data_od1;
			cin >> godzina_od;
			cout << "DO: ";
			cin >> data_do1;
			cin >> godzina_do;
			operacje->WypiszDane((data_od1 + " " + godzina_od), (data_do1 + " " + godzina_do));
			break;
		case 19: // zapis do pliku binarnego
			cout << "Nazwa pliku do zapisu (np plik_binarny.bin):";
			cin >> nazwa_pliku;
			this->dane->ZapiszBinarnie(nazwa_pliku);
			break;
		case 20: // odczyt z pliku binarnego
			cout << "Jaki plik binarny odczytac ? (np plik.bin): ";
			cin >> nazwa_pliku;
			dane->OdczytajBinarnie(nazwa_pliku);
			for (const auto& pomiar : dane->GetPomiary())
			{
				this->drzewo->DodajPomiar(pomiar);
			}
			break;
		case 0: // wyjdz
			cout << "Koniec programu" << endl;
			break;
		}

	} while (wybor != 0);
}
