#include "Dane.h"
#include <algorithm>
#include <set>
#include <tuple>
#include <stdlib.h>
#include <fstream>
#include <ctime>


bool operator<(const Pomiar& a, const Pomiar& b) {
	return tie(a._czas, a._autokonsumpcja, a._eksport, a._import, a._pobor, a._produkcja) <
		tie(b._czas, b._autokonsumpcja, b._eksport, b._import, b._pobor, b._produkcja);
}

std::vector<std::string> split(std::string s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string token;
	while (std::getline(ss, token, delim)) {
		result.push_back(token);
	}
	return result;
}



void Dane::WczytajPlik(string nazwa_pliku)
{
	std::ifstream plik(nazwa_pliku);
	std::set<Pomiar> uniquePomiary;

	int correct = 0, incorrect = 0;

	time_t t = time(nullptr);
	tm* now = localtime(&t);
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", now);

	string errorLogFile = "log_error_" + string(buffer) + ".txt";
	string correctLogFile = "log_" + string(buffer) + ".txt";
	ofstream badLog(errorLogFile);
	ofstream goodLog(correctLogFile);


	if (plik.is_open()) {
		std::string line;
		int lineNumber = 0; //zmienna sledzaca nr linii

		// odczytaj linie po linii
		while (std::getline(plik, line)) {
			++lineNumber;
			std::vector<std::string> fields = split(line, ','); // splitowanie linii po przecinkach

			if (fields.size() == 0) // pomijanie pustych linii po splitowaniu
			{
				badLog << "Pusta linia nr "<<lineNumber<<": " << line << '\n';
				incorrect++;
				continue;
			}
			if (fields[0] == "Time") {
				// pominiecie naglowkow
				continue;
			}

			if (fields.size() == 6) {
				// parsowanie linii do obiektu Pomiar
				Pomiar pomiar;
				pomiar._czas = fields[0];
				// usuwanie cudzyslowiow
				for (int i = 1; i < 6; i++) {
					fields[i].erase(std::remove(fields[i].begin(), fields[i].end(), '"'), fields[i].end());
				}
				// convert the fields to double
				try
				{
					pomiar._autokonsumpcja = std::stod(fields[1]);
					pomiar._eksport = std::stod(fields[2]);
					pomiar._import = std::stod(fields[3]);
					pomiar._pobor = std::stod(fields[4]);
					pomiar._produkcja = std::stod(fields[5]);
				}
				catch (std::invalid_argument& e)
				{
					badLog << "Nieprawidlowe pole, linia nr "<< lineNumber <<": " << line << '\n';
					incorrect++;
				}
				if (uniquePomiary.find(pomiar) != uniquePomiary.end()) {

					badLog << "Powtorzona linia nr " << lineNumber << ": " << line << "\n";
					incorrect++;
				}
				else {
					correct++;
					uniquePomiary.insert(pomiar);
				}
			}
			else {
				badLog << "Nieprawidlowe pole, linia nr " << lineNumber << ": " << line << '\n';
				incorrect++;
				continue;
			}
			goodLog << line << '\n';
		}
		plik.close();
		badLog.close();
	}
	pomiary.assign(uniquePomiary.begin(), uniquePomiary.end());
	std::cout << "Poprawne: " << correct << "\nNiepoprawne: " << incorrect << "\n";
}

void Dane::ZapiszBinarnie(string nazwa_pliku)
{
	ofstream plik(nazwa_pliku, ios::binary);
	if (plik.is_open())
	{
		for (const auto& p : pomiary)
		{
			size_t size = p._czas.size();
			plik.write(reinterpret_cast<const char*>(&size), sizeof(size_t));
			plik.write(p._czas.c_str(), p._czas.size());
			plik.write(reinterpret_cast<const char*>(&p._autokonsumpcja), sizeof(double));
			plik.write(reinterpret_cast<const char*>(&p._eksport), sizeof(double));
			plik.write(reinterpret_cast<const char*>(&p._import), sizeof(double));
			plik.write(reinterpret_cast<const char*>(&p._pobor), sizeof(double));
			plik.write(reinterpret_cast<const char*>(&p._produkcja), sizeof(double));
		}
		plik.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku do zapisu" << endl;
	}
}



void Dane::OdczytajBinarnie(string nazwa_pliku)
{
	ifstream plik(nazwa_pliku, ios::binary);
	vector<Pomiar> pomiary2;
	Pomiar p;
	while (plik)
	{
		size_t size;
		plik.read(reinterpret_cast<char*>(&size), sizeof(size_t));
		p._czas.resize(size);
		plik.read(&p._czas[0], size);
		plik.read(reinterpret_cast<char*>(&p._autokonsumpcja), sizeof(double));
		plik.read(reinterpret_cast<char*>(&p._eksport), sizeof(double));
		plik.read(reinterpret_cast<char*>(&p._import), sizeof(double));
		plik.read(reinterpret_cast<char*>(&p._pobor), sizeof(double));
		plik.read(reinterpret_cast<char*>(&p._produkcja), sizeof(double));
		if (plik) pomiary.push_back(p);
	}
}

vector<Pomiar> Dane::GetPomiary()
{
	return pomiary;
}

