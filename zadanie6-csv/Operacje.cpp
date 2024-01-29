#include "Operacje.h"
#include <sstream> // for std::istringstream
#include <iomanip> // for std::get_time

double Operacje::SumaAutokonsumpcji(string data_od, string data_do)
{
	double suma = 0;
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._autokonsumpcja;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << std::fixed << std::setprecision(1);
	return suma;
}

double Operacje::SumaEksportu(string data_od, string data_do)
{
	double suma = 0;
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._eksport;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << std::fixed << std::setprecision(1);
	return suma;
}

double Operacje::SumaImportu(string data_od, string data_do)
{
	double suma = 0;
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._import;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma;
}

double Operacje::SumaPoboru(string data_od, string data_do)
{

	double suma = 0;
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._pobor;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma;
}

double Operacje::SumaProdukcji(string data_od, string data_do)
{
	double suma = 0;
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._produkcja;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma;

}

double Operacje::SredniaAutokonsumpcja(string data_od, string data_do)
{
	double suma = 0;
	int licznik = 0;

	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._autokonsumpcja;
									licznik++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma / licznik;
}

double Operacje::SredniaEksport(string data_od, string data_do)
{
	double suma = 0;
	int licznik = 0;

	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._eksport;
									licznik++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma / licznik;
}

double Operacje::SredniaImport(string data_od, string data_do)
{
	double suma = 0;
	int licznik = 0;

	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._import;
									licznik++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma / licznik;
}

double Operacje::SredniaPobor(string data_od, string data_do)
{
	double suma = 0;
	int licznik = 0;

	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._pobor;
									licznik++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma / licznik;
}

double Operacje::SredniaProdukcja(string data_od, string data_do)
{
	double suma = 0;
	int licznik = 0;

	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od && time_czas <= time_do)
								{
									suma += drzewo->miesiace[i][j][k][l]._produkcja;
									licznik++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return suma / licznik;
}

std::string Operacje::PorownajAutokonsumpcje(string data_od1, string data_do1, string data_od2, string data_do2)
{
	double suma1 = 0;
	double suma2 = 0;

	std::tm tm_od1 = {}, tm_do1 = {}, tm_od2 = {}, tm_do2 = {};
	std::istringstream ss_od1(data_od1);
	std::istringstream ss_do1(data_do1);
	std::istringstream ss_od2(data_od2);
	std::istringstream ss_do2(data_do2);
	ss_od1 >> std::get_time(&tm_od1, "%d.%m.%Y %H:%M");
	ss_do1 >> std::get_time(&tm_do1, "%d.%m.%Y %H:%M");
	ss_od2 >> std::get_time(&tm_od2, "%d.%m.%Y %H:%M");
	ss_do2 >> std::get_time(&tm_do2, "%d.%m.%Y %H:%M");
	time_t time_od1 = std::mktime(&tm_od1);
	time_t time_do1 = std::mktime(&tm_do1);
	time_t time_od2 = std::mktime(&tm_od2);
	time_t time_do2 = std::mktime(&tm_do2);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od1 && time_czas <= time_do1)
								{
									suma1 += drzewo->miesiace[i][j][k][l]._autokonsumpcja;
								}
								if (time_czas >= time_od2 && time_czas <= time_do2)
								{
									suma2 += drzewo->miesiace[i][j][k][l]._autokonsumpcja;
								}
							}
						}
					}
				}
			}
		}
	}
	if (suma1 > suma2)
		return "Wiecej autokonsumpcji w pierwszym okresie";
	else if (suma1 < suma2)
		return "Wiecej autokonsumpcji w drugim okresie";
	else
		return "Tyle samo autokonsumpcji w obu okresach";

}


std::string Operacje::PorownajEksport(string data_od1, string data_do1, string data_od2, string data_do2)
{
	double suma1 = 0;
	double suma2 = 0;

	std::tm tm_od1 = {}, tm_do1 = {}, tm_od2 = {}, tm_do2 = {};
	std::istringstream ss_od1(data_od1);
	std::istringstream ss_do1(data_do1);
	std::istringstream ss_od2(data_od2);
	std::istringstream ss_do2(data_do2);
	ss_od1 >> std::get_time(&tm_od1, "%d.%m.%Y %H:%M");
	ss_do1 >> std::get_time(&tm_do1, "%d.%m.%Y %H:%M");
	ss_od2 >> std::get_time(&tm_od2, "%d.%m.%Y %H:%M");
	ss_do2 >> std::get_time(&tm_do2, "%d.%m.%Y %H:%M");
	time_t time_od1 = std::mktime(&tm_od1);
	time_t time_do1 = std::mktime(&tm_do1);
	time_t time_od2 = std::mktime(&tm_od2);
	time_t time_do2 = std::mktime(&tm_do2);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od1 && time_czas <= time_do1)
								{
									suma1 += drzewo->miesiace[i][j][k][l]._eksport;
								}
								if (time_czas >= time_od2 && time_czas <= time_do2)
								{
									suma2 += drzewo->miesiace[i][j][k][l]._eksport;
								}
							}
						}
					}
				}
			}
		}
	}
	if (suma1 > suma2)
		return "Wiecej eksportu w pierwszym okresie";
	else if (suma1 < suma2)
		return "Wiecej eksportu w drugim okresie";
	else
		return "Tyle samo eksportu w obu okresach";
}

std::string Operacje::PorownajImport(string data_od1, string data_do1, string data_od2, string data_do2)
{

	double suma1 = 0;
	double suma2 = 0;
	std::tm tm_od1 = {}, tm_do1 = {}, tm_od2 = {}, tm_do2 = {};
	std::istringstream ss_od1(data_od1);
	std::istringstream ss_do1(data_do1);
	std::istringstream ss_od2(data_od2);
	std::istringstream ss_do2(data_do2);
	ss_od1 >> std::get_time(&tm_od1, "%d.%m.%Y %H:%M");
	ss_do1 >> std::get_time(&tm_do1, "%d.%m.%Y %H:%M");
	ss_od2 >> std::get_time(&tm_od2, "%d.%m.%Y %H:%M");
	ss_do2 >> std::get_time(&tm_do2, "%d.%m.%Y %H:%M");
	time_t time_od1 = std::mktime(&tm_od1);
	time_t time_do1 = std::mktime(&tm_do1);
	time_t time_od2 = std::mktime(&tm_od2);
	time_t time_do2 = std::mktime(&tm_do2);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od1 && time_czas <= time_do1)
								{
									suma1 += drzewo->miesiace[i][j][k][l]._import;
								}
								if (time_czas >= time_od2 && time_czas <= time_do2)
								{
									suma2 += drzewo->miesiace[i][j][k][l]._import;
								}
							}
						}
					}
				}
			}
		}
	}
	if (suma1 > suma2)
		return "Wiecej importu w pierwszym okresie";
	else if (suma1 < suma2)
		return "Wiecej importu w drugim okresie";
	else
		return "Tyle samo importu w obu okresach";
}

std::string Operacje::PorownajPobor(string data_od1, string data_do1, string data_od2, string data_do2)
{
	double suma1 = 0;
	double suma2 = 0;

	std::tm tm_od1 = {}, tm_do1 = {}, tm_od2 = {}, tm_do2 = {};
	std::istringstream ss_od1(data_od1);
	std::istringstream ss_do1(data_do1);
	std::istringstream ss_od2(data_od2);
	std::istringstream ss_do2(data_do2);
	ss_od1 >> std::get_time(&tm_od1, "%d.%m.%Y %H:%M");
	ss_do1 >> std::get_time(&tm_do1, "%d.%m.%Y %H:%M");
	ss_od2 >> std::get_time(&tm_od2, "%d.%m.%Y %H:%M");
	ss_do2 >> std::get_time(&tm_do2, "%d.%m.%Y %H:%M");
	time_t time_od1 = std::mktime(&tm_od1);
	time_t time_do1 = std::mktime(&tm_do1);
	time_t time_od2 = std::mktime(&tm_od2);
	time_t time_do2 = std::mktime(&tm_do2);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od1 && time_czas <= time_do1)
								{
									suma1 += drzewo->miesiace[i][j][k][l]._pobor;
								}
								if (time_czas >= time_od2 && time_czas <= time_do2)
								{
									suma2 += drzewo->miesiace[i][j][k][l]._pobor;
								}
							}
						}
					}
				}
			}
		}
	}
	if (suma1 > suma2)
		return "Wiecej poboru w pierwszym okresie";
	else if (suma1 < suma2)
		return "Wiecej poboru w drugim okresie";
	else
		return "Tyle samo poboru w obu okresach";
}

std::string Operacje::PorownajProdukcje(string data_od1, string data_do1, string data_od2, string data_do2)
{
	double suma1 = 0;
	double suma2 = 0;
	std::tm tm_od1 = {}, tm_do1 = {}, tm_od2 = {}, tm_do2 = {};
	std::istringstream ss_od1(data_od1);
	std::istringstream ss_do1(data_do1);
	std::istringstream ss_od2(data_od2);
	std::istringstream ss_do2(data_do2);
	ss_od1 >> std::get_time(&tm_od1, "%d.%m.%Y %H:%M");
	ss_do1 >> std::get_time(&tm_do1, "%d.%m.%Y %H:%M");
	ss_od2 >> std::get_time(&tm_od2, "%d.%m.%Y %H:%M");
	ss_do2 >> std::get_time(&tm_do2, "%d.%m.%Y %H:%M");
	time_t time_od1 = std::mktime(&tm_od1);
	time_t time_do1 = std::mktime(&tm_do1);
	time_t time_od2 = std::mktime(&tm_od2);
	time_t time_do2 = std::mktime(&tm_do2);

	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (int l = 0; l < drzewo->miesiace[i][j][k].size(); l++)
							{
								// Convert _czas to time_t
								std::tm tm_czas = {};
								std::istringstream ss_czas(drzewo->miesiace[i][j][k][l]._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);

								if (time_czas >= time_od1 && time_czas <= time_do1)
								{
									suma1 += drzewo->miesiace[i][j][k][l]._produkcja;
								}
								if (time_czas >= time_od2 && time_czas <= time_do2)
								{
									suma2 += drzewo->miesiace[i][j][k][l]._produkcja;
								}
							}
						}
					}
				}
			}
		}
	}
	if (suma1 > suma2)
		return "Wiecej produkcji w pierwszym okresie";
	else if (suma1 < suma2)
		return "Wiecej produkcji w drugim okresie";
	else
		return "Tyle samo produkcji w obu okresach";
}

vector<Pomiar> Operacje::WyszukajRekordy(double wartosc, double tolerancja, string data_od, string data_do, string kategoria)
{
	vector<Pomiar> wyniki;
	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (Pomiar p : drzewo->miesiace[i][j][k])
							{
								if (p._czas >= data_od && p._czas <= data_do)
								{
									if (kategoria == "autokonsumpcja")
									{
										if (p._autokonsumpcja >= wartosc - tolerancja && p._autokonsumpcja <= wartosc + tolerancja)
										{
											wyniki.push_back(p);
										}
									}
									else if (kategoria == "eksport")
									{
										if (p._eksport >= wartosc - tolerancja && p._eksport <= wartosc + tolerancja)
										{
											wyniki.push_back(p);
										}
									}
									else if (kategoria == "import")
									{
										if (p._import >= wartosc - tolerancja && p._import <= wartosc + tolerancja)
										{
											wyniki.push_back(p);
										}
									}
									else if (kategoria == "pobor")
									{
										if (p._pobor >= wartosc - tolerancja && p._pobor <= wartosc + tolerancja)
										{
											wyniki.push_back(p);
										}
									}
									else if (kategoria == "produkcja")
									{
										if (p._produkcja >= wartosc - tolerancja && p._produkcja <= wartosc + tolerancja)
										{
											wyniki.push_back(p);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << std::fixed << std::setprecision(1);
	return wyniki;
}

void Operacje::WypiszDane(string data_od, string data_do)
{
	std::tm tm_od = {}, tm_do = {};
	std::istringstream ss_od(data_od);
	std::istringstream ss_do(data_do);
	ss_od >> std::get_time(&tm_od, "%d.%m.%Y %H:%M");
	ss_do >> std::get_time(&tm_do, "%d.%m.%Y %H:%M");
	time_t time_od = std::mktime(&tm_od);
	time_t time_do = std::mktime(&tm_do);
	int liczba = 0;
	for (int i = 0; i < 12; i++)
	{
		if (!drzewo->miesiace[i].empty())
		{
			for (int j = 0; j < 31; j++)
			{
				if (!drzewo->miesiace[i][j].empty())
				{
					for (int k = 0; k < 4; k++)
					{
						if (!drzewo->miesiace[i][j][k].empty())
						{
							for (Pomiar p : drzewo->miesiace[i][j][k])
							{
								std::tm tm_czas = {};
								std::istringstream ss_czas(p._czas);
								ss_czas >> std::get_time(&tm_czas, "%d.%m.%Y %H:%M");
								time_t time_czas = std::mktime(&tm_czas);
								if (time_czas >= time_od && time_czas <= time_do)
								{
									cout << "Czas: " << p._czas << endl;
									cout << "Autokonsumpcja: " << p._autokonsumpcja << endl;
									cout << "Eksport: " << p._eksport << endl;
									cout << "Import: " << p._import << endl;
									cout << "Pobor: " << p._pobor << endl;
									cout << "Produkcja: " << p._produkcja << endl;
									cout << "---------------------" << endl;
									liczba++;
								}
							}
						}
					}
				}
			}
		}
	}
}

