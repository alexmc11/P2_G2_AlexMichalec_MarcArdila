#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
template<>

struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{

		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
		}
};

void help()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "--FULLENTI ALCHEMIST--" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "- Cuando se combinan 2 elementos y estos producen un resultado, se suma 1 a la" << std::endl;
	std::cout << " puntuación si el nuevo elemento no se encuentra en la lista de elemento. No" << std::endl;
	std::cout << " se pueden combinar 2 elementos que ocupen la misma posición en la lista." << std::endl << std::endl;
	std::cout << "- escribir 'add' y el número de un elemento disponible en la lista añade" << std::endl;
	std::cout << "una copia del elemento al que hace referencia dentro de la lista." << std::endl << std::endl;
	std::cout << "- escribir 'add basics' añade nuevas instancias de los 4 elementos básicos." << std::endl << std::endl;
	std::cout << "- escribir 'delete' y el número de un elemento disponible en la lista," << std::endl;
	std::cout << " elimina el elemento al que hace referencia." << std::endl << std::endl;
	std::cout << "- escribir 'info' y el número de un elemento disponible en la lista, " << std::endl;
	std::cout << "abre en el navegador la página de Wikipedia con la información acerca " << std::endl;
	std::cout << "del elemento." << std::endl << std::endl;
	std::cout << "- escribir 'sort' ordena todos los elementos por orden alfabético." << std::endl << std::endl;
	std::cout << "- escribir 'clean' elimina todos los elementos que estén repetidos en la lista." << std::endl << std::endl;

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
	std::vector<std::string> lista{"air", "fire", "earth", "water"};

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
		elem1 = line.substr(pos2 + 2, res2);
		elem2 = line.substr(pos3 + 2, res3);
		//meter los datos en el mapa
		key.first = elem1;
		key.second = elem2;
		mymap[key] = result;
	};

	std::cin >> caso;

	if (caso == "add")
	{
		std::cin >> numero;

		if (numero < lista.size()) 
		{
			lista.push_back(lista[numero-1]);
		}
	}
	else if (caso == "add basics")
	{
		lista.push_back("air");
		lista.push_back("fire");
		lista.push_back("earth");
		lista.push_back("water");
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
	else if (caso == "help")
	{
		system("cls");
		help();
	}
}