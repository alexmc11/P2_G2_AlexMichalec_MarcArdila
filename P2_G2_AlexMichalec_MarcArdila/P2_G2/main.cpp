#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <Windows.h>
#include <cstdlib>
template<>

struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{

		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
		}
};

bool discovered(std::string a, std::vector<std::string>b, int c)
{
	bool d;
	c--;
	for (int i = 0; i < b.size(); i++)
	{
		if (a == b[i])
		{
			return true;
		}

	}
	return false;
}
void help()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "--FULLENTI ALCHEMIST--" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "- Cuando se combinan 2 elementos y estos producen un resultado, se suma 1 a la" << std::endl;
	std::cout << " puntuacion si el nuevo elemento no se encuentra en la lista de elemento. No" << std::endl;
	std::cout << " se pueden combinar 2 elementos que ocupen la misma posicion en la lista." << std::endl << std::endl;
	std::cout << "- escribir 'add' y el numero de un elemento disponible en la lista añade" << std::endl;
	std::cout << "una copia del elemento al que hace referencia dentro de la lista." << std::endl << std::endl;
	std::cout << "- escribir 'add basics' añade nuevas instancias de los 4 elementos basicos." << std::endl << std::endl;
	std::cout << "- escribir 'delete' y el numero de un elemento disponible en la lista," << std::endl;
	std::cout << " elimina el elemento al que hace referencia." << std::endl << std::endl;
	std::cout << "- escribir 'info' y el numero de un elemento disponible en la lista, " << std::endl;
	std::cout << "abre en el navegador la página de Wikipedia con la informacion acerca " << std::endl;
	std::cout << "del elemento." << std::endl << std::endl;
	std::cout << "- escribir 'sort' ordena todos los elementos por orden alfabetico." << std::endl << std::endl;
	std::cout << "- escribir 'clean' elimina todos los elementos que esten repetidos en la lista." << std::endl << std::endl;

}

void main() {

	help();
	std::ifstream fentrada("elements.dat");
	std::unordered_map<std::pair<std::string, std::string>, std::string> mymap;
	std::string line, result, elem1, elem2;
	int pos1, pos2, pos3, end;
	int res1, res2, res3;
	std::string caso;
	int numero;
	std::string a;
	int el2;
	int puntuacion = 0;
	std::vector<std::string> lista{"Air", "Fire", "Earth", "Water"};
	std::vector<std::string> lista2;
	std::string wiki = "https://en.wikipedia.org/wiki/";
	bool check;
	bool discover = false;
	bool firsttime = false;

	while (getline(fentrada, line)) {
		std::pair<std::string, std::string> key;
		//encontrar signos
		pos1 = 0;
		pos2 = line.find("=");
		pos3 = line.find("+");
		end = line.find("\n");
		//operaciones para que cree el substr
		res1 = pos2 - pos1 - 1;
		res2 = (pos3 - 1) - (pos2 + 1);
		res3 = end - (pos3 + 1);
		//leer los elementos y almacenarlos en strings
		result = line.substr(pos1, res1);
		elem1 = line.substr(pos2 + 2, res2-1);
		elem2 = line.substr(pos3 + 2, res3 - 1);
		//meter los datos en el mapa
		key.first = elem1;
		key.second = elem2;
		mymap[key] = result;
	};
	while (puntuacion < 395) {
		check = true;
		for (int i = 0; i < lista.size(); i++)
		{
			std::cout << i + 1 << ". " << lista[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << "  Puntos: " << puntuacion << std::endl;

		std::cin >> caso;
		
		int juego = atoi(caso.c_str());

		if (caso == "add")
		{
			std::cin >> a;
			numero = atoi(a.c_str());
			if (a == "basics")
			{
				lista.push_back("Air");
				lista.push_back("Fire");
				lista.push_back("Earth");
				lista.push_back("Water");
				
			}
			else if (numero <= lista.size() && numero != 0)
			{
				lista.push_back(lista[numero - 1]);
			}
			
		}
	
		else if (caso == "delete")
		{
			std::cin >> numero;

			if (numero < lista.size())
			{
				lista.erase(lista.begin() + (numero - 1));
			}
		}
		else if (caso == "info")
		{
			int aux;
			std::cin >> aux;
			std::string url;

			url.operator+=(wiki);
			url.operator+=(lista[aux - 1]);

			ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
		}
		else if (caso == "sort")
		{
			std::sort(lista.begin(), lista.end());
		}
		else if (caso == "clean")
		{
			std::set<std::string>limpio;

			for (int i = 0; i < lista.size() - 1; i++) {

				limpio.insert(lista[i]);
			}
			lista.clear();

			for (auto j = limpio.begin(); j != limpio.end(); j++) {

				lista.push_back(*j);
			}
		}
	

		//El caso, si la X es = 0, entre,
		else if (juego != 0)
		{
			
			std::cin >> el2;
			while (juego == el2)
			{
				std::cin >> el2;
			}
				
				std::pair<std::string, std::string> key;
				key.first = lista[juego - 1];
				key.second = lista[el2 - 1];
				
				auto it = mymap[key];

				if (mymap.size() > 390)
				{
					auto erase = mymap.find(key);
					mymap.erase(erase);
					key.first = lista[el2 - 1];
					key.second = lista[juego - 1];
					auto it = mymap[key];

					if (mymap.size() > 390)
					{
						auto erase = mymap.find(key);
						mymap.erase(erase);
						check = false;
					}
				}
				if (check == true)
				{
					if (firsttime == true)
					{
						int end = lista2.size();
						discover = discovered(mymap[key], lista2, end);
						
					}
					lista.push_back(mymap[key]);
					lista.erase(lista.begin() + juego - 1);
					lista.erase(lista.begin() + el2 - 2);
					
					if (discover == false)
					{
						puntuacion++;
						lista2.push_back(mymap[key]);
					}
					firsttime = true;
					discover = false;
					
				}
					
		}
		system("cls");
		if (caso == "help")
		{
			help();
		}
	}
}